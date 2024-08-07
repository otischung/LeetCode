#include <assert.h>

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
   private:
    std::vector<std::string> numberword;
    std::string less_than_100(uint8_t num) {
        assert(num < 100);
        std::string ret;

        if (num == 0) return ret;

        if (num <= 20) {
            ret = numberword[num];
        } else {
            ret = numberword[num / 10 + 18];
            if (num % 10 != 0) {
                ret += ' ' + numberword[num % 10];
            }
        }
        return ret;
    }

    std::vector<std::string> less_than_1000(uint16_t num) {
        assert(num < 1000);
        std::vector<std::string> result;

        // 0
        if (num == 0) return result;

        // 1-99
        result.emplace_back(less_than_100(num % 100));

        // 100-999
        if (num > 99) {
            num /= 100;
            result.emplace_back(numberword[28]);
            result.emplace_back(less_than_100(num));
        }

        return result;
    }

   public:
    Solution() {
        numberword = {
            // 0-20
            "Zero", "One", "Two", "Three", "Four",
            "Five", "Six", "Seven", "Eight", "Nine",
            "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
            "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen",
            "Twenty",
            // 21-27
            "Thirty", "Forty", "Fifty", "Sixty", "Seventy",
            "Eighty", "Ninety",
            // 28-31
            "Hundred", "Thousand", "Million", "Billion"};
    }
    std::string numberToWords(int num) {
        assert(num >= 0);
        std::vector<std::string> result;
        std::string ret;
        bool is_zero = true;

        for (uint8_t i = 28; i < 32; ++i) {
            // 0
            if (num == 0) {
                break;
            }
            if (i > 28 && num % 1000 != 0) {
                result.emplace_back(numberword[i]);
            }

            // 1-999
            is_zero = false;
            std::vector<std::string> tmp_result = less_than_1000(num % 1000);
            std::move(tmp_result.begin(), tmp_result.end(), std::back_inserter(result));

            num /= 1000;
        }

        // 0
        if (is_zero) {
            return numberword[0];
        }

        for (auto it = result.rbegin(); it != result.rend(); ++it) {
            if ((*it).compare("") != 0) {
                ret += *it;
                ret += ' ';
            }
        }

        ret.pop_back();

        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    int input;

    while (std::cin >> input) {
        std::cout << s.numberToWords(input) << '\n';
    }
    return EXIT_SUCCESS;
}
