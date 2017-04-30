//
// Created by togrul on 4/28/2017.
//
#include <iostream>
//#include <sstream>
#include <cstdlib>
#include <cstdio>
//#include <cmath>

using namespace std;

class ProblemE {
public:
    long long int parseString(std::string line) {
        iteration = 0;
        long long int digit = getInt(line, iteration);
        for (int i = iteration; i < line.size(); i++) {
            i = iteration;

            while (!isdigit(line[i]) && i < line.size()) {
                if (line[i] == 'p') { //plus
                    i = iteration + 4;
                    digit += getInt(line, i);

                } else if (line[i] == 'm') { //minus
                    i = iteration + 5;
                    digit -= getInt(line, i);

                } else if (line[i] == 't' && line[i + 1] == 'i') { // times
                    i = iteration + 5;
                    digit *= getInt(line, i);

                } else if (line[i] == 't' && line[i + 11] == 'f') { //tothepowerof
                    i = iteration + 12;
                    long long int eded2 = 1;
                    for (int j = 0; j < getInt(line, i); j++) {
                        eded2 *= digit;
                    }
                    digit = eded2;
                }
                i++;
            }
        }

        return digit;
    }

private:
    int iteration = 0;
//    long long int digit = 0;

    long long int getInt(std::string line, int i) {
        long long int number = 0;
        while (isdigit(line[i]) && i < line.size()) {
            number += (line[i] - '0');
            number = number * 10;
            i++;
        }
        number /= 10;
        iteration = i;
        return number;
    }

    // Convert string to int
    long long int getIntX(std::string line, int i) {
        long long int number = 0;
        std::string stringNumber;
        while (isdigit(line[i]) && i < line.size()) {
            stringNumber += line[i];
            i++;
        }

        number = atoi(stringNumber.c_str());
//        cout << number << endl;
        iteration = i;
        return number;
    }

};


int main() {
    freopen("output.txt", "w", stdout); //Redirect cin and cout to files
    int times;
    int counter = 0;
    std::string line;
    long long number;

    std::ios_base::sync_with_stdio(false); // Supposedly makes I/O faster
    ProblemE problemE;
    std::cin >> times;
    std::getline(std::cin, line);
    while (times--) {
        counter++;
        std::getline(std::cin, line);
        std::cout << "Case #" << counter << ": " << problemE.parseString(line) << std::endl;
    }
}
