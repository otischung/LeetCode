#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    vector<int> table;
    void resize_table(int size) {
        table.resize(size + 1, 2147483647);
        table[0] = 0;
    }

   public:
    int coinChange(vector<int>& coins, int amount) {
        resize_table(amount);
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                int remain = i - coins[j];
                if (remain >= 0 && table[remain] != 2147483647) {
                    table[i] = min(table[i], 1 + table[remain]);
                }
            }
        }
        return (table[amount] == 2147483647) ? -1 : table[amount];
    }
};

int main() {
    Solution s;
    vector<int> coins = {1, 2, 5};
    cout << s.coinChange(coins, 11) << endl;
    return 0;
}
