#include "ExpressionManager.h"
#include "ExpressionManagerInterface.h"
#include <sstream>

using namespace std;

bool ExpressionManager::isBalanced(string expression) {
  stringstream ss(expression);
  stack <char> equation;
  char placeHolder;
  while (ss >> placeHolder) {
     if (placeHolder == '{' || placeHolder == '[' || placeHolder == '(') {
        equation.push(placeHolder);
     }
     else if (placeHolder == '}' || placeHolder == ']' || placeHolder == ')') {
        if (equation.size() > 0) {
           if (equation.top() == '{' && placeHolder == '}') {
              equation.pop();
           }
           else if (equation.top() == '[' && placeHolder == ']') {
              equation.pop();
           }
           else if (equation.top() == '(' && placeHolder == ')') {
              equation.pop();
           }
        }
        else {
           return false;
        }
     }
  }
  if (equation.empty()) {
     return true;
  }
  else {
     return false;
  }
  
}

bool ExpressionManager::isNumber(string token) {
    stringstream ss(token);
    string::const_iterator it = token.begin();
    while (it != token.end() && isdigit(*it)) ++it;
    return !token.empty() && it == token.end();
}

bool ExpressionManager::isOperator(string token) {
    stringstream ss(token);
    string op;
    while (ss >> op) {
        if (op == "*" || op == "/" || op == "+" || op == "-" || op == "%") {
        return true;
        }
        else {
            cout << "False because " << op << " is not an operator." << endl;
            return false;
        }
    }
}

bool ExpressionManager::isOperand(string token) {
    stringstream ss(token);
    string op;
    while (ss >> op) {
        if (op == "*" || op == "/" || op == "+" || op == "-" || op == "%" || 
        op == "[" || op == "{" || op == "(" || op == ")" || op == "}" || op == "]") {
        return true;
        }
        else {
            cout << "False because " << op << " is not an operand." << endl;
            return false;
        }
    }
}

bool ExpressionManager::operatorCount(string expression) {
    stringstream ss(expression);
    string op;
    int numCount = 0;
    while (ss >> op) {
                if (numCount >= 1) {
           return false;
        }
        if (isNumber(op)) {
            numCount = numCount - 1;
        }
        else if (isOperator(op)) {
            numCount = numCount + 1;
        }
    }
    return true;
}

bool ExpressionManager::postfixValid(string postfixExpression) {
    int operatorCount = 0;
    int intCount = 0;
    stringstream ss(postfixExpression);
    string token;
    while (ss >> token) {
        if (isNumber(token)) {
            intCount = intCount + 1;
        }
        else if (isOperator(token)) {
            operatorCount = operatorCount + 1;
        }
    }
    if ((intCount - 1) == operatorCount) {
        return true;
    }
    else {
        return false;
    }
}

string ExpressionManager::postfixEvaluate(string postfixExpression) {
   stringstream ss(postfixExpression);
   stack<string> myStack;
   string token;
   string valueOne;
   string valueTwo;
   if (postfixValid(postfixExpression)) {
       while (ss >> token) {
           if (isOperand(token) && myStack.size() < 2) {
               return "invalid";
           }
           if (isNumber(token)) {
           myStack.push(token);
           }
           else if (isOperator(token) && myStack.size() >= 2) {
               int newValue = 0;
               int firstValue;
               int secondValue;
               string str;
               valueTwo = myStack.top();
               myStack.pop();
               valueOne = myStack.top();
               myStack.pop();
               stringstream kk(valueOne);
               kk >> firstValue;
               stringstream pp(valueTwo);
               pp >> secondValue;
               switch(token[0]) {
                     case '+':
                     newValue = firstValue + secondValue;
                     str = to_string(newValue);
                     myStack.push(str);
                     break;
                     case '-':
                     newValue = firstValue - secondValue;
                     str = to_string(newValue);
                     myStack.push(str);
                     break;
                     case '*':
                     newValue = firstValue * secondValue;
                     str = to_string(newValue);
                     myStack.push(str);
                     break;
                     case '/':
                     if (secondValue == 0) {
                        return "invalid";
                     }
                     newValue = firstValue / secondValue;
                     str = to_string(newValue);
                     myStack.push(str);
                     break;
                     case '%':
                     newValue = firstValue % secondValue;
                     str = to_string(newValue);
                     myStack.push(str);
                     break;
               }
           }
       }
       return myStack.top();
   }
   else {
       return "invalid";
   }
}

string ExpressionManager::postfixToInfix(string postfixExpression) {
   stringstream ss(postfixExpression);
   stack<string> myStack;
   string token;
   string valueOne;
   string valueTwo;
   if (postfixValid(postfixExpression)) {
       while (ss >> token) {
           if (isNumber(token)) {
           myStack.push(token);
           }
           else if (isOperator(token) && myStack.size() >= 2) {
               string newString;
               int firstValue;
               int secondValue;
               string str;
               valueTwo = myStack.top();
               myStack.pop();
               valueOne = myStack.top();
               myStack.pop();
               switch(token[0]) {
                     case '+':
                     newString = "( " + valueOne + " + " + valueTwo + " )";
                     myStack.push(newString);
                     break;
                     case '-':
                     newString = "( " + valueOne + " - " + valueTwo + " )";
                     myStack.push(newString);
                     break;
                     case '*':
                     newString = "( " + valueOne + " * " + valueTwo + " )";
                     myStack.push(newString);
                     break;
                     case '/':
                     newString = "( " + valueOne + " / " + valueTwo + " )";
                     myStack.push(newString);
                     break;
                     case '%':
                     newString = "( " + valueOne + " % " + valueTwo + " )";
                     myStack.push(newString);
                     break;
               }
           }
           else {
               return "invalid";
           }
       }
       if (myStack.top().size() == 1) {
           return "invalid";
       }
       return myStack.top();
   }
   else {
       return "invalid";
   }
}


int ExpressionManager::priorityEvaluation(string p) {
    if (p == "}" || p == "]" || p == ")") {
        return 3;
    }
    else if (p == "*" || p == "/" || p == "%") {
        return 2;
    }
    else if (p == "+" || p == "-") {
        return 1;
    }
    else {
        return 0;
    }
}

bool ExpressionManager::MatchNotFound(string B, string A) {
    if (A == ")" && B == "(") {
        return false;
    }
    else if (A == "]" && B == "[") {
        return false;
    }
    else if (A == "}" && B == "{") {
        return false;
    }
    else {
        return true;
    }
}
/*
bool ExpressionManager::MatchNotFound(string leftOperand, string token) {
    if (leftOperand == "{" && token == "}") {
        return false;
    }
    else if (leftOperand == "[" && token == "]") {
        return false;
    }
    else if (leftOperand == "(" && token == ")") {
        return false;
    }
    else {
        return true;
    }
}*/

string ExpressionManager::infixToPostfix(string infixExpression) {
   stringstream ss(infixExpression);
   stack<string> myStack;
   string myExpression;
   string token;
   if (isBalanced(infixExpression) == false) {
       return "invalid";
   }
   if (operatorCount(infixExpression) == false) {
       return "invalid";
   }
   while (ss >> token) {
       if (isNumber(token)) {
           myExpression.append(token + " ");
       }
       else if (isOperand(token)) {
           switch(priorityEvaluation(token)) {
               case 0:
               myStack.push(token); 
               break;
               case 1:
               if (myStack.empty()) {
                   myStack.push(token);
                   break;
               }
               else if (priorityEvaluation(myStack.top()) == 0) {
                       myStack.push(token);
                       break;
               }
               while (myStack.size() > 0 && priorityEvaluation(myStack.top()) >=1) { 
                    string temp = myStack.top();
                    myExpression.append(temp + " ");
                    myStack.pop();
               }
               myStack.push(token);
               break;
               case 2:
               if (myStack.empty()) {
                   myStack.push(token);
               }
               else if (priorityEvaluation(myStack.top()) < 2) {
                   myStack.push(token);
               }
               else if (priorityEvaluation(myStack.top()) >= 2) { 
                   string temp = myStack.top();
                    myExpression.append(temp + " ");
                    myStack.pop();
                    myStack.push(token);
               }
               break;
               case 3:
               if (myStack.size() > 0) {
                   while (MatchNotFound(myStack.top(), token)) {
                        string temp = myStack.top();
                        myExpression.append(temp + " ");
                        myStack.pop();
                   }
               }
               if (MatchNotFound(myStack.top(), token) == false) {
                   myStack.pop();
               }
               break;
           }
       }
       else {
           return "invalid";
       }
   }
   while (myStack.size() > 0) {
       string temp = myStack.top();
       myExpression.append(temp + " ");
       myStack.pop();
   }
   if (myExpression.substr(myExpression.size() - 1, 1) == " ") {
       myExpression.resize(myExpression.size() - 1);
   }
   if (isNumber(myExpression.substr(myExpression.size() - 1, 1)) || myExpression.size() == 1) {
       return "invalid";
   }
   return myExpression;
}
