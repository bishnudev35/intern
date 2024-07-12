#include <bits/stdc++.h>
using namespace std;

// Function to determine precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to perform the infix to postfix conversion
vector<string> infixToPostfix(const string& infix) {
    stack<char> operators;
    vector<string> postfix;
    set<char> opSet = {'+', '-', '*', '/'};
    string operand = "";
    bool decimalFound = false;

    for (char c : infix) {
        if (isdigit(c) || (c == '.' && !decimalFound)) {
            if (c == '.') decimalFound = true;
            operand += c;
        } else {
            if (!operand.empty()) {
                postfix.push_back(operand);
                operand = "";
                decimalFound = false;
            }
            if (c == '(') {
                operators.push(c);
            } else if (c == ')') {
                while (!operators.empty() && operators.top() != '(') {
                    postfix.push_back(string(1, operators.top()));
                    operators.pop();
                }
                operators.pop(); // pop the '(' from the stack
            } else if (opSet.find(c) != opSet.end()) {
                while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                    postfix.push_back(string(1, operators.top()));
                    operators.pop();
                }
                operators.push(c);
            }
        }
    }

    if (!operand.empty()) {
        postfix.push_back(operand);
    }

    while (!operators.empty()) {
        postfix.push_back(string(1, operators.top()));
        operators.pop();
    }

    return postfix;
}

// Function to perform calculation based on the operator
string calculate(string a, string b, string op) {
    double x = stod(a);
    double y = stod(b);
    double ans = 0.0;

    if (op == "+") ans = y + x;
    else if (op == "-") ans = y - x;
    else if (op == "*") ans = y * x;
    else if (op == "/") ans = y / x;

    return to_string(ans);
}

// Function to evaluate the postfix expression
string evaluate(vector<string> postfix) {
    stack<string> st;
    set<string> operators = {"+", "-", "*", "/"};

    for (const string& token : postfix) {
        if (operators.find(token) == operators.end()) {
            st.push(token);
        } else {
            string a = st.top(); st.pop();
            string b = st.top(); st.pop();
            string result = calculate(a, b, token);
            st.push(result);
        }
    }

    return st.top();
}

int main() {
    while (true) {
        string infix;
        cout << "Enter infix expression (or type 'exit' to quit): ";
        getline(cin, infix);

        if (infix == "exit") break;

        vector<string> postfix = infixToPostfix(infix);
        cout << "Postfix expression: ";
        for (const string& token : postfix) {
            if (!token.empty()) {
                cout << token << " ";
            }
        }
        cout << endl;

        string result = evaluate(postfix);
        // Remove trailing zeros and decimal point
        result.erase(result.find_last_not_of('0') + 1, string::npos);
        if (result.back() == '.') result.pop_back();

        cout << "Evaluation result: " << result << endl;
    }
    return 0;
}
