#include <algorithm>
#include <iostream>
#include <vector>

typedef struct NUM {
    int num;
    int idx;
} Num;

class Solution {
   private:
    Num max1, max2, min1, min2;

   public:
    int maxDistance(std::vector<std::vector<int>> &arrays) {
        // Initialization, set max and min to the first two arrays.
        if (arrays[0][0] > arrays[1][0]) {
            min1.num = arrays[1][0];
            min1.idx = 1;
            min2.num = arrays[0][0];
            min2.idx = 0;
        } else {
            min1.num = arrays[0][0];
            min1.idx = 0;
            min2.num = arrays[1][0];
            min2.idx = 1;
        }
        if (arrays[0].back() > arrays[1].back()) {
            max1.num = arrays[0].back();
            max1.idx = 0;
            max2.num = arrays[1].back();
            max2.idx = 1;
        } else {
            max1.num = arrays[1].back();
            max1.idx = 1;
            max2.num = arrays[0].back();
            max2.idx = 0;
        }

        if (arrays.size() > 2) {
            for (int i = 2; i < arrays.size(); ++i) {
                if (min1.num > arrays[i][0]) {
                    min2.num = min1.num;
                    min2.idx = min1.idx;
                    min1.num = arrays[i][0];
                    min1.idx = i;
                } else if (min2.num > arrays[i][0]) {
                    min2.num = arrays[i][0];
                    min2.idx = i;
                }
                if (max1.num < arrays[i].back()) {
                    max2.num = max1.num;
                    max2.idx = max1.idx;
                    max1.num = arrays[i].back();
                    max1.idx = i;
                } else if (max2.num < arrays[i].back()) {
                    max2.num = arrays[i].back();
                    max2.idx = i;
                }
            }
        }

        // Return the final answer.
        if (max1.idx != min1.idx) {
            return max1.num - min1.num;
        } else {
            if (max2.num - min1.num > max1.num - min2.num) {
                return max2.num - min1.num;
            } else {
                return max1.num - min2.num;
            }
        }
    }
};

int main(int argc, char **argv) {
    Solution s;
    std::vector<std::vector<int>> arrays = {
        {-1, 1},
        {-3, 1, 4},
        {-2, -1, 0, 2}
    };
    std::cout << s.maxDistance(arrays) << '\n';
    return EXIT_SUCCESS;
}
