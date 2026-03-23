#pragma once

// Подключаем сгенерированный ANTLR базовый visitor
#include "PolynomialBaseVisitor.h"

// Подключаем наши классы
#include "include/Polynomial.h"

#include <map>
#include <string>

/**
 * @brief Visitor для построения объектов Polynomial из дерева разбора
 *
 * Этот класс наследуется от PolynomialBaseVisitor (сгенерирован ANTLR)
 * и переопределяет методы для каждого типа узла.
 */
class PolyBuilderVisitor : public PolynomialBaseVisitor {
private:
    // Хранилище переменных (для присваиваний)
    std::map<std::string, Polynomial> variables;

public:
    // Посещение узла программы
    virtual antlrcpp::Any visitProg(PolynomialParser::ProgContext* ctx) override;

    // Посещение узла присваивания (a = 2x + 3y)
    virtual antlrcpp::Any visitAssign(PolynomialParser::AssignContext* ctx) override;

    // Посещение узла выражения (2x + 3y)
    virtual antlrcpp::Any visitPrintExpr(PolynomialParser::PrintExprContext* ctx) override;

    // Посещение узла полинома (сумма термов)
    virtual antlrcpp::Any visitPoly(PolynomialParser::PolyContext* ctx) override;

    // Посещение узла терма (2x^2y)
    virtual antlrcpp::Any visitTerm(PolynomialParser::TermContext* ctx) override;

    // Получить значение переменной
    Polynomial getVariable(const std::string& name) const;
};