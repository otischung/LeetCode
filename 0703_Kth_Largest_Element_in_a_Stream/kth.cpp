#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class KthLargest {
   private:
    int k;
    // Min Heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

   public:
    KthLargest(int k, std::vector<int>& nums) : k(k) {
        for (const auto &n : nums) {
            pq.push(n);
            if (pq.size() > k) {
                pq.pop();
            }
        }
    }

    int add(int val) {
        if (pq.size() < k) {
            pq.push(val);
        } else if (pq.top() < val) {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main(int argc, char** argv) {
    int k, cnt, num;
    std::vector<int> nums;
    std::cin >> k >> cnt;
    if (cnt > 0) {
        for (int i = 0; i < cnt; ++i) {
            std::cin >> num;
            nums.emplace_back(num);
        }
    }
    KthLargest sol(k, nums);
    while (std::cin >> num) {
        std::cout << sol.add(num) << '\n';
    }
    return EXIT_SUCCESS;
}
