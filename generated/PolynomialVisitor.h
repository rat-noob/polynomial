
// Generated from D:/UNN/c++/polynomial/polynomial/grammar/Polynomial.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "PolynomialParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by PolynomialParser.
 */
class  PolynomialVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by PolynomialParser.
   */
    virtual std::any visitProg(PolynomialParser::ProgContext *context) = 0;

    virtual std::any visitAssign(PolynomialParser::AssignContext *context) = 0;

    virtual std::any visitPrintExpr(PolynomialParser::PrintExprContext *context) = 0;

    virtual std::any visitExit(PolynomialParser::ExitContext *context) = 0;

    virtual std::any visitPoly(PolynomialParser::PolyContext *context) = 0;

    virtual std::any visitTerm(PolynomialParser::TermContext *context) = 0;

    virtual std::any visitSign(PolynomialParser::SignContext *context) = 0;

    virtual std::any visitCoefficient(PolynomialParser::CoefficientContext *context) = 0;

    virtual std::any visitVariables(PolynomialParser::VariablesContext *context) = 0;

    virtual std::any visitVar(PolynomialParser::VarContext *context) = 0;


};

