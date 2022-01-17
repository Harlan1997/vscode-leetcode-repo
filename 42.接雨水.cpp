/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
#include "leetcode.h"
class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        int left = 0, right = len - 1;
        int leftMax = 0, rightMax = 0;
        int ret = 0;
        while (left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if (height[left] < height[right]) {
                ret = ret + leftMax - height[left];
                left++;
            }
            if (height[left] >= height[right]) {
                ret = ret + rightMax - height[right];
                right--;
            }
        }
        return ret;
    }
};
// @lc code=end

