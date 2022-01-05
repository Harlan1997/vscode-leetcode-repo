#include "leetcode.h"
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backTracking(candidates, target, 0);
        return res;
    }

    void backTracking(vector<int>& candidates, int target, int index) {
        if (index >= candidates.size()) {
            return;
        }
        int num = candidates[index];  
        if (target == num) {
            tmp.push_back(num);
            res.push_back(tmp);
            return;
        } else if (target > 0 && target < num && !tmp.empty()) {
            int tail = tmp.back();
            tmp.pop_back();
            target += tail;
            backTracking(candidates, target, index + 1);
        } else if (target > num) {
            tmp.push_back(num);
            backTracking(candidates, target - num, index);
            tmp.pop_back();
            backTracking(candidates, target, index + 1);
        }       
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> v = {2, 3, 6, 7};
    s->combinationSum(v, 7);
}

