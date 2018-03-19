#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int numOfSteps = cost.size();
        vector<int> routeCost(numOfSteps);

        routeCost[0] = cost[0];
        routeCost[1] = cost[1];

        for(int i = 2; i < numOfSteps; i++) {
            if(i == numOfSteps - 1) {
                routeCost[i] = min(routeCost[i - 1], (routeCost[i - 2] + cost[i]) );
            } else {
                routeCost[i] = min( (routeCost[i - 1] + cost[i]), (routeCost[i - 2] + cost[i]) );
            }
        }

        return routeCost[numOfSteps - 1];
    }
};

int main(){
    Solution solution = Solution();
    vector<int> cost = {10,15,20};
    cout<<solution.minCostClimbingStairs(cost)<<endl;
}