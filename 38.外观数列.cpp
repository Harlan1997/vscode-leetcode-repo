/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
#include "leetcode.h"
class Solution {
public:
    string countAndSay(int n) {
        string prev = "1";
        for (int i = 2; i <= n; i++) {
            string curr = "";
            int start = 0;
            int pos = 0;
            while (pos < prev.length()) {   
                while (pos < prev.length() && prev[pos] == prev[start]) {
                    pos++;
                }
                curr += to_string(pos-start) + prev[start];
                start = pos;
            }
            prev = curr;
        }
        return prev;
    }
};
// @lc code=end

