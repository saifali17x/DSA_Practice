class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map <int, int> mp;
        int res = 0;

        for(int num : nums)
        {
            if(!mp[num]) // If the number hasn't been seen yet
            {
                mp[num] = mp[num - 1] + mp[num + 1] + 1;  // 1 + 1 + 1 = 3

                // Update the left boundary of the new sequence
                mp[num - mp[num - 1]] = mp[num];  // 3 - mp[2] = 3 - 1 = 2 → mp[2] = 3

                // Update the right boundary of the new sequence
                mp[num + mp[num + 1]] = mp[num];  // 3 + mp[4] = 3 + 1 = 4 → mp[4] = 3
                res = max(res, mp[num]);  // update the result if this sequence is the longest so far
            }
        }
        return res;
    }
};