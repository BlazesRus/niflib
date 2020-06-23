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
    NIFLIB_API class FormulaElement : std::vector<std::string>
    {
    };
    std::vector<FormulaElement> ExprLayout;
    std::vector<std::string> ValueNames;
    /// <summary>
    /// Initializes a new instance of the <see cref="ExprFormula"/> class.
    /// </summary>
    /// <param name="ElemValue">The elem value to read in order to create formula data.</param>
    ExprFormula(std::string ElemValue)
    {

    }
};