#include <iostream>
#include <string>
#include <vector>

class Solution {
   private:
    static constexpr int REPEAT_TIMES = 3;
    bool checker(const std::string &s, int length) {
        // The count for a-z, initialize to 0.
        std::vector<int> hashcnt(26, 0);
        int idx = 0;

        for (int i = 0; i < s.size(); ++i) {
            // Get the max index of the same character from i to idx.
            while (s[idx] != s[i])
                ++idx;
            // If the length of the substring passed the threshold.
            if (i - idx + 1 >= length)
                // Increase the corresponding count.
                ++hashcnt[s[i] - 'a'];
            // If the count of the character is greater than or equal to REPEAT_TIMES, then return true.
            if (hashcnt[s[i] - 'a'] >= REPEAT_TIMES)
                return true;
        }
        return false;
    }

   public:
    int maximumLength(std::string s) {
        // Perform a binary search on the length of the substring.
        // The problem exhibits monotonic behavior.
        // If the distinct length is valid, then all smaller lengths are also valid.
        // If the distinct length is invalid, then all greater lengths are also invalid.
        int min_len = 1;
        int max_len = s.size();

        if (!checker(s, min_len))
            return -1;

        while (min_len + 1 < max_len) {
            int length = min_len + (max_len - min_len) / 2;
            if (checker(s, length))
                min_len = length;
            else
                max_len = length;
        }

        return min_len;
    }
};

int main(int argc, char **argv) {
    Solution s;
    std::string str;
    while (std::cin >> str) {
        std::cout << s.maximumLength(str) << std::endl;
    }
    return EXIT_SUCCESS;
}
