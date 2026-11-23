class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        myset = set()
        left=0
        maxLength = 0
        for i in range(len(s)):
            while s[i] in myset:
                myset.discard(s[left])
                left+=1
            myset.add(s[i])
            maxLength = max(maxLength, i-left+1)
        return maxLength
