#include <gtest.h>
#include "Polynomial.h"

TEST(TListTest, can_create_empty_list) {
    TList<int> list;
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}

TEST(TListTest, can_push_front) {
    TList<int> list;
    list.push_front(10);
    list.push_front(20);

    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.front(), 20);
    EXPECT_EQ(list.back(), 10);
}

TEST(TListTest, can_push_back) {
    TList<int> list;
    list.push_back(10);
    list.push_back(20);

    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.front(), 10);
    EXPECT_EQ(list.back(), 20);
}

TEST(TListTest, can_pop_front) {
    TList<int> list;
    list.push_back(10);
    list.push_back(20);

    int value = list.pop_front();

    EXPECT_EQ(value, 10);
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.front(), 20);
}

TEST(TListTest, can_pop_back) {
    TList<int> list;
    list.push_back(10);
    list.push_back(20);

    int value = list.pop_back();

    EXPECT_EQ(value, 20);
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.back(), 10);
}

TEST(TListTest, throws_when_pop_from_empty) {
    TList<int> list;

    EXPECT_THROW(list.pop_front(), std::out_of_range);
    EXPECT_THROW(list.pop_back(), std::out_of_range);
}

TEST(TListTest, can_copy_list) {
    TList<int> list1;
    list1.push_back(10);
    list1.push_back(20);

    TList<int> list2(list1);  

    EXPECT_EQ(list2.size(), 2);
    EXPECT_EQ(list2.pop_front(), 10);
    EXPECT_EQ(list2.pop_front(), 20);
}

TEST(TListTest, can_assign_list) {
    TList<int> list1;
    list1.push_back(10);
    list1.push_back(20);

    TList<int> list2;
    list2 = list1;  

    EXPECT_EQ(list2.size(), 2);
    EXPECT_EQ(list2.pop_front(), 10);
    EXPECT_EQ(list2.pop_front(), 20);
}

TEST(TListTest, clear_empties_list) {
    TList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    list.clear();

    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}

TEST(TListTest, iterator_works) {
    TList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    int sum = 0;
    for (auto it = list.begin(); it != list.end(); ++it) {
        sum += *it;
    }

    EXPECT_EQ(sum, 60);
}


TEST(MonomTest, can_create_monom) {
    Monom m(2.5, 2, 1, 0);

    EXPECT_DOUBLE_EQ(m.getCoef(), 2.5);
    EXPECT_EQ(m.getXDeg(), 2);
    EXPECT_EQ(m.getYDeg(), 1);
    EXPECT_EQ(m.getZDeg(), 0);
}

TEST(MonomTest, can_create_default_monom) {
    Monom m;

    EXPECT_DOUBLE_EQ(m.getCoef(), 0.0);
    EXPECT_EQ(m.getXDeg(), 0);
    EXPECT_EQ(m.getYDeg(), 0);
    EXPECT_EQ(m.getZDeg(), 0);
    EXPECT_TRUE(m.isZero());
}

TEST(MonomTest, can_copy_monom) {
    Monom m1(2.5, 2, 1, 0);
    Monom m2(m1);  

    EXPECT_DOUBLE_EQ(m2.getCoef(), 2.5);
    EXPECT_EQ(m2.getXDeg(), 2);
    EXPECT_EQ(m2.getYDeg(), 1);
    EXPECT_EQ(m2.getZDeg(), 0);
}

TEST(MonomTest, can_assign_monom) {
    Monom m1(2.5, 2, 1, 0);
    Monom m2;

    m2 = m1;  

    EXPECT_DOUBLE_EQ(m2.getCoef(), 2.5);
    EXPECT_EQ(m2.getXDeg(), 2);
    EXPECT_EQ(m2.getYDeg(), 1);
    EXPECT_EQ(m2.getZDeg(), 0);
}

TEST(MonomTest, pack_degrees_works) {
    Monom m(1.0, 3, 5, 7);

    EXPECT_EQ(m.getXDeg(), 3);
    EXPECT_EQ(m.getYDeg(), 5);
    EXPECT_EQ(m.getZDeg(), 7);
}

TEST(MonomTest, comparison_operators_work) {
    Monom m1(2.5, 2, 1, 0);
    Monom m2(3.0, 2, 1, 0);  
    Monom m3(1.0, 1, 0, 0);  

    EXPECT_TRUE(m1 == m2);    
    EXPECT_FALSE(m1 == m3);
    EXPECT_TRUE(m1 != m3);

    EXPECT_TRUE(m3 < m1);      
    EXPECT_TRUE(m1 > m3);
}

TEST(MonomTest, multiplication_works) {
    Monom m1(2.0, 2, 1, 0);  
    Monom m2(3.0, 1, 1, 2);  

    Monom result = m1 * m2;

    EXPECT_DOUBLE_EQ(result.getCoef(), 6.0);
    EXPECT_EQ(result.getXDeg(), 3);  
    EXPECT_EQ(result.getYDeg(), 2);  
    EXPECT_EQ(result.getZDeg(), 2);  
}

TEST(MonomTest, addition_works_for_like_terms) {
    Monom m1(2.0, 2, 1, 0);
    Monom m2(3.0, 2, 1, 0);

    Monom result = m1 + m2;

    EXPECT_DOUBLE_EQ(result.getCoef(), 5.0);
    EXPECT_EQ(result.getXDeg(), 2);
    EXPECT_EQ(result.getYDeg(), 1);
    EXPECT_EQ(result.getZDeg(), 0);
}

TEST(MonomTest, addition_throws_for_unlike_terms) {
    Monom m1(2.0, 2, 1, 0);
    Monom m2(3.0, 1, 0, 0);

    EXPECT_THROW(m1 + m2, std::invalid_argument);
}

TEST(MonomTest, subtraction_works_for_like_terms) {
    Monom m1(5.0, 2, 1, 0);
    Monom m2(3.0, 2, 1, 0);

    Monom result = m1 - m2;

    EXPECT_DOUBLE_EQ(result.getCoef(), 2.0);
    EXPECT_EQ(result.getXDeg(), 2);
    EXPECT_EQ(result.getYDeg(), 1);
    EXPECT_EQ(result.getZDeg(), 0);
}

TEST(MonomTest, evaluate_works) {
    Monom m(2.5, 2, 1, 0);  

    double val = m.evaluate(2.0, 3.0, 0);  

    EXPECT_DOUBLE_EQ(val, 30.0);
}

TEST(MonomTest, isZero_works) {
    Monom m1(0.0, 2, 1, 0);
    Monom m2(2.5, 2, 1, 0);

    EXPECT_TRUE(m1.isZero());
    EXPECT_FALSE(m2.isZero());
}

TEST(MonomTest, setter_works) {
    Monom m;
    m.setCoef(3.5);
    m.setDeg(2, 3, 4);

    EXPECT_DOUBLE_EQ(m.getCoef(), 3.5);
    EXPECT_EQ(m.getXDeg(), 2);
    EXPECT_EQ(m.getYDeg(), 3);
    EXPECT_EQ(m.getZDeg(), 4);
}

TEST(MonomTest, getPackDeg_returns_packed_value) {
    Monom m(1.0, 3, 5, 7);
    unsigned int packed = m.getPackDeg();

    
    Monom m2(1.0, packed & 1023, (packed >> 10) & 1023, (packed >> 20) & 1023);

    EXPECT_EQ(m2.getXDeg(), 3);
    EXPECT_EQ(m2.getYDeg(), 5);
    EXPECT_EQ(m2.getZDeg(), 7);
}

TEST(PolynomialTest, can_create_empty_polynomial) {
    Polynomial p;

    EXPECT_TRUE(p.isEmpty());
    EXPECT_EQ(p.getSize(), 0);
}

TEST(PolynomialTest, can_add_monom) {
    Polynomial p;
    Monom m(2.5, 2, 1, 0);

    p.addMonom(m);

    EXPECT_EQ(p.getSize(), 1);
    EXPECT_FALSE(p.isEmpty());
}

TEST(PolynomialTest, combines_like_terms_automatically) {
    Polynomial p;
    p.addMonom(Monom(2.0, 2, 1, 0));   
    p.addMonom(Monom(3.0, 2, 1, 0));   

    EXPECT_EQ(p.getSize(), 1);  
}

TEST(PolynomialTest, removes_zero_terms) {
    Polynomial p;
    p.addMonom(Monom(2.0, 2, 1, 0));    
    p.addMonom(Monom(-2.0, 2, 1, 0));   

    EXPECT_EQ(p.getSize(), 0);  
    EXPECT_TRUE(p.isEmpty());
}

TEST(PolynomialTest, can_add_polynomials) {
    Polynomial p1;
    p1.addMonom(Monom(2.0, 2, 0, 0));  
    p1.addMonom(Monom(1.0, 1, 0, 0));  

    Polynomial p2;
    p2.addMonom(Monom(3.0, 2, 0, 0)); 
    p2.addMonom(Monom(4.0, 0, 0, 0));  

    Polynomial sum = p1 + p2;

    EXPECT_EQ(sum.getSize(), 3);  
}

TEST(PolynomialTest, can_subtract_polynomials) {
    Polynomial p1;
    p1.addMonom(Monom(5.0, 2, 0, 0));  
    p1.addMonom(Monom(3.0, 1, 0, 0));  

    Polynomial p2;
    p2.addMonom(Monom(2.0, 2, 0, 0));  
    p2.addMonom(Monom(1.0, 1, 0, 0));  

    Polynomial diff = p1 - p2;

    EXPECT_EQ(diff.getSize(), 2);  
}

TEST(PolynomialTest, can_multiply_polynomials) {
    Polynomial p1;
    p1.addMonom(Monom(2.0, 1, 0, 0));  
    p1.addMonom(Monom(1.0, 0, 0, 0));  

    Polynomial p2;
    p2.addMonom(Monom(3.0, 1, 0, 0));  
    p2.addMonom(Monom(2.0, 0, 0, 0));  

    Polynomial prod = p1 * p2;

    EXPECT_EQ(prod.getSize(), 3);
}

TEST(PolynomialTest, can_multiply_by_scalar) {
    Polynomial p;
    p.addMonom(Monom(2.0, 2, 1, 0));  
    p.addMonom(Monom(3.0, 1, 0, 0));  

    Polynomial result = p * 2.5;

    EXPECT_EQ(result.getSize(), 2);
}

TEST(PolynomialTest, can_evaluate) {
    Polynomial p;
    p.addMonom(Monom(2.0, 2, 0, 0));  
    p.addMonom(Monom(3.0, 1, 0, 0));  
    p.addMonom(Monom(1.0, 0, 0, 0));  

    double val = p.evaluate(2.0, 0, 0);  

    EXPECT_DOUBLE_EQ(val, 15.0);
}


TEST(PolynomialTest, can_compare_polynomials) {
    Polynomial p1;
    p1.addMonom(Monom(2.0, 2, 0, 0));
    p1.addMonom(Monom(1.0, 1, 0, 0));

    Polynomial p2;
    p2.addMonom(Monom(2.0, 2, 0, 0));
    p2.addMonom(Monom(1.0, 1, 0, 0));

    Polynomial p3;
    p3.addMonom(Monom(3.0, 2, 0, 0));

    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3);
    EXPECT_TRUE(p1 != p3);
}

TEST(PolynomialTest, unary_minus_works) {
    Polynomial p;
    p.addMonom(Monom(2.0, 2, 0, 0));   
    p.addMonom(Monom(-3.0, 1, 0, 0));  

    Polynomial neg = -p;

   
    EXPECT_EQ(neg.getSize(), 2);
}

TEST(PolynomialTest, clear_empties_polynomial) {
    Polynomial p;
    p.addMonom(Monom(2.0, 2, 0, 0));
    p.addMonom(Monom(3.0, 1, 0, 0));

    p.clear();

    EXPECT_TRUE(p.isEmpty());
    EXPECT_EQ(p.getSize(), 0);
}

TEST(PolynomialTest, complex_expression) {
    Polynomial p1;
    p1.addMonom(Monom(2.0, 1, 0, 0));
    p1.addMonom(Monom(1.0, 0, 0, 0));

    Polynomial p2;
    p2.addMonom(Monom(3.0, 1, 0, 0));
    p2.addMonom(Monom(2.0, 0, 0, 0));

    Polynomial result = p1 * p2;

    EXPECT_EQ(result.getSize(), 3);

   
    double val = result.evaluate(1.0, 0, 0);
    EXPECT_DOUBLE_EQ(val, 15.0);  
}

TEST(PolynomialTest, three_variable_expression) {
    Polynomial p;
    p.addMonom(Monom(2.0, 2, 1, 0));  
    p.addMonom(Monom(3.0, 0, 2, 1));  
    p.addMonom(Monom(1.0, 1, 0, 0)); 

    double val = p.evaluate(2.0, 3.0, 4.0);
    
    EXPECT_DOUBLE_EQ(val, 134.0);
}

