/**
 * Header file defines the functions to evaluate arithmetic expressions
 */

#ifndef ASSIGN_4_EVAL_EXPR_H
#define ASSIGN_4_EVAL_EXPR_H

#include <string>
using namespace std;

// #define IS_OPERATOR_CHAR(c) c == '+' || c == '-' || c == '*' || c == '/'
// #define is_division_by_zero(x) x == 0
// #define is_add_sub(c) c == '+' || c == '-'
// #define is_div_mult(c) c == '*' || c == '/'
// #define add_operator_w_space(op) string(1, op) + ' '

// #define TOO_FEW_OPERATOR false
// #define DIVISION_BY_0 false
// #define UNKNOWN_CHAR false
// #define UNVALID_POSTFIX_EXPR false

/**
 * @brief Evaluate a postfix expression
 * @param postfix_expr The input expression in the postfix format.
 * @param result gets the evaluated value of the expression (by reference).
 * @return true if expression is a valid postfix expression and evaluation is done without error, otherwise false.
 */
bool evalPostfixExpr(string postfix_expr, float& result);

/**
 * @brief Convert an infix expression to an equivalent postfix expression
 * @param infix_expr The input expression in the infix format.
 * @return the converted postfix expression. If the input infix expression is invalid, return an empty string "";
 */
string convertInfixToPostfix(string infix_expr);

/**
 * @brief Evaluate an infix expression. It's converted to a postfix expression first and then evaluated
 * @param infix_expr The input expression in the infix format.
 * @param result gets the evaluated value of the expression (by reference).
 * @return true if expression is valid and evaluation is done without error, otherwise false.
 */
bool evalInfixExpr(string infix_expr, float& result);

#endif //ASSIGN_4_EVAL_EXPR_H
