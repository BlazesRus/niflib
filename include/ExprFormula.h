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
/// FormulaKeys References
/// </summary>
NIFLIB_API class ExprFormula// : std::map<std::string, Storage>
{
private:
    /// <summary>
    /// Prevents a default instance of the <see cref="ExprFormula"/> class from being created.
    /// </summary>
    ExprFormula() {}
public:
    /// <summary>
    /// Class FormulaElement. 
    /// Implements the <see cref="std::vector{std::string}" />
    /// </summary>
    /// <seealso cref="std::vector{std::string}" />
    NIFLIB_API class FormulaElement : std::vector<std::string>
    {//@; #i, and #f starting elements reserved, and of course all operator values
       
        // Expression Example: ((Variable01 >= 1)&&(Variable02>2.5))
        // with (Variable01 >= 1) FormulaElement values:
        // Variable01, >=, #i0
        // with (Variable01 >= 1) values referenced from:
        // Variable01, >=, IntValues[0]
        // with (Variable02>2.5) FormulaElement values:
        // Variable02, >, #i0
        // with (Variable02>2.5) values referenced from:
        // Variable02, >, FloatValues[0]
        // Initial FormulaElement Values : @1, &&, @2

    };
    std::vector<FormulaElement> ExprLayout;

    //Don't need to refer to element for variable names
    //std::vector<std::string> ValueNames;

    //Might add optional vector reference to other values stored elsewhere for evaluating values

    /// <summary>
    /// The stored int values
    /// </summary>
    std::vector<int> IntValues;
    /// <summary>
    /// The stored float values
    /// </summary>
    std::vector<int> FloatValues;

    bool EvalAsBool()
    {
        return true;//Placeholder code
    }

    /// <summary>
    /// Initializes a new instance of the <see cref="ExprFormula"/> class.
    /// </summary>
    /// <param name="ElemValue">The elem value to read in order to create formula data.</param>
    ExprFormula(std::string ElemValue)
    {
        //0 = ???
        //1 = Number
        //2 = Operator
        //3 = Value
        short ScanType = 0;
        size_t CurrentFormElement = 0;
        ExprLayout.push_back(FormulaElement());
    }
};