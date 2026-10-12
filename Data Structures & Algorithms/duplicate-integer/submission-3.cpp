class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> set(nums.begin(), nums.end());
        if(set.size()!=nums.size())return true;
        return false;
    }
};