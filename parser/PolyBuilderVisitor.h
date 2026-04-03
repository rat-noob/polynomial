#pragma once

#include <antlr4-runtime.h>   
#include "../generated/PolynomialBaseVisitor.h"
#include "../include/Polynomial.h"
#include <map>
#include <string>
#include <any>

Polynomial anyToPolynomial(const std::any& value);

class PolyBuilderVisitor : public PolynomialBaseVisitor {
private:
    std::map<std::string, Polynomial> variables;

public:
    virtual std::any visitProg(PolynomialParser::ProgContext* ctx) override;
    virtual std::any visitAssign(PolynomialParser::AssignContext* ctx) override;
    virtual std::any visitPrintExpr(PolynomialParser::PrintExprContext* ctx) override;
    virtual std::any visitPoly(PolynomialParser::PolyContext* ctx) override;
    virtual std::any visitTerm(PolynomialParser::TermContext* ctx) override;

    Polynomial getVariable(const std::string& name) const;
};