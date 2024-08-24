#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
   public:
    std::string nearestPalindromic(std::string n) {
        int len = n.size();
        bool is_odd = len & 1;
        int mid = is_odd ? len / 2 : len / 2 - 1;
        std::string ret;

        // If it has only 1 digit.
        if (len == 1) {
            ret.push_back(n[0] - 1);
            return ret;
        }
        // First half
        for (int i = 0; i <= mid; ++i) {
            ret.push_back(n[i]);
        }
        // Second half
        mid = is_odd ? mid - 1 : mid;
        for (int i = mid; i >= 0; --i) {
            ret.push_back(n[i]);
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    std::string input;

    while (std::cin >> input) {
        std::cout << s.nearestPalindromic(input) << '\n';
    }
    return EXIT_SUCCESS;
}
