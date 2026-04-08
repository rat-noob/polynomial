#include "PolyBuilderVisitor.h"
#include <iostream>
#include <cmath>
#include <any>
#include <stdexcept>


Polynomial anyToPolynomial(const std::any& value) {
 
        return std::any_cast<Polynomial>(value);
    
    
}

std::any PolyBuilderVisitor::visitProg(PolynomialParser::ProgContext* ctx) {
    Polynomial result;
    for (auto stat : ctx->stat()) {
        auto anyResult = visit(stat);
        result = anyToPolynomial(anyResult);
    }
    return std::make_any<Polynomial>(result);
}

std::any PolyBuilderVisitor::visitAssign(PolynomialParser::AssignContext* ctx) {
    std::string id = ctx->ID()->getText();
    auto anyValue = visit(ctx->poly());
    Polynomial value = anyToPolynomial(anyValue);
    variables[id] = value;
    return std::make_any<Polynomial>(value);
}

std::any PolyBuilderVisitor::visitPrintExpr(PolynomialParser::PrintExprContext* ctx) {
    return visit(ctx->poly());
}

std::any PolyBuilderVisitor::visitPoly(PolynomialParser::PolyContext* ctx) {
    if (ctx->term().empty()) {
        return std::make_any<Polynomial>();
    }

    
    auto anyFirst = visit(ctx->term(0));
    Polynomial result = anyToPolynomial(anyFirst);

    
    int termIndex = 1;
    for (size_t i = 0; i < ctx->children.size(); i++) {
        auto child = ctx->children[i];
        std::string text = child->getText();

        
        if (text == "+" || text == "-") {
            
            if (termIndex < ctx->term().size()) {
                auto anyNext = visit(ctx->term(termIndex));
                Polynomial nextTerm = anyToPolynomial(anyNext);

                if (text == "+") {
                    result = result + nextTerm;
                }
                else {
                    result = result - nextTerm;
                }
                termIndex++;
            }
        }
    }

    return std::make_any<Polynomial>(result);
}

std::any PolyBuilderVisitor::visitTerm(PolynomialParser::TermContext* ctx) {
    double coeff = 1.0;
    int xDeg = 0, yDeg = 0, zDeg = 0;

    
    if (ctx->coefficient()) {
        std::string coeffStr = ctx->coefficient()->getText();
        coeff = std::stod(coeffStr);
    }

    
    if (ctx->variables()) {
        for (auto varCtx : ctx->variables()->var()) {
            char var = varCtx->VAR()->getText()[0];
            int deg = 1;

            
            if (varCtx->NUM()) {
                deg = std::stoi(varCtx->NUM()->getText());
            }

            switch (var) {
            case 'x': xDeg = deg; break;
            case 'y': yDeg = deg; break;
            case 'z': zDeg = deg; break;
            }
        }
    }

  
    if (coeff == 0.0) {
        return std::make_any<Polynomial>();
    }

    Monom monom(coeff, xDeg, yDeg, zDeg);
    return std::make_any<Polynomial>(Polynomial(monom));
}

Polynomial PolyBuilderVisitor::getVariable(const std::string& name) const {
    auto it = variables.find(name);
    if (it != variables.end()) {
        return it->second;
    }
    throw std::runtime_error("Unknown variable: " + name);
}