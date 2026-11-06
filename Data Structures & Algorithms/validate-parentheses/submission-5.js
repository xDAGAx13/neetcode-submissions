class Solution {
    /**
     * @param {string} s
     * @return {boolean}
     */
    isValid(s) {
        const m = new Map([
            ['{', '}'],
            ['[', ']'],
            ['(', ')'],
        ]);
        const stack = [];
        for(const ch of s){
            if(m.has(ch)){
                stack.push(ch);
            }else{
                if(stack.length==0 || m.get(stack.at(-1))!=ch)return false;
                stack.pop();
            }
        }
        return stack.length===0;
    }
}
