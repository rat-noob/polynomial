
// Generated from grammar/Polynomial.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "PolynomialVisitor.h"


/**
 * This class provides an empty implementation of PolynomialVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  PolynomialBaseVisitor : public PolynomialVisitor {
public:

  virtual std::any visitProg(PolynomialParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssign(PolynomialParser::AssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrintExpr(PolynomialParser::PrintExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExit(PolynomialParser::ExitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPoly(PolynomialParser::PolyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTerm(PolynomialParser::TermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSign(PolynomialParser::SignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCoefficient(PolynomialParser::CoefficientContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariables(PolynomialParser::VariablesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVar(PolynomialParser::VarContext *ctx) override {
    return visitChildren(ctx);
  }


};

