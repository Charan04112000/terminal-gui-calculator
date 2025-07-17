#include <string>
#include <stdexcept>
#include <sstream>
#include <stack>
#include <cctype>
#include <cmath>

double evaluateExpression(const std::string& expr) {
    std::istringstream in(expr);
    std::stack<double> values;
    std::stack<char> ops;

    auto precedence = [](char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    };

    auto applyOp = [](double a, double b, char op) {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': 
                if (b == 0) throw std::runtime_error("Division by zero");
                return a / b;
            default: throw std::runtime_error("Unknown operator");
        }
    };

    double num;
    char ch;
    while (in >> std::ws) {
        if (isdigit(in.peek()) || in.peek() == '.') {
            in >> num;
            values.push(num);
        } else {
            in >> ch;
            while (!ops.empty() && precedence(ops.top()) >= precedence(ch)) {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                values.push(applyOp(a, b, ops.top()));
                ops.pop();
            }
            ops.push(ch);
        }
    }

    while (!ops.empty()) {
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        values.push(applyOp(a, b, ops.top()));
        ops.pop();
    }

    if (values.empty()) throw std::runtime_error("Invalid expression");
    return values.top();
}

