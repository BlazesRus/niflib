// ***********************************************************************
// Code Created initially by James Michael Armstrong (https://github.com/BlazesRus)
// Not exclusive for use in Niflib(will add to GlobalCode project later)
// ***********************************************************************
#pragma once

#include <map>
#include <vector>
#include <string>


#include "dll_export.h"

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
    std::vector<int> FloatValues;

    void TrimFormula()
    {
        if(this[0].size()==2&& this[0][0].front()=="@")
        {
            this[0] = this[1]; this->pop_back();//Reduce formula in (@1) to just @1
        }
    }

    bool EvalAsBool(std::map<std::string, bool> ElementValues)
    {
		bool Value = false;
        for (std::vector<std::string>::iterator CurrentVal = this[0].begin(), LastVal = this[0].begin(); CurrentVal != LastVal; ++CurrentVal)
        {
		}
        return Value;
    }
	
	//RecursivelyEvaluateFloatingVals
    bool EvalAsBool(std::map<std::string, float> ElementValues)
    {
		float Value = 0.0f;
        for (std::vector<std::string>::iterator CurrentVal = this[0].begin(), LastVal = this[0].begin(); CurrentVal != LastVal; ++CurrentVal)
        {
		}
        return (Value==0.0f)?false:true;
    }

    bool EvalAsBool(std::map<std::string, int> ElementValues)
    {
		int Value = 0.0;
        for (std::vector<std::string>::iterator CurrentVal = this[0].begin(), LastVal = this[0].begin(); CurrentVal != LastVal; ++CurrentVal)
        {
		}
        return (Value==0.0f)?false:true;
    }
	
	std::string ToString()
	{
		std::string strBuffer="";
		return strBuffer;//Placeholder Code
	}

    /// <summary>
    /// Initializes a new instance of the <see cref="ExprFormula"/> class.
    /// </summary>
    /// <param name="ElemValue">The elem value to read in order to create formula data.</param>
    ExprFormula(std::string ElemValue)
    {
        //0 = ???
        //1 = Operator
		//2 = Formula
        //3 = Variable Value
		//4 = Number
		//5 = Float Number
		//6 = Int Number
		//7 = Bool Number
        short ScanType = 0;
		std::string strBuffer = "";
		size_t FormulaIndex = 0;
        size_t CurrentFormElement = 0;
        this->push_back(StringVector());//Initialize first (Formula) field
        for (std::string::iterator CurrentVal = ElemValue.begin(), LastVal = ElemValue.end(); CurrentVal != LastVal; ++CurrentVal)
        {
			if(*CurrentVal=='(')
			{
				FormulaIndex = this->size();
				this->push_back(StringVector());
			}
			else if(*CurrentVal==')')
			{
				if(ScanType==3)
				{
				
				}
				else if(ScanType==5)
				{
				
				}
				else if(ScanType==6)
				{
				
				}
				else if(ScanType==7)
				{
				
				}
				strBuffer = "";
				--FormulaIndex;
			}
			else if(ScanType==0)//Almost only at either start of a formula or after operator 
			{
				if(*CurrentVal=='#')
				{
					ScanType = 4;
				}
				else if(*CurrentVal=='@')
				{
					ScanType = 2;
				}
				//operators = ['==', '!=', '>=', '<=', '&&', '||', '&', '|', '-', '+', '>', '<', '/', '*', '!','++','--']
				else if(*CurrentVal=='+')//++
				{
					strBuffer = '+'; ScanType = 1;
				}
				else if(*CurrentVal=='-')//--
				{
					strBuffer = '-'; ScanType = 1;
				}
/*				else if(*CurrentVal=='!')//Negative Operator only valid for in front of NonOperators
				{
					strBuffer = '!'; //ScanType = 1;
				}
*/
				//else if(*CurrentVal=='&')
				//{
				//	strBuffer = '&'; ScanType = 1;
				//}
				//else if(*CurrentVal=='|')
				//{
				//	strBuffer = '|'; ScanType = 1;
				//}
				//else if(*CurrentVal=='=')
				//{
				//	strBuffer = '+'; ScanType = 1;
				//}
				//else if(*CurrentVal=='>')
				//{
				//	strBuffer = '>'; ScanType = 1;
				//}
				//else if(*CurrentVal=='<')
				//{
				//	strBuffer = '>'; ScanType = 1;
				//}
				//else if(*CurrentVal=='/')
				//{
				//	strBuffer = '/'; ScanType = 1;
				//}
				//else if(*CurrentVal=='*')
				//{
				//	strBuffer = '*'; ScanType = 1;
				//}
				else
				{
				
				}
			}
			else if(ScanType==4)
			{
				if(*CurrentVal=='f')
				{
					ScanType = 5;
				}
				else if(*CurrentVal=='f')
				{
					ScanType = 5;
				}
			}
			else if(ScanType==2)
			{
			
			}
			else if(ScanType==1)
			{
			
			}
			else
			{
			
			}
		}
        TrimFormula();
    }
};