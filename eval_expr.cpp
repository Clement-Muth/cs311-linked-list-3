/**
 *Implementation of the functions to evaluate arithmetic expressions
 *The implementation should use the Stack data structure
 */
// You must complete the TODO parts and then complete LinkedList.cpp. Delete "TODO" after you are done.
// You should always comments to each function to describe its PURPOSE and PARAMETERS
#include <stdbool.h>
#include <string>
#include "stack.h"
#include "eval_expr.h"

#ifndef TEST_DEFINE_DEBUG
#define TEST_DEFINE_DEBUG
    #define IS_OPERATOR_CHAR(c) c == '+' || c == '-' || c == '*' || c == '/'
    #define is_division_by_zero(x) x == 0
    #define is_add_sub(c) c == '+' || c == '-'
    #define is_div_mult(c) c == '*' || c == '/'
    #define add_operator_w_space(op) string(1, op) + ' '

    #define TOO_FEW_OPERATOR false
    #define DIVISION_BY_0 false
    #define UNKNOWN_CHAR false
    #define UNVALID_POSTFIX_EXPR false
#endif //TEST_DEFINE_DEBUG

float (*Calculator::operations[256])(float, float) = {0};

float processOperation(char const c, float const operand1, float const operand2) {
    Calculator::initializeOperations();

    return Calculator::operations[c](operand1, operand2);
}

/**
 *@brief Evaluate a postfix expression
 *@param postfix_expr The input expression in the postfix format.
 *@param result gets the evaluated value of the expression (by reference).
 *@return true if expression is a valid postfix expression and evaluation is done without error, otherwise false.
 */
bool evalPostfixExpr(string postfix_expr, float &result)
{
    Stack<float> operandStack;

    for (char c : postfix_expr) {
        if (isdigit(c)) operandStack.push(static_cast<float>(c - '0'));
        else if (isspace(c)) continue;
        else if (IS_OPERATOR_CHAR(c)) {
            if (operandStack.size() < 2) return TOO_FEW_OPERATOR;
            float operand2 = 0;
            float operand1 = 0;
            float result = 0;

            operandStack.pop(operand2);
            operandStack.pop(operand1);
            result = round(processOperation(c, operand1, operand2) * 10) / 10;
            if (result == -1) return DIVISION_BY_0;
            operandStack.push(result);
        }
        else return UNKNOWN_CHAR;
    }
    if (operandStack.size() == 1) {
        operandStack.pop(result);
        return true;
    }
    else return UNVALID_POSTFIX_EXPR;
}

static int precedence(char const op)
{
    return is_add_sub(op) ? 1 : is_div_mult(op) ? 2 : 0;
}

static bool processOperationConvert(string const infix_expr, Stack<char>& operatorStack, string& postfix_expr)
{
    for (char c : infix_expr) {
        switch (c) {
            case ' ':
                break;
            case '(':
                operatorStack.push(c);
                break;
            case ')':
                while (!operatorStack.isEmpty() && operatorStack.top() != '(') {
                    char topOperator;

                    operatorStack.pop(topOperator);
                    postfix_expr += add_operator_w_space(topOperator);
                }
                if (!operatorStack.isEmpty() && operatorStack.top() == '(') {
                    char openParenthesis;

                    operatorStack.pop(openParenthesis);
                } else return false;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                while (!operatorStack.isEmpty() && operatorStack.top() != '(' && precedence(c) <= precedence(operatorStack.top())) {
                    char topOperator;

                    operatorStack.pop(topOperator);
                    postfix_expr += add_operator_w_space(topOperator);
                }
                operatorStack.push(c);
                break;
            default:
                if (isdigit(c)) postfix_expr += add_operator_w_space(c);
                else return false;
        }
    }
    return true;
}

/**
 *@brief Convert an infix expression to an equivalent postfix expression
 *@param infix_expr The input expression in the infix format.
 *@return the converted postfix expression. If the input infix expression is invalid, return an empty string "";
 */
string convertInfixToPostfix(string infix_expr)
{
    string postfix_expr;
    Stack<char> operatorStack;
    const bool process_result = processOperationConvert(infix_expr, operatorStack, postfix_expr);

    if (!process_result) return "";
    while (!operatorStack.isEmpty()) {
        char topOperator;

        if (operatorStack.top() == '(') return "";
        operatorStack.pop(topOperator);
        postfix_expr += add_operator_w_space(topOperator);
    }
    if (!postfix_expr.empty()) postfix_expr.pop_back();
    return postfix_expr;
}

/**
 *@brief Evaluate an infix expression. It's converted to a postfix expression first and then evaluated
 *@param infix_expr The input expression in the infix format.
 *@param result gets the evaluated value of the expression (by reference).
 *@return true if expression is valid and evaluation is done without error, otherwise false.
 */
bool evalInfixExpr(string infix_expr, float &result)
{
    string postfix_expr = convertInfixToPostfix(infix_expr);

    return postfix_expr.empty() ? false : evalPostfixExpr(postfix_expr, result);
}
