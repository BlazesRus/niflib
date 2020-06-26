// ***********************************************************************
// Code Created initially by James Michael Armstrong (https://github.com/BlazesRus)
// Not exclusive for use in Niflib(will add to GlobalCode project later)
// ***********************************************************************
#pragma once

#include <map>
#include <vector>
#include <string>
#include "C:\UserFiles\GitHub\MultiPlatformGlobalCode\GlobalCode\VariableConversionFunctions\VariableConversionFunctions.h"

#include "dll_export.h"
#define NIFLIB_API
#define NIFLIB_HIDDEN

/// <summary>
/// Class ExprFormula. (FormulaElement)Operator(FormulaElement)
/// FormulaElements stored as std::vector<std::string>
/// Expression Example: ((Variable01 >= 1)&&(Variable02>2.5))
/// with (Variable01 >= 1) FormulaElement values:
/// Variable01, >=, #i0
/// with (Variable01 >= 1) values referenced from:
/// Variable01, >=, IntValues[0]
/// with (Variable02>2.5) FormulaElement values:
/// Variable02, >, #i0
/// with (Variable02>2.5) values referenced from:
/// Variable02, >, FloatValues[0]
/// Initial FormulaElement Values : @1, &&, @2
/// </summary>
NIFLIB_API class ExprFormula: public std::vector<std::vector<std::string>>
{
private:
    /// <summary>
    /// Prevents a default instance of the <see cref="ExprFormula"/> class from being created.
    /// </summary>
    ExprFormula() {}
    using StringVector = std::vector<std::string>;
public:
    /// <summary>
    /// The stored int values
    /// </summary>
    std::vector<int> IntValues;

    /// <summary>
    /// The stored float values
    /// </summary>
    std::vector<float> FloatValues;

    /// <summary>
    /// The stored boolean values
    /// </summary>
    std::vector<bool> BoolValues;

    void TrimFormula()
    {
        if(this->size() == 2&&this[0].size()==1&& this[0][0].front()=="@")
        {
            this[0] = this[1]; this->pop_back();//Reduce formula in (@1) to just @1
        }
    }

    bool EvalAsBool(std::map<std::string, bool> ElementValues)
    {
        bool Value = false;
        for (std::vector<std::string>::iterator CurrentVal = at(0).begin(), LastVal = at(0).end(); CurrentVal != LastVal; ++CurrentVal)
        {

        }
        return Value;
    }
    
    //RecursivelyEvaluateFloatingVals
    bool EvalAsBool(std::map<std::string, float> ElementValues)
    {
        float Value = 0.0f;
        for (std::vector<std::string>::iterator CurrentVal = at(0).begin(), LastVal = at(0).end(); CurrentVal != LastVal; ++CurrentVal)
        {
        }
        return (Value==0.0f)?false:true;
    }

    bool EvalAsBool(std::map<std::string, int> ElementValues)
    {
        int Value = 0.0;
        for (std::vector<std::string>::iterator CurrentVal = at(0).begin(), LastVal = at(0).end(); CurrentVal != LastVal; ++CurrentVal)
        {
        }
        return (Value==0.0f)?false:true;
    }
    
    std::string ToString()
    {
        std::string strBuffer="";
        return strBuffer;//Placeholder Code
    }

    void InsertFromBuffer(std::string& strBuffer, size_t& FormulaIndex, short& ScanType)
    {
        if (strBuffer=="true")
        {
            size_t valIndex = BoolValues.size();
            BoolValues.push_back(true);
            this->at(FormulaIndex).push_back("#b" + valIndex);
        }
        else if (strBuffer == "false")
        {
            size_t valIndex = BoolValues.size();
            BoolValues.push_back(false);
            this->at(FormulaIndex).push_back("#b" + valIndex);
        }
        else if (ScanType == 3)
        {
            this->at(FormulaIndex).push_back(strBuffer);
        }
        else if (ScanType == 5)
        {
            size_t valIndex = FloatValues.size();
            FloatValues.push_back(VariableConversionFunctions::ReadFloatFromString(strBuffer));
            this->at(FormulaIndex).push_back("#f"+ valIndex);
        }
        else if (ScanType == 6||ScanType==4)
        {
            size_t valIndex = IntValues.size();
            IntValues.push_back(VariableConversionFunctions::ReadIntFromString(strBuffer));
            this->at(FormulaIndex).push_back("#i" + valIndex);
        }
   //     else if (ScanType == 7)
   //     {
   //         size_t valIndex = BoolValues.size();
   //         BoolValues.push_back(VariableConversionFunctions::ReadBoolFromString(strBuffer));
   //         this->at(FormulaIndex).push_back("#b" + valIndex);
   //     }
    }

    /// <summary>
    /// Initializes a new instance of the <see cref="ExprFormula" /> class.
    /// </summary>
    /// <param name="ElemValue">The elem value to read in order to create formula data.</param>
    ExprFormula(std::string ElemValue)
    {
        //0 = ???
        //1 = Operator
        //3 = Variable Value
        //4 = Number
        //5 = Float Number
        //6 = Int Number
        //7 = Bool Number
        short ScanType = 0;
        std::string strBuffer = "";
        size_t FormulaIndex = 0;
        //size_t CurrentFormElement = 0;
        this->push_back(StringVector());//Initialize first (Formula) field
        for (std::string::iterator CurrentVal = ElemValue.begin(), LastVal = ElemValue.end(); CurrentVal != LastVal; ++CurrentVal)
        {
            if(*CurrentVal=='(')
            {
                if (!strBuffer.empty()) { InsertFromBuffer(strBuffer, FormulaIndex, ScanType); }
                FormulaIndex = this->size();
                this->push_back(StringVector());
            }
            else if(*CurrentVal==')')
            {
                InsertFromBuffer(strBuffer, FormulaIndex, ScanType);
                strBuffer = ""; ScanType = 0;
                --FormulaIndex;
            }
            else if(ScanType==0)//Almost only at either start of a formula or after operator 
            {
                //operators = ['==', '!=', '>=', '<=', '&&', '||', '&', '|', '-', '+', '>', '<', '/', '*', '!','++','--']
                if(*CurrentVal=='+')//++
                {
                    strBuffer = '+'; ScanType = 1;
                }
                else if(*CurrentVal=='-')//--
                {
                    strBuffer = '-'; ScanType = 1;//Either Number or operator
                }
                else if(*CurrentVal=='!')//Negative Operator only valid for in front of NonOperators
                {
                    this->at(FormulaIndex).push_back("!");
                }
                else
                {
                    
                }
            }
            else if(ScanType==1)
            {
                if(strBuffer=="-")
                {
                    
                    if(VariableConversionFunctions::IsDigit(*CurrentVal))
                    {
                        ScanType == 4; strBuffer += *CurrentVal;
                    }
                    else if(*CurrentVal=='-')//-- Operator
                    {

                    }
                    else//- Operator
                    {
                        strBuffer.clear();
                    }
                }
                else if (strBuffer == "+")
                {
                    strBuffer += *CurrentVal;
                    if (*CurrentVal == '+')//++ Operator
                    {

                    }
                    else//+ Operator
                    {

                    }
                }
            }
            else
            {
                if (*CurrentVal == '+')//++ or +
                {
                    InsertFromBuffer(strBuffer, FormulaIndex, ScanType);
                    strBuffer = '+'; ScanType = 1;
                }
                else if (*CurrentVal == '-')//-- or -
                {
                    InsertFromBuffer(strBuffer, FormulaIndex, ScanType);
                    strBuffer = '-'; ScanType = 1;
                }
                else if(*CurrentVal=='!')//!=
                {
                    InsertFromBuffer(strBuffer, FormulaIndex, ScanType);
                    strBuffer = '!'; ScanType = 1;
                }
                else if(*CurrentVal=='&')
                {
                    InsertFromBuffer(strBuffer, FormulaIndex, ScanType);
                    strBuffer = '&'; ScanType = 1;
                }
                else if(*CurrentVal=='|')
                {
                    InsertFromBuffer(strBuffer, FormulaIndex, ScanType);
                    strBuffer = '|'; ScanType = 1;
                }
                else if(*CurrentVal=='=')
                {
                    InsertFromBuffer(strBuffer, FormulaIndex, ScanType);
                    strBuffer = '='; ScanType = 1;
                }
                else if(*CurrentVal=='>')
                {
                    InsertFromBuffer(strBuffer, FormulaIndex, ScanType);
                    strBuffer = '>'; ScanType = 1;
                }
                else if(*CurrentVal=='<')
                {
                    InsertFromBuffer(strBuffer, FormulaIndex, ScanType);
                    strBuffer = '>'; ScanType = 1;
                }
                else if(*CurrentVal=='/')
                {
                    InsertFromBuffer(strBuffer, FormulaIndex, ScanType);
                    strBuffer = '/'; ScanType = 1;
                }
                else if(*CurrentVal=='*')
                {
                    InsertFromBuffer(strBuffer, FormulaIndex, ScanType);
                    strBuffer = '*'; ScanType = 1;
                }
                else
                {
                    strBuffer += *CurrentVal;
                }
            }
        }
        TrimFormula();
    }
};