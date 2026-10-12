class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<vector<string>> out;
      unordered_map<string, vector<string>> map;
      for(auto& str : strs){
        string need(26,0);
        for(char c:str){
          need[c-'a']++;
        }
        map[need].push_back(str);
      }
      for(auto& val:map){
        out.push_back(val.second);
      }
      return out;
    }
};