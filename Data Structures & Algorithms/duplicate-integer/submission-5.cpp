class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> my_set(nums.begin(), nums.end());
        if(my_set.size()<(int)nums.size()) return true;
        return false;
    }
};