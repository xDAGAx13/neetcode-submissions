class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if(len(s)!=len(t)):return False
        need = [0]*26
        check = [0]*26
        for i in range(len(s)):
            need[ord(s[i])-ord('a')]+=1
            check[ord(t[i])-ord('a')]+=1
        return need==check
        
        