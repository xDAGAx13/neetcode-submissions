class Solution {
    /**
     * @param {number[]} nums
     * @param {number} k
     * @return {number[]}
     */
    topKFrequent(nums, k) {
        const count = new Map();
        for(const x of nums){
            count.set(x, (count.get(x)??0)+1);
        }
        const buckets = Array.from({length:nums.length+1},()=>[]);
        for(const [x,c] of count){
            buckets[c].push(x);
        }
        const out = [];
        for(let i = buckets.length-1; i>=0 && out.length<k;i--){
            out.push(...buckets[i]);
        }
        return out.slice(0,k)
    }
}
