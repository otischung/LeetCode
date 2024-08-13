#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class Solution {
  private:
    void recursive(
        std::vector<int> &candidates,
        std::vector<std::vector<int>> &ret,
        std::vector<int> &ans,
        int target,
        int idx) {
        if (target == 0) {
            ret.emplace_back(ans);
            return;
        }
        for (int i = idx; i < candidates.size(); ++i) {
            // i > idx means that it is NOT the first time scanning this item.
            // If this item is same as the previous item, it must have been considered before.
            if (i > idx && candidates[i] == candidates[i - 1]) continue;
            // If this item is greater than this item, then there is no answer.
            // This will return and cause pop_back in the previous function call.
            if (candidates[i] > target) return;
            // Otherwise, we can add this item to see if this will form a correct answer.
            ans.emplace_back(candidates[i]);
            // Recursive call, reduce remain target, scan from the next index.
            recursive(candidates, ret, ans, target - candidates[i], i + 1);
            // Finish the recursive call, pop 1 item and scan the next item in the next for loop.
            ans.pop_back();
        }
    }

  public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates, int target) {
        std::vector<std::vector<int>> ret;
        std::vector<int> ans;
        // We must sort the candidates first.
        std::sort(candidates.begin(), candidates.end());
        recursive(candidates, ret, ans, target, 0);
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    std::vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    std::vector<std::vector<int>> sol = s.combinationSum2(candidates, target);
    std::cout << "[\n";
    for (const auto &i : sol) {
        std::cout << "\t[";
        for (const auto &j : i) {
            std::cout << j << ',';
        }
        std::cout << "],\n";
    }
    std::cout << "]\n";
    return EXIT_SUCCESS;
}
