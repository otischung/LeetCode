#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    int minimumPushes(std::string input) {
        std::vector<int> hash(26, 0);
        int cnt = 0;
        for (const auto &c : input) {
            // Only process lowercase letters
            if (c >= 'a' && c <= 'z') {
                ++hash[c - 'a'];
            } else {
                continue;
            }
        }
        std::sort(hash.begin(), hash.end(), std::greater<int>());
        for (int i = 0; i < hash.size(); ++i) {
            if (hash[i] == 0) break;
            // Since there are only 8 keyboards, the 8th char will need to press one more time.
            // All keys need to press at least 1 time.
            cnt += hash[i] * (i / 8 + 1);
        }
        return cnt;
    }
};

int main(int argc, char **argv) {
    Solution s;
    std::cout << "Please enter the input string: ";
    std::string input;
    std::cin >> input;
    std::cout << s.minimumPushes(input) << '\n';
    return EXIT_SUCCESS;
}
