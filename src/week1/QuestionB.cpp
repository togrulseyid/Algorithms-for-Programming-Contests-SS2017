//
// Created by togrul on 4/28/2017.
// Used https://github.com/panks/BigInteger/blob/master/BigIntegerSingleFile.cpp multiplication and add methods
//

#include <iostream>
#include <cstdlib>
#include<sstream>
#include <cstring>

#define C_SQUARE "89875517873681764"

using namespace std;

std::string add(std::string number1, std::string number2) {
    std::string add = (number1.length() > number2.length()) ? number1 : number2;
    char carry = '0';
    int differenceInLength = abs((int) (number1.size() - number2.size()));

    if (number1.size() > number2.size())
        number2.insert(0, differenceInLength, '0'); // put zeros from left

    else// if(number1.size() < number2.size())
        number1.insert(0, differenceInLength, '0');

    for (int i = number1.size() - 1; i >= 0; --i) {
        add[i] = ((carry - '0') + (number1[i] - '0') + (number2[i] - '0')) + '0';

        if (i != 0) {
            if (add[i] > '9') {
                add[i] -= 10;
                carry = '1';
            } else
                carry = '0';
        }
    }
    if (add[0] > '9') {
        add[0] -= 10;
        add.insert(0, 1, '1');
    }
    return add;
}

std::string multiply(std::string n1, std::string n2) {
    if (n1.length() > n2.length())
        n1.swap(n2);

    std::string res = "0";
    for (int i = n1.length() - 1; i >= 0; --i) {
        std::string temp = n2;
        int currentDigit = n1[i] - '0';
        int carry = 0;

        for (int j = temp.length() - 1; j >= 0; --j) {
            temp[j] = ((temp[j] - '0') * currentDigit) + carry;

            if (temp[j] > 9) {
                carry = (temp[j] / 10);
                temp[j] -= (carry * 10);
            } else
                carry = 0;

            temp[j] += '0'; // back to string mood
        }

        if (carry > 0)
            temp.insert(0, 1, (carry + '0'));

        temp.append((n1.length() - i - 1), '0'); // as like mult by 10, 100, 1000, 10000 and so on

        res = add(res, temp); // O(n)
    }

    while (res[0] == '0' && res.length() != 1) // erase leading zeros
        res.erase(0, 1);

    return res;
}

int main() {
    int count;
    std::cin >> count;
    int countDown = count;

    std::string materia;
    while (--countDown >= 0) {
        std::cin >> materia;

        std::cout << "Case #" << count - countDown << ": " << multiply(C_SQUARE, materia) << std::endl;
    }

    return 0;
}