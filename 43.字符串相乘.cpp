/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
#include "leetcode.h"
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int m = num1.length();
        int n = num2.length();
        vector<int> v(m + n);
        for (int i = m - 1; i >= 0; i--) {
            int x = num1[i] - '0';
            for (int j = n - 1; j >= 0; j--) {
                int y = num2[j] - '0';
                int res = x * y;
                v[i + j + 1] += res;
            }
        }
        for (int i = m + n - 1; i > 0; i--) {
            v[i - 1] += v[i] / 10;
            v[i] %= 10;
        }
        int index = v[0] == 0 ? 1 : 0;
        string ret;
        while (index < m + n) {
            ret.push_back(v[index] + '0');
            index++;
        }
        return ret;
    }
};
// @lc code=end

