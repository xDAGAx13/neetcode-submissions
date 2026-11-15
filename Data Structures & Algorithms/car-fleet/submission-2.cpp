class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> cars;
        for(int i = 0; i<speed.size();i++){
            double arrivalTime = (double) (target-position[i])/(double)speed[i];
            cars.push_back({position[i], arrivalTime});
        }
        sort(cars.begin(), cars.end());
        double earliestArrival = cars.back().second;
        int numFleets = 1;
        for(int i = cars.size()-2; i>=0;i--){
            if(cars[i].second>earliestArrival){
                numFleets++;
            earliestArrival = cars[i].second;
            }
        }
        return numFleets;
    }
};
