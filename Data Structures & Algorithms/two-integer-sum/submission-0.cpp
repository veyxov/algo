class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        
        for (int i = 0; i < nums.size(); ++i) {
            int cur_x = nums[i];
            int need = target - cur_x;

            if (mp.contains(need)) {
                return {mp[need], i};
            }
            mp[cur_x] = i;
        }

        return {0, 0};
    }
};
