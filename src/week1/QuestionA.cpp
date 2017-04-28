//
// Created by togrul on 4/28/2017.
//

#include <iostream>

int main() {
    int count;
    std::cin >> count;
    int countDown = count;

    std::string name;
    while (--countDown >= 0) {
        std::cin >> name;

        std::cout << "Case #" << count - countDown << ": Hello " << name << "!\n";
    }

    return 0;
}