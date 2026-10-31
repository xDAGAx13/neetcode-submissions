class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      vector<int> out(nums.size(), 1);
      int preFix = 1;
      for(int i = 1;i<nums.size();i++){
        preFix*=nums[i-1];
        out[i]=preFix;
      }
      int suffix = 1;
      for(int i = nums.size()-2;i>=0;i--){
        suffix*=nums[i+1];
        out[i]*=suffix;
      }
      return out;
    }
};