/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include "leetcode.h"
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backTracking(candidates, target, 0, tmp);
        return res;
    }

    void backTracking(vector<int>& candidates, int target, int index, vector<int> &tmp) {
        if (index == candidates.size()) {
            return;
        }
        if (target == 0) {
            res.push_back(tmp);
            return;
        } 
        //选中当前值
        backTracking(candidates, target, index + 1, tmp);
        //不选中当前值
        if (target - candidates[index] >= 0) {
            tmp.push_back(candidates[index]);
            backTracking(candidates, target - candidates[index], index, tmp);
            tmp.pop_back();
        }
    }
};
// @lc code=end

