class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      int n = numbers.size();
       unordered_map <int, int> prevMap;

      for(int i = 0; i < n; i++)
      {
        int diff = target - numbers[i]; 
        if(prevMap.find(diff) != prevMap.end())
        {
            return {prevMap[diff] + 1, i + 1};
        }
        prevMap.insert({numbers[i], i});
      }
      return {};
    }
};
