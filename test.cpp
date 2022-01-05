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

int main() {
    Solution *s = new Solution();
    vector<int> v = {2, 5, 2, 1, 2};
    cout << s->combinationSum2(v, 5).size();
}
