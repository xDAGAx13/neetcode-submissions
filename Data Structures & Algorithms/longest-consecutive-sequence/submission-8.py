class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        myset = set(nums)
        maxLength = 0;
        for num in myset:
            if not num-1 in myset:
                length = 1
                while num+1 in myset:
                    length+=1
                    num+=1
                maxLength = max(maxLength, length)
        return maxLength
            




        