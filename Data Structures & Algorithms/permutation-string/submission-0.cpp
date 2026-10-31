class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      if(s2.size()<s1.size())return false;
      vector<int> need(26,0);
      for(char c:s1){
        need[c-'a']++;
      }
      vector<int> check(26,0);
      for(int i = 0; i<s1.size();i++){
        check[s2[i]-'a']++;
      }
      if(need==check)return true;
      for(int i = s1.size();i<s2.size();i++){
        check[s2[i-s1.size()]-'a']--;
        check[s2[i]-'a']++;
        if(need==check)return true;
      }
      return false;
    }
};
