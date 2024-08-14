#include <math.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class Solution {
   private:
    bool at_least_k_pair_dist_less_or_equal_to_mid(std::vector<int> &nums, int k, int mid) {
        int cnt = 0;
        int left = 0;

        for (int right = 1; right < nums.size(); ++right) {
            while (nums[right] - nums[left] > mid) ++left;
            cnt += right - left;
        }
        return k <= cnt;
    }

   public:
    // Binary search, O(n log n + n log(max distance))
    int smallestDistancePair(std::vector<int> &nums, int k) {
        // Sort the input array, then the max. dist. pair is formed by the first and the last elements.
        std::sort(nums.begin(), nums.end());
        // Perform binary search by "distance".
        int left = 0;
        int right = nums.back() - nums.front();
        int mid;

        while (left < right) {
            // Calculate the middle distance.
            mid = left + (right - left) / 2;

            // If there are at least k pairs with a distance less than or equal to mid,
            if (at_least_k_pair_dist_less_or_equal_to_mid(nums, k, mid)) {
                // then we search for potentially smaller distances.
                right = mid;
            } else {  // If there are less than k pairs with a distance less than or equal to mid,
                // then we search for larger distances.
                left = mid + 1;
            }
        }

        return left;
    }
    // Max heap, O(n^2 log k)
    // int smallestDistancePair(std::vector<int> &nums, int k) {
    //     std::priority_queue<int> pq;
    //     for (int i = 0; i < nums.size() - 1; ++i) {
    //         for (int j = i + 1; j < nums.size(); ++j) {
    //             pq.push(abs(nums[i] - nums[j]));
    //             if (pq.size() > k) {
    //                 pq.pop();
    //             }
    //         }
    //     }
    //     return pq.top();
    // }
};

int main(int argc, char **argv) {
    Solution s;
    std::vector<int> nums;
    int k, num;
    std::cin >> k;
    while (std::cin >> num) {
        nums.emplace_back(num);
    }
    std::cout << s.smallestDistancePair(nums, k) << '\n';
    return EXIT_SUCCESS;
}
