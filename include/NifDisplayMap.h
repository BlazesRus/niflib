// ***********************************************************************
// Code Created initially by James Michael Armstrong for use in Niflib dll/static library(https://github.com/BlazesRus) for use in displaying NifNodes inside a NodeTree-like structure
// Most of file loading code is variation of ReadNifTree code from niflib.h
// ***********************************************************************
#pragma once

#define _AFXDLL
//#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <map>
#include <string>
#include <NIF_IO.h>
//#include "niflib.h"
#include "gen/Header.h"
#include "gen/enums.h"
#include "nif_versions.h"
#include "gen/Footer.h"

#include "dll_export.h"

NIFLIB_API class NifDisplayMapNode// : NifMapNode
{
/*
    /// <summary>
    /// Index position of ParentNode (EmptyNode=inside Root Level by default)
    /// </summary>
    int ParentIndex;

    /// <summary>
    /// The indexes of all child nodes
    /// </summary>
    UIntVector ChildNodes;



*/

    //NIFLIB_API Niflib::Ref<Niflib::NiNode> CreateNodeCopy()
    //{
    //    return new Niflib::NiNode;
    //}
	
    /// <summary>
    /// Node Coordinate Data(Current Position of Node in Tree)
    /// </summary>
    CRect		CoordData;

    NifDisplayMapNode()
    {

    }
};

NIFLIB_API class NifDisplayMap : public std::map<int, NifDisplayMapNode>
{
private:
    const int EmptyNode = -1;
public:
    int RootIndex;

    /// <summary>
    /// Reads the file data. (Calls a modified version of Niflib::ReadNifTree(string const& file_name, NifInfo * info = NULL)) 
    /// </summary>
    /// <param name="FileName">Name of the file.</param>
    void ReadFileData(std::string const& file_name, Niflib::NifInfo* info = NULL)
    {
    ////Read object list
    //vector<NiObjectRef> objects = ReadNifList(file_name, info);
        //--Open File--//
        std::ifstream in(file_name.c_str(), std::ifstream::binary);

        std::list<Niflib::NiObjectRef> missing_link_stack;
    //start of ReadNifList(in, missing_link_stack, info); part of code
        /*  --Turning off registering of objects for NifNodeTree since aiming to rely on less pointers
        //Ensure that objects are registered
        if (g_objects_registered == false) {
            g_objects_registered = true;
            RegisterObjects();
        }
        */

        //--Read Header--//
        Niflib::Header header;
        Niflib::hdrInfo hinfo(&header);

        // set the header pointer in the stream
        in >> hinfo;

        //Create a new NifInfo if one isn't given.
        bool delete_info = false;
        if (info == NULL) {
            info = new Niflib::NifInfo();
            delete_info = true;
        }

        //Read header.
        *info = header.Read(in);

        //If NifInfo structure is provided, fill it with info from header
        info->version = header.version;
        info->userVersion = header.userVersion;
        info->userVersion2 = header.userVersion2;
        info->endian = Niflib::EndianType(header.endianType);
        info->author = header.exportInfo.author;
        info->exportScript = header.exportInfo.exportScript;
        info->processScript = header.exportInfo.processScript;

#ifdef DEBUG_HEADER_FOOTER
        //Print debug output for header
        cout << header.asString();
#endif

#ifdef PRINT_OBJECT_NAMES
        cout << endl << "Reading Objects:";
#endif

        //--Read Objects--//
        size_t numObjects = header.numBlocks;
        map<unsigned, Niflib::NiObjectRef> objects; //Map to hold objects by number
        vector<Niflib::NiObjectRef> obj_list; //Vector to hold links in the order they were created.
        list<unsigned int> link_stack; //List to add link values to as they're read in from the file
        string objectType;
        stringstream errStream;

        std::streampos headerpos = in.tellg();
        std::streampos nextobjpos = headerpos;

        //Loop through all objects in the file
        unsigned int i = 0;
        //Aiming to store new_obj inside alternative object that relies less on pointers (also going to need alternative "fix links code" or possibly none at all since non-existent pointers won't break)
        Niflib::NiObjectRef new_obj;
        while (true) {

            // Check if the size information matches in version 20.3 and greater
            if (header.version >= Niflib::VER_20_3_0_3) {
                if (nextobjpos != in.tellg()) {
                    // incorrect positioning seek to expected location
                    in.seekg(nextobjpos);
                }
                // update next location
                nextobjpos += header.blockSize[i];
            }


            //Check for EOF
            if (in.eof()) {
                errStream << "End of file reached prematurely.  This NIF may be corrupt or improperly supported." << endl;
                if (new_obj != NULL) {
                    errStream << "Last successfully read object was:  " << endl;
                    errStream << "====[ " << "Object " << i - 1 << " | " << new_obj->GetType().GetTypeName() << " ]====" << endl;
                    errStream << new_obj->asString();
                }
                else {
                    errStream << "No objects were read successfully." << endl;
                }
                throw runtime_error(errStream.str());
            }

            // Starting position of block in stream
            std::streampos startobjpos = in.tellg();

            //There are two main ways to read objects
            //One before version 5.0.0.1 and one after
            if (header.version >= 0x05000001) {
                //From version 5.0.0.1 to version 10.0.1.106  there is a zero byte at the begining of each object

                if (header.version <= Niflib::VER_10_1_0_106) {
                    unsigned int checkValue = Niflib::ReadUInt(in);
                    if (checkValue != 0) {
                        //Throw an exception if it's not zero
                        errStream << "Read failure - Bad object position.  Invalid check value:  " << checkValue << endl;
                        if (new_obj != NULL) {
                            errStream << "Last successfully read object was:  " << endl;
                            errStream << "====[ " << "Object " << i - 1 << " | " << new_obj->GetType().GetTypeName() << " ]====" << endl;
                            errStream << new_obj->asString();
                        }
                        else {
                            errStream << "No objects were read successfully." << endl;
                        }
                        throw runtime_error(errStream.str());
                    }
                }

                // Find which NIF object type this is by using the header arrays
                objectType = header.blockTypes[header.blockTypeIndex[i]];

#ifdef PRINT_OBJECT_NAMES
                cout << endl << i << ":  " << objectType;
#endif
            }
            else {
                // Find which object type this is by reading the string at this location
                unsigned int objectTypeLength = Niflib::ReadUInt(in);
                if (objectTypeLength > 30 || objectTypeLength < 6) {
                    errStream << "Read failure - Bad object position.  Invalid Type Name Length:  " << objectTypeLength << endl;
                    if (new_obj != NULL) {
                        errStream << "Last successfully read object was:  " << endl;
                        errStream << "====[ " << "Object " << i - 1 << " | " << new_obj->GetType().GetTypeName() << " ]====" << endl;
                        errStream << new_obj->asString();
                    }
                    else {
                        errStream << "No objects were read successfully." << endl;
                    }
                    throw runtime_error(errStream.str());
                }
                char* charobjectType = new char[objectTypeLength + 1];
                in.read(charobjectType, objectTypeLength);
                charobjectType[objectTypeLength] = 0;
                objectType = string(charobjectType);
                delete[] charobjectType;

#ifdef PRINT_OBJECT_NAMES
                cout << endl << i << ":  " << objectType;
#endif

                if (header.version < Niflib::VER_3_3_0_13) {
                    //There can be special commands instead of object names
                    //in these versions

                    if (objectType == "Top Level Object") {
                        //Just continue on to the next object
                        continue;
                    }

                    if (objectType == "End Of File") {
                        //File is finished
                        break;
                    }
                }
            }

            //Going to use alternative code here to avoid create objects to an object registry that relies a lot on pointers
            ////Create object of the type that was found
            //new_obj = ObjectRegistry::CreateObject(objectType);
            //To-Do Alternative new_obj creation code

            //Check for an unknown object type
            if (new_obj == NULL) {
                errStream << "Unknown object type encountered during file read:  " << objectType << endl;
                if (new_obj != NULL) {
                    errStream << "Last successfully read object was:  " << endl;
                    errStream << "====[ " << "Object " << i - 1 << " | " << new_obj->GetType().GetTypeName() << " ]====" << endl;
                    errStream << new_obj->asString();
                }
                else {
                    errStream << "No objects were read successfully." << endl;
                }
                throw runtime_error(errStream.str());
            }

            unsigned int index;
            if (header.version < Niflib::VER_3_3_0_13) {
                //These old versions have a pointer value after the name
                //which is used as the index
                index = Niflib::ReadUInt(in);
            }
            else {
                //These newer versions use their position in the file as their index
                index = i;
            }

            //Read new object
            new_obj->Read(in, link_stack, *info);

            //Add object to map
            objects[index] = new_obj;

            //Add object to list
            obj_list.push_back(new_obj);

            //Store block number
            new_obj->internal_block_number = index;

            // Ending position of block in stream
            std::streampos endobjpos = in.tellg();

            // Check if the size information matches
            if (header.version >= Niflib::VER_20_3_0_3) {
                std::streamsize calcobjsize = endobjpos - startobjpos;
                unsigned int objsize = header.blockSize[i];
                if (calcobjsize != objsize) {
                    errStream << "Object size mismatch occurred during file read:" << endl;
                    errStream << "====[ " << "Object " << i << " | " << objectType << " ]====" << endl;
                    errStream << "  Start: " << startobjpos << "  Expected Size: " << objsize << "  Read Size: " << calcobjsize << endl;
                    errStream << endl;
                }
            }

#ifdef PRINT_OBJECT_CONTENTS
            cout << endl << new_obj->asString() << endl;
#endif

            if (header.version >= Niflib::VER_3_3_0_13) {
                //We know the number of objects, so increment the count
                //and break if we've finished
                ++i;
                if (i >= numObjects) {
                    break;
                }
            }
        }

        //--Read Footer--//
        Niflib::Footer footer;
        footer.Read(in, link_stack, *info);

#ifdef DEBUG_HEADER_FOOTER
        //Print footer debug output
        footer.asString();
#endif

        // Check for accumulated warnings
        if (errStream.tellp() > 0) {
            throw runtime_error(errStream.str());
        }

#ifdef DEBUG_LINK_PHASE
        cout << "Link Stack:" << endl;
        list<unsigned int>::iterator it;
        for (it = link_stack.begin(); it != link_stack.end(); ++it) {
            cout << *it << endl;
        }

        cout << "Fixing Links:" << endl;
#endif
        //--Now that all objects are read, go back and fix the links--//


        for (unsigned int i = 0; i < obj_list.size(); ++i) {
#ifdef DEBUG_LINK_PHASE
            cout << "   " << i << ":  " << obj_list[i] << endl;
#endif
            //Fix links & other pre-processing
            obj_list[i]->FixLinks(objects, link_stack, missing_link_stack, *info);
        }

        //delete info if it was dynamically allocated
        if (delete_info) {
            delete info;
        }

        // clear the header pointer in the stream.  Should be in try/catch block
        Niflib::hdrInfo hinfo2(NULL);
        in >> hinfo2;

        //Return completed object list
    //end of ReadNifList(in, missing_link_stack, info); part of code

        in.close();
    }
    NifDisplayMap(std::string const& FileName)
    {
        ReadFileData(FileName);
    }
    NifDisplayMap()
    {}
    ~NifDisplayMap()
    {}
};