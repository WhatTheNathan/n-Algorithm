#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(m > 0 && n > 0) {
            // initialize
            vector<vector<int>> map(m, vector<int>(n));
            map[0][0] = grid[0][0];

            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    int downPolicy = INT_MAX;
                    int rightPolicy = INT_MAX;
                    if(j - 1 >= 0)
                        rightPolicy = map[i][j-1];
                    if(i - 1 >= 0)
                        downPolicy = map[i-1][j];
                    if( i || j)
                        map[i][j] = min(rightPolicy,downPolicy) + grid[i][j];
                }
            }
            return map[m-1][n-1];
        }
        return 0;
    }
};

int main(){
    Solution solution = Solution();
    vector<vector<int>> grid;

    vector<int> row = {1,3,1};
    grid.push_back(row);

    row = {1,5,1};
    grid.push_back(row);

//    row = {4,2,1};
//    grid.push_back(row);

    cout<<solution.minPathSum(grid)<<endl;
}