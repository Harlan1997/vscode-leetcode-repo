/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
#include "leetcode.h"
class Solution {
public:
    set<vector<int>> ret;
    vector<int> tmp;
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        backTracking(candidates, target, 0, tmp);
        return vector<vector<int>>(ret.begin(), ret.end());
    }

    void backTracking(vector<int> candidates, int target, int index, vector<int> &tmp) {
        if (index == candidates.size()) {
            return;
        }
        if (target == 0) {
            ret.insert(tmp);
            return;
        }
        backTracking(candidates, target, index + 1, tmp);
        if (target >= candidates[index]) {
            tmp.push_back(candidates[index]);
            backTracking(candidates, target - candidates[index], index + 1, tmp);
            tmp.pop_back();
        }
    }

};
// @lc code=end

