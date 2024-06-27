//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool isToeplitz(vector<vector<int>> &mat);

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }

        bool b = isToeplitz(a);

        if (b == true)
            cout << "true";
        else
            cout << "false";

        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

bool isToeplitz(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int startRow = rows - 1; startRow >= 0; --startRow) {
        int val = matrix[startRow][0];
        for (int r = startRow, c = 0; r < rows && c < cols; ++r, ++c) {
            if (matrix[r][c] != val) {
                return false;
            }
        }
    }

    for (int startCol = 1; startCol < cols; ++startCol) {
        int val = matrix[0][startCol];
        for (int r = 0, c = startCol; r < rows && c < cols; ++r, ++c) {
            if (matrix[r][c] != val) {
                return false;
            }
        }
    }

    return true;
}
