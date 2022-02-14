/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
//#include "leetcode.h"
class Solution {
public:
    int jump(vector<int>& nums) {
        int cnt = 0;
        int index = 0;
        if (nums.size() == 1) {
            return 0;
        }
        while (index < nums.size()) {
            if (index + nums[index] >= nums.size() - 1) {
                return cnt + 1;
            }
            index = findMax(nums, index, index + nums[index]);
            cnt++;
        }
        return cnt;
    }

    int findMax(vector<int>& nums, int index, int end) {
        int _max = -1;
        int ret = -1;
        for (int i = index; i <= end; i++) {
            int reachable_stride = i - index + nums[i];
            if (reachable_stride > _max) {
                _max = reachable_stride;
                ret = i;
            }
        }
        return ret;
    }
};
// @lc code=end

