class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int,int> freq;
      for(int num:nums){
        freq[num]++;
      }
      priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min;
      for(auto& pair: freq){
        min.push({pair.second, pair.first});
        if(min.size()>k)min.pop();
      }
      vector<int> out;
      while(!min.empty()){
        out.push_back(min.top().second);
        min.pop();
      }
      return out;
    }
};