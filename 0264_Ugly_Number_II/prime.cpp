#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
   public:
    int nthUglyNumber(int n) {
        std::vector<int> dp(n);
        dp[0] = 1;

        int p1 = 0, p2 = 0, p3 = 0;

        for (int i = 1; i < n; ++i) {
            int twoMul = dp[p1] * 2;
            int threeMul = dp[p2] * 3;
            int fiveMul = dp[p3] * 5;

            dp[i] = std::min(twoMul, std::min(threeMul, fiveMul));

            if (dp[i] == twoMul) ++p1;
            if (dp[i] == threeMul) ++p2;
            if (dp[i] == fiveMul) ++p3;
        }

        return dp[n - 1];
    }
};

int main(int argc, char **argv) {
    Solution s;
    int n;
    while (std::cin >> n) {
        std::cout << s.nthUglyNumber(n) << '\n';
    }
    return EXIT_SUCCESS;
}
