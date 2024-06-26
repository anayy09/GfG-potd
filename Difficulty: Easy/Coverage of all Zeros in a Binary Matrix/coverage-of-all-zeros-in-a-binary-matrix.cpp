//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    int findCoverage(vector<vector<int>>& grid) {
        int coverage = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 0) {
                    if (r > 0 && grid[r - 1][c] == 1) coverage++;
                    if (r < rows - 1 && grid[r + 1][c] == 1) coverage++;
                    if (c > 0 && grid[r][c - 1] == 1) coverage++;
                    if (c < cols - 1 && grid[r][c + 1] == 1) coverage++;
                }
            }
        }
        return coverage;
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        int ans = obj.findCoverage(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends