class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        out = [1]*len(nums)
        preFix = 1
        for i in range(len(nums)):
            if i>=1:
                preFix*=nums[i-1]
                out[i]*=preFix
        suffix = 1
        for i in range(len(nums), -1, -1):
            if i <len(nums)-1:
                suffix*=nums[i+1]
                out[i]*=suffix
            
        return out