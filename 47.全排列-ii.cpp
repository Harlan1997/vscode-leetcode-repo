/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
#include "leetcode.h"
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // set insert log(n)
        set<vector<int>> ret;
        backTracking(ret, nums, 0);
        return vector<vector<int>>(ret.begin(), ret.end());
    }

    void backTracking(set<vector<int>> &ret, vector<int>& nums, int index) {
        if (index == nums.size() - 1) {
            ret.insert(nums);
            return;
        }
        // i = index -> no swap
        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            // swap, the number of position index is certain. go to next position
            backTracking(ret, nums, index + 1);
            // no swap, go to the next position
            swap(nums[index], nums[i]);
        }
    }
};
// @lc code=end

