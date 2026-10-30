class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      unordered_set<char> set;
      int left = 0;
      int maxLength = 0;
      for(int i = 0;i<s.size();i++){
        while(set.count(s[i])){
          set.erase(s[left]);
          left++;
        }
        maxLength = max(maxLength, i-left+1);
        set.insert(s[i]);
      }
      return maxLength;
    }
};