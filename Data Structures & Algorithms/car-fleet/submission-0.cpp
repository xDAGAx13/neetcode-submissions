class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> cars;
        for(int i = 0;i<speed.size();i++){
            double arrivalTime = (double) (target-position[i])/(double)speed[i];
            pair<int,double> newPair = {position[i], arrivalTime};
            cars.push_back(newPair);
        }
        sort(cars.begin(), cars.end());
        int result = 1;
        double earliestArrival = cars.back().second;
        for(int i = cars.size()-2;i>=0;i--){
            if(cars[i].second>earliestArrival){
                result++;
                earliestArrival=cars[i].second;
            }
        }
        return result;
    }
};
