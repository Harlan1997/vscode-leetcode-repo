/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
#include "leetcode.h"
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backTracking(candidates, target, 0, tmp);
        return res;
    }

    void backTracking(vector<int>& candidates, int target, int index, vector<int> &tmp) {
        if (target == 0) {
            res.push_back(tmp);
            return;
        } 
        if (index == candidates.size()) {
            return;
        }
        for(int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (target - candidates[i] >= 0) {
                tmp.push_back(candidates[i]);
                backTracking(candidates, target - candidates[i], i + 1, tmp);
                tmp.pop_back();
            } else {
                break;
            }
        }
    }
};
// @lc code=end

