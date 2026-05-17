#include <vector>
#include <unordered_set>

class Solution {
public:
    bool hasDuplicate(std::vector<int>& nums) 
    {
        std::unordered_set<int> seen;
        for(int num : nums)
        {
            // If the number is already in the set, it's a duplicate
            if(seen.find(num) != seen.end())
                return true;
            seen.insert(num);
        }
        return false;
    }
};
