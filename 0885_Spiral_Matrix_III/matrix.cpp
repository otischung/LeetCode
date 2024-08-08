#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        std::vector<std::vector<int>> result;
        // valids: How many index is legel.
        // cnt: How many loop cycle been run, starts from 0.
        // mode: Specify the mode change. 0: right; 1: down; 2: left; 3: up.
        // step: Specify how many scan steps in a mode.
        int valids = 0, cnt = 0, mode = 0, step = 1;
        int x = rStart, y = cStart;
        while (valids < rows * cols) {
            // For debugging
            // std::cout << "// [" << x << ',' << y << "]\n";
            // If points is legal
            if (x >= 0 && x < rows && y >= 0 && y < cols) {
                ++valids;
                std::vector<int> coor(2);
                coor[0] = x;
                coor[1] = y;
                result.emplace_back(coor);
            }

            switch (mode) {
                case 0:
                    ++y;
                    break;
                case 1:
                    ++x;
                    break;
                case 2:
                    --y;
                    break;
                case 3:
                    --x;
                    break;
                default:
                    break;
            }
            ++cnt;
            if (cnt == step) {
                mode = (mode + 1) % 4;
            } else if (cnt == step * 2) {
                mode = (mode + 1) % 4;
                ++step;
                cnt = 0;
            }
        }
        return result;
    }
};

int main(int argc, char **argv) {
    Solution s;
    int rows, cols, rStart, cStart;
    while (std::cin >> rows >> cols >> rStart >> cStart) {
        std::vector<std::vector<int>> result = s.spiralMatrixIII(rows, cols, rStart, cStart);
        std::cout << '[';
        for (const auto &i : result) {
            std::cout << '[' << i[0] << ',' << i[1] << "],";
        }
        std::cout << "]\n";
    }
    return EXIT_SUCCESS;
}
