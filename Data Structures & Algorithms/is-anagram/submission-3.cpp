class Solution {
public:
    bool isAnagram(string s, string t) {
        for(char x:s){
            if(std::count(s.begin(), s.end(), x)!=std::count(t.begin(), t.end(), x)){
                return false;
            }
        }
        for(char x:t){
            if(std::count(s.begin(), s.end(), x)!=std::count(t.begin(), t.end(), x)){
                return false;
            }
        }
        return true;
    }
};
