#include <bits/stdc++.h>
using namespace std;

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infixToPostfix(string s)
{
    stack<char> st;
    string output = "";

    for (char c : s)
    {
        if (isalnum(c)) // operand
        {
            output += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                output += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        }
        else if (isOperator(c))
        {
            while (!st.empty() && precedence(st.top()) >= precedence(c))
            {
                if (c == '^' && st.top() == '^')
                    break; // handle right-associative '^'
                output += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        output += st.top();
        st.pop();
    }

    return output;
}

int main()
{
    string expr;
    cout << "Enter infix expression: ";
    cin >> expr;

    cout << "Postfix expression: " << infixToPostfix(expr) << endl;
    return 0;
}
