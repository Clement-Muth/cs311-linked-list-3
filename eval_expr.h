/**
 * Header file defines the functions to evaluate arithmetic expressions
 */

#ifndef ASSIGN_4_EVAL_EXPR_H
#define ASSIGN_4_EVAL_EXPR_H

#include <string>
using namespace std;

class Calculator {
    public:
        static float add(float a, float b) {
            return a + b;
        }

        static float subtract(float a, float b) {
            return a - b;
        }

        static float multiply(float a, float b) {
            return a * b;
        }

        static float divide(float a, float b) {
            return is_division_by_zero(b) ? -1 : a / b;
        }

        static void initializeOperations() {
            operations['+'] = add;
            operations['-'] = subtract;
            operations['*'] = multiply;
            operations['/'] = divide;
        }

        static float (*operations[256])(float, float);

    private:
        static bool is_division_by_zero(float b) {
            return b == 0;
        }
};

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
