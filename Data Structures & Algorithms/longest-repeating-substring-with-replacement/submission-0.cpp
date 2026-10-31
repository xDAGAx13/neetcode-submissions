class Solution {
public:
  int characterReplacement(string s, int k) {
    unordered_map<char, int>freq;
    int left = 0;
    int maxLength = 0;
    int maxFreq = 0;
    for(int i = 0; i<s.size();i++){
      freq[s[i]]++;
      maxFreq = max(maxFreq, freq[s[i]]);
      int length = i - left+1;
      int cost = length - maxFreq;
      if(cost>k){
        freq[s[left]]--;
        left++;
      }
      maxLength = max(maxLength, i - left+1);
    }
  return maxLength;
  }
};