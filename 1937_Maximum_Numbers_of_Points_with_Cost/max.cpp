#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
   private:
    std::vector<std::vector<long long>> table;
    // Recursive Method, TLE
    long long fn(std::vector<std::vector<int>>& points, int r, int c) {
        if (r == 0) {
            table[r][c] = points[r][c];
            return table[r][c];
        }
        if (table[r][c] != -1) {
            return table[r][c];
        }
        long long max = 0xFFFFFFFFFFFFFFFF;  // The minimum value of long long int type.
        for (int i = 0; i < points[0].size(); ++i) {
            max = std::max(max, fn(points, r - 1, i) - std::abs(i - c));
        }
        table[r][c] = max + points[r][c];
        return table[r][c];
    }

   public:
    // Recursive Method, TLE
    long long maxPoints(std::vector<std::vector<int>>& points) {
        table.assign(points.size(), std::vector<long long>(points[0].size(), -1));
        long long ans = 0xFFFFFFFFFFFFFFFF;  // The minimum value of long long int type.
        for (int i = 0; i < points[0].size(); ++i) {
            ans = std::max(ans, fn(points, points.size() - 1, i));
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    int row, col, input;
    std::vector<std::vector<int>> points;

    std::cin >> row >> col;
    points.assign(row, std::vector<int>(col));
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            std::cin >> input;
            points[i][j] = input;
        }
    }
    std::cout << s.maxPoints(points) << '\n';
    return EXIT_SUCCESS;
}
