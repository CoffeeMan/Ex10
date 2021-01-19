// Copyright 2021 Stolbov Yaroslav
#include <iostream>
#include <string>
#include "postfix.h"

int main() {
    std::string s1("2 + 2");
    std::string s2 = infix2postfix(s1);
    std::cout << s2;
    return 0;
}
