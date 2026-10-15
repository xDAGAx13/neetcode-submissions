class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> set(nums.begin(), nums.end());
    int maxLength = 0;
    for(int num:set){
      if(!set.count(num-1)){
        int length = 1;
        int current = num;
        while(set.count(current+1)){
          length++;
          current++;
        }
        maxLength = max(length, maxLength);
      }
    }
    return maxLength;
  }
};
