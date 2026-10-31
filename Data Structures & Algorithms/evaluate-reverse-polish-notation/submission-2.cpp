class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      unordered_set<string> operands = {"+", "-", "*", "/"};
       vector<int> stack;
       for(int i = 0;i<tokens.size();i++){
        if(operands.count(tokens[i])){
          int val2 = stack.back();
          stack.pop_back();
          int val1 = stack.back();
          stack.pop_back();
          int result = 0;
          if(tokens[i]=="+") result = val1+val2;
          else if(tokens[i]=="-")result = val1-val2;
          else if(tokens[i]=="*")result = val1*val2;
          else result = val1/val2;
          stack.push_back(result);
        }else{
          stack.push_back(stoi(tokens[i]));
        }
       }
       return stack.back();
    }
};