#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class Solution {
   private:
    void dfs(int idx, int& size, std::vector<bool>& visited, std::vector<std::vector<int>>& stones) {
        visited[idx] = true;
        for (int i = 0; i < size; ++i) {
            if (!visited[i]) {
                // Search for the stones along the x-axis.
                if (stones[i][0] == stones[idx][0]) {
                    dfs(i, size, visited, stones);
                }
                // Search for the stones along the y-axis.
                if (stones[i][1] == stones[idx][1]) {
                    dfs(i, size, visited, stones);
                }
            }
        }
    }

   public:
    int removeStones(std::vector<std::vector<int>>& stones) {
        /********************************************************************************
         * You can only remove stones that belong to the same group.
         * Therefore, if the number of stones is greater than the number of groups,
         * then these extra stones must not form any new groups.
         * They must belong to an existing group.
         ********************************************************************************/
        int size = stones.size();
        int group = 0;
        std::vector<bool> visited(size, false);

        for (int i = 0; i < size; ++i) {
            if (!visited[i]) {
                dfs(i, size, visited, stones);
                group += 1;
            }
        }
        return size - group;
    }
};

int main() {
    Solution s;
    int size, x, y;
    std::cin >> size;
    if (size < 1) {
        std::cerr << "Error, the size must be at least 1.\n";
        return 1;
    }
    std::vector<std::vector<int>> stones(size, std::vector<int>(2));
    for (int i = 0; i < size; ++i) {
        std::cin >> x >> y;
        stones[i][0] = x;
        stones[i][1] = y;
    }
    std::cout << s.removeStones(stones) << '\n';
    return EXIT_SUCCESS;
}
