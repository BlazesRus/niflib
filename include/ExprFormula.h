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
protected://All Derivatives can use
    using StringVector = std::vector<std::string>;
    /// <summary>
    /// Returns the rest of string.
    /// </summary>
    /// <param name="targetStr">The target string.</param>
    /// <param name="index">The index.</param>
    /// <returns>std.string.</returns>
    std::string ReturnRestOfString(std::string& targetStr, size_t index)
	{
		std::string strBuffer="";
		for (std::string::iterator CurrentVal = targetStr.begin()+index, LastVal = targetStr.end(); CurrentVal != LastVal; ++CurrentVal)
		{
			strBuffer += *CurrentVal;
		}
		return strBuffer;
	}
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

    /// <summary>
    /// Trims the formula.
    /// </summary>
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
	
    /// <summary>
    /// Recursively adds to the string.
    /// </summary>
    /// <param name="strBuffer">The string buffer.</param>
    /// <param name="FormIndex">Index of the form.</param>
    void RecursivelyAddToString(std::string& strBuffer, size_t FormIndex)
	{
		size_t NextFormIndex;
        std::string CurString;
		for (std::vector<std::string>::iterator CurrentVal = at(FormIndex).begin(), LastVal = at(FormIndex).end(); CurrentVal != LastVal; ++CurrentVal)
		{
            CurString = *CurrentVal;
			if(CurString.front()=='@')//FormulaDetected
			{
				strBuffer += "(";
				NextFormIndex = VariableConversionFunctions::ReadIntFromString(ReturnRestOfString(CurString,1));
				RecursivelyAddToString(strBuffer, NextFormIndex);
				strBuffer += ")";
			}
			else if(CurString.front()=='#')//NumberDetected
			{
				FormIndex = VariableConversionFunctions::ReadIntFromString(ReturnRestOfString(CurString,2));
				if(CurString[1]=='f')
				{
					strBuffer += FloatValues.at(FormIndex);
				}
				else if(CurString[1]=='i')
				{
					strBuffer += IntValues.at(FormIndex);
				}
				else//Boolean with second value assumed to be b(until I add support for 4th type of value etc)
				{
					strBuffer += BoolValues.at(FormIndex);
				}
			}
			else
			{
				strBuffer += CurString;
			}
		}
	}
	
    /// <summary>
    /// Converts to string(with no extra spacing applied).
    /// </summary>
    /// <returns>std.string.</returns>
    std::string ToString()
    {
        std::string strBuffer="";
		size_t FormIndex;
        std::string CurString;
        for (std::vector<std::string>::iterator CurrentVal = at(0).begin(), LastVal = at(0).end(); CurrentVal != LastVal; ++CurrentVal)
        {
            CurString = *CurrentVal;
            if (CurString.front() == '@')//FormulaDetected
            {
                strBuffer += "(";
                FormIndex = VariableConversionFunctions::ReadIntFromString(ReturnRestOfString(CurString, 1));
                RecursivelyAddToString(strBuffer, FormIndex);
                strBuffer += ")";
            }
            else if (CurString.front() == '#')//NumberDetected
            {
                FormIndex = VariableConversionFunctions::ReadIntFromString(ReturnRestOfString(CurString, 2));
                if (CurString[1] == 'f')
                {
                    strBuffer += FloatValues.at(FormIndex);
                }
                else if (CurString[1] == 'i')
                {
                    strBuffer += IntValues.at(FormIndex);
                }
                else//Boolean with second value assumed to be b(until I add support for 4th type of value etc)
                {
                    strBuffer += BoolValues.at(FormIndex);
                }
            }
            else
            {
                strBuffer += CurString;
            }
        }
        return strBuffer;
    }

    /// <summary>
    /// Inserts from buffer.
    /// </summary>
    /// <param name="strBuffer">The string buffer.</param>
    /// <param name="FormulaIndex">Index of the formula.</param>
    /// <param name="ScanType">Type of the scan.</param>
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
    /// Resets to single blank formula
    /// </summary>
    void ResetToBlank()
	{
		this->clear();
		this->push_back(StringVector());//Initialize first (Formula) field
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