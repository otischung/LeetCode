#include <iostream>
#include <string>
#include <unordered_map>

typedef struct LOC_PAIR {
    size_t i, j;
} lp;

class Solution {
   private:
    size_t ans_i = 0, ans_j = 0;

   public:
    Solution() : ans_i(0), ans_j(0) {}
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, size_t> char_umap;
        size_t i = 0, j = 0;

        size_t ans = 1;

        if (s.length() == 0) {
            return 0;
        }

        char_umap.insert(std::pair<char, int>(s.at(j), j + 1));
        for (j = 1; j < s.length(); ++j) {
            // If this char is not in map.
            if (char_umap.count(s.at(j)) == 0) {
                // Add this char into map
                char_umap.insert(std::pair<char, int>(s.at(j), j + 1));
            }
            // Otherwise,
            else {
                // Move i to the location specified by map.
                i = std::max(char_umap[s.at(j)], i);
                // Set the location of this char to be the next index.
                char_umap[s.at(j)] = j + 1;
            }

            // Check if the answer is longer or not.
            if (ans < j - i + 1) {
                ans = j - i + 1;
                ans_i = i;
                ans_j = j;
            }
        }
        return ans;
    }

    lp get_location() {
        lp ret;
        ret.i = ans_i;
        ret.j = ans_j;
        return ret;
    }
};

int main() {
    Solution s;
    std::string question = "abcdeafbdgcbb";
    int len = s.lengthOfLongestSubstring(question);
    lp loc = s.get_location();
    std::cout << len << '\n';
    std::cout << loc.i << ' ' << loc.j << '\n';
    std::cout << question.substr(loc.i, loc.j - loc.i + 1) << '\n';
    return 0;
}
