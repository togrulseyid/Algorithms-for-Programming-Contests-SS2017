//
// Created by togrul on 4/28/2017.
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

struct gr {
    template<class T>
    bool operator()(T const &a, T const &b) const { return a > b; }
};

int main() {
    int times;
    int count;
    scanf("%d", &times);
    int caseNum = 1;
    while (times--) {
        scanf("%d", &count);
        std::vector<std::vector<int>> plays(count);
        int num;
        while (count--) {
            std::vector<int> players(5);

            for (int p = 0; p < 5; ++p) {
                scanf("%d", &num);
                players[p] = num;
            }

            std::sort(players.begin(), players.end(), gr());
            plays[count] = players;
        }

        std::sort(plays.begin(), plays.end(), gr());

        printf("Case #%d:\n", caseNum);
        for (int i = 0; i < plays.size(); i++) {
            for (int j = 0; j < 5; j++) {
                printf("%d ", plays[i][j]);
            }
            printf("\n");
        }

        plays.clear();
        caseNum++;
    }

    return 0;
}