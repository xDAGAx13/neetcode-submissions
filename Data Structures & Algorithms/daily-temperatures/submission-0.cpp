class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      vector<int> result(temperatures.size(), 0);
      vector<int> stack;
      for(int i = 0;i<temperatures.size();i++){
        int count = 0;
        while(!stack.empty()&&temperatures[i]>temperatures[stack.back()]){
          int prev = stack.back();
          stack.pop_back();
          result[prev] = i-prev;
        }
        stack.push_back(i);
      }
      return result;
    }
};