class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> map;
        map['[']=']';
        map['{']='}';
        map['(']=')';
        vector<char> order;
        for(char c:s){
            if(map.count(c)){
                order.push_back(c);
            }else{
                if(order.empty()||map[order.back()]!=c)return false;
                order.pop_back();
            }
        }
        return order.empty();
    }
};
