#include "PolyBuilderVisitor.h"
#include <iostream>
#include <cmath>

// ============================================
// Реализация методов visitor
// ============================================

antlrcpp::Any PolyBuilderVisitor::visitProg(PolynomialParser::ProgContext* ctx) {
    Polynomial result;

    // Проходим по всем инструкциям
    for (auto stat : ctx->stat()) {
        result = visit(stat).as<Polynomial>();
    }

    return result;
}

antlrcpp::Any PolyBuilderVisitor::visitAssign(PolynomialParser::AssignContext* ctx) {
    // Получаем имя переменной
    std::string id = ctx->ID()->getText();

    // Вычисляем полином справа от "="
    Polynomial value = visit(ctx->poly()).as<Polynomial>();

    // Сохраняем в хранилище
    variables[id] = value;

    return value;
}

antlrcpp::Any PolyBuilderVisitor::visitPrintExpr(PolynomialParser::PrintExprContext* ctx) {
    // Просто вычисляем полином
    return visit(ctx->poly());
}

antlrcpp::Any PolyBuilderVisitor::visitPoly(PolynomialParser::PolyContext* ctx) {
    if (ctx->term().empty()) {
        return Polynomial();
    }

    // Начинаем с первого терма
    Polynomial result = visit(ctx->term(0)).as<Polynomial>();

    // Обрабатываем остальные термы
    for (size_t i = 1; i < ctx->term().size(); i++) {
        // Получаем знак оператора (между термами)
        std::string op = ctx->getChild(2 * i - 1)->getText();
        Polynomial nextTerm = visit(ctx->term(i)).as<Polynomial>();

        if (op == "+") {
            result = result + nextTerm;
        }
        else {  // op == "-"
            result = result - nextTerm;
        }
    }

    return result;
}

antlrcpp::Any PolyBuilderVisitor::visitTerm(PolynomialParser::TermContext* ctx) {
    double coeff = 1.0;
    int xDeg = 0, yDeg = 0, zDeg = 0;

    // Обработка знака
    if (ctx->sign()) {
        if (ctx->sign()->getText() == "-") {
            coeff = -1.0;
        }
    }

    // Обработка коэффициента
    if (ctx->coefficient()) {
        coeff *= std::stod(ctx->coefficient()->getText());
    }

    // Обработка переменных
    if (ctx->variables()) {
        for (auto varCtx : ctx->variables()->var()) {
            char var = varCtx->VAR()->getText()[0];
            int deg = 1;

            if (varCtx->exponent) {
                deg = std::stoi(varCtx->exponent->getText());
            }

            switch (var) {
            case 'x': xDeg = deg; break;
            case 'y': yDeg = deg; break;
            case 'z': zDeg = deg; break;
            }
        }
    }

    // Если коэффициент нулевой, возвращаем пустой полином
    if (coeff == 0.0) {
        return Polynomial();
    }

    // Создаём моном и полином
    Monom monom(coeff, xDeg, yDeg, zDeg);
    return Polynomial(monom);
}

Polynomial PolyBuilderVisitor::getVariable(const std::string& name) const {
    auto it = variables.find(name);
    if (it != variables.end()) {
        return it->second;
    }
    throw std::runtime_error("Unknown variable: " + name);
}