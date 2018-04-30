
#pragma once
#include "ExpressionManagerInterface.h"
#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

class ExpressionManager : public ExpressionManagerInterface {
   public:
   ExpressionManager() {}
   ~ExpressionManager() {}
   bool isBalanced(string expression);
   bool isNumber(string token);
   bool isOperator(string token);
   bool operatorCount(string expression);
   bool postfixValid(string postfixExpression);
   string postfixEvaluate(string postfixExpression);
   string postfixToInfix(string postfixExpression);
   int priorityEvaluation(string priority);
   bool isOperand(string token);
   bool MatchNotFound(string leftOperand, string token);
   string infixToPostfix(string infixExpression);
};
