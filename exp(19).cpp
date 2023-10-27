/* 
 22070123132
Exp_19
infix and postfix expression solving using stack.
menu options - i) Push ii) Pop iii) Display iv) exit
*/

#include <iostream>
#include <stack>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to determine the precedence of an operator
int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to convert infix expression to postfix expression
string infixToPostfix(string infix) {
    stack<char> operatorStack;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            operatorStack.push(c);
        } else if (c == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            if (!operatorStack.empty() && operatorStack.top() == '(') {
                operatorStack.pop();
            }
        } else if (isOperator(c)) {
            while (!operatorStack.empty() && getPrecedence(c) <= getPrecedence(operatorStack.top())) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }

    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

int main() {
    stack<char> stack;
    string infixExpression, postfixExpression;

    while (true) {
        cout << "Menu options:" << endl;
        cout << "1. Push (Infix Expression)" << endl;
        cout << "2. Pop (Convert and Display Postfix Expression)" << endl;
        cout << "3. Display (Current Stack)" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        char choice;
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Enter the infix expression: ";
                cin >> infixExpression;
                postfixExpression = infixToPostfix(infixExpression);
                cout << "Infix expression pushed onto the stack." << endl;
                break;
            case '2':
                if (postfixExpression.empty()) {
                    cout << "No infix expression in the stack." << endl;
                } else {
                    cout << "Postfix Expression: " << postfixExpression << endl;
                    postfixExpression = "";
                }
                break;
            case '3':
                if (postfixExpression.empty()) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Current Stack: " << infixExpression << endl;
                }
                break;
            case '4':
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
        }
    }

    return 0;
}
/*Output
Menu options:
1. Push (Infix Expression)
2. Pop (Convert and Display Postfix Expression)
3. Display (Current Stack)
4. Exit
Enter your choice: 1
Enter the infix expression: (A+B)*C
Infix expression pushed onto the stack.        
Menu options:
1. Push (Infix Expression)
2. Pop (Convert and Display Postfix Expression)
3. Display (Current Stack)
4. Exit
Enter your choice: 3
Current Stack: (A+B)*C
Menu options:
1. Push (Infix Expression)
2. Pop (Convert and Display Postfix Expression)
3. Display (Current Stack)
4. Exit
Enter your choice: 2
Postfix Expression: AB+C*
Menu options:
1. Push (Infix Expression)
2. Pop (Convert and Display Postfix Expression)
3. Display (Current Stack)
4. Exit
Enter your choice: 4
Exiting the program.
*/
