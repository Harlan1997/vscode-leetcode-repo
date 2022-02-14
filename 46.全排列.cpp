/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
//#include "leetcode.h"
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        backTracking(ret, nums, 0);
        return ret;
    }

    void backTracking(vector<vector<int>>& ret, vector<int>& nums, int index) {
        if (index == nums.size()) {
            ret.push_back(nums);
        }
        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            backTracking(ret, nums, index + 1);
            swap(nums[index], nums[i]);
        }
    }
};
// @lc code=end

