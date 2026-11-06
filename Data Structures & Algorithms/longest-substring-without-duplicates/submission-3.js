class Solution {
    /**
     * @param {string} s
     * @return {number}
     */
    lengthOfLongestSubstring(s) {
        const set = new Set();
        let left = 0;
        let maxLength = 0;
        for(let i = 0; i<s.length;i++){
            while(set.has(s[i])){
                set.delete(s[left]);
                left++;
            }
            maxLength = Math.max(maxLength, i-left+1);
            set.add(s[i]);
        }
        return maxLength;
    }
}
