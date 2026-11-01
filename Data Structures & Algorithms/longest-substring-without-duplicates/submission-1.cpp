class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      unordered_set<char> seen;
      int left = 0;
      int maxLength = 0;
      for(int i = 0; i<s.size();i++){
        while(seen.count(s[i])){
          seen.erase(s[left]);
          left++;
        }
        seen.insert(s[i]);
        maxLength = max(maxLength, i-left+1);
      }
      return maxLength;
    }
};