class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mylist = [[]]
        map = {}
        for str in strs:
            need = [0]*26
            for char in str:
                need[ord(char)-ord('a')]+=1
            need = tuple(need)
            if need not in map: map[need]=[]
            map[need].append(str)
        return list(map.values())


            


        