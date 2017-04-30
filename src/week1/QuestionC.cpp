//
// Created by togrul on 4/28/2017.
//

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include <vector>
#include <regex>
#include <cstdio>

using namespace std;

class QuestionC {
public:

    void replaceString(string line) {
        std::vector<std::string> words = split(line);

        std::cout << "burdadi" << std::endl;
        for (int i = 0; i < words.size(); ++i) {
            std::cout << i << endl;

            if (replace(words[i], "studentin", "studierende")) {
                continue;
            } else if (replace(words[i], "studenten", "studierende")) {
                continue;
            } else if (replace(words[i], "student", "studierender")) {
                continue;
            } else if (replace(words[i], "entin", "studierender")) {
                continue;
            } else if (replace(words[i], "enten", "ierende")) {
                continue;
            } else if (replace(words[i], "ent", "ierender")) {
                continue;
            }
        }
        for (int i = 0; i < words.size() - 1; ++i) {
            std::cout << words[i] << " ";
        }
//        if (words.size() > 0)
        std::cout << words[words.size() - 1];

    }

private:
    std::vector<std::string> split(const std::string line) {
        string str(line);
        string buf;
        stringstream ss(str); // Insert the string into a stream

        std::vector<string> tokens; //  vector to hold our words

        while (ss >> buf)
            tokens.push_back(buf);
        return tokens;
    }

    bool replace(std::string &word, const std::string &pattern, const std::string &newStr) {
        std::string::size_type pos = 0u;
        bool ifFound = false;
        while ((pos = word.find(pattern, pos)) != std::string::npos) {
            word.replace(pos, pattern.length(), newStr);
            pos += newStr.length();
            ifFound = true;
        }
        return ifFound;
    }
};

int main() {
    QuestionC questionX;
    questionX.replaceString("ein zierenderner ierende ierenderhaelt keine studierende");
    exit(-1);
    std::ios_base::sync_with_stdio(false); // Supposedly makes I/O faster
//    freopen("output.txt", "w", stdout); //Redirect cin and cout to files

    QuestionC questionC;
    int t;
    int times;
    std::cin >> t;
    std::cin >> times;
    std::cout << "Case #1:" << std::endl;
    std::string line;
    std::getline(std::cin, line);
    while (times-- > 0) {
        std::getline(std::cin, line);
        if (line != "") {
            questionC.replaceString(line);
            std::cout << std::endl;
        }
    }

    return 0;
}
