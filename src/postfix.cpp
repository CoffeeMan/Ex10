// Copyright 2021 Stolbov Yaroslav
#include <stack>
#include "postfix.h"
std::string infix2postfix(std::string infix) {
    std::string current;
    std::stack <char> st;
    int priority;
    for (int i = 0; i < infix.length(); i++) {
        priority = getP(infix[i]);
        if (priority == 0)
            current += infix[i];
        if (priority == 1)
            st.push(infix[i]);
        if (priority > 1) {
            while (!st.empty()) {
                if (getP(st.top()) >= priority) {
                    current = current + st.top();
                    st.pop();
                } else {
                    break;
                }
            }
            st.push(infix[i]);
        }
        if (priority == -1) {
            while (getP(st.top()) != 1) {
                current += ' ';
                current += st.top();
                st.pop();
            }
            st.pop();
        }
    }
    current += ' ';
    while (!st.empty()) {
        current += st.top();
        st.pop();
        current += ' ';
    }
    for (int i = 0; i < current.length(); i++)
        if (current[i] == ' ' && current[i + 1] == ' ')
        {current.erase(i, 1); i = (i - 1);}
    if (current[current.length() - 1] == ' ')
        current.erase(current.size() - 1);
        /*current = current.substr(0, current.size() - 1);*/
    return current;
}

int getP(char token) {
    if (token == '*' || token == '/')
        return 3;
    else if (token == '+' || token == '-')
        return 2;
    else if (token == '(')
        return 1;
    else if (token == ')')
        return -1;
    else
        return 0;
}
