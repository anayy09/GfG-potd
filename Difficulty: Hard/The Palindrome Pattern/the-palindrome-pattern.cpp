//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool isPalindrome(const string& str) {
        string reversedStr = str;
        reverse(reversedStr.begin(), reversedStr.end());
        return reversedStr == str;
    }
    
    string pattern(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for (int r = 0; r < rows; r++) {
            string rowStr;
            for (int c = 0; c < cols; c++) {
                rowStr += (matrix[r][c] + '0');
            }
            if (isPalindrome(rowStr)) {
                return to_string(r) + " R";
            }
        }
        
        for (int c = 0; c < cols; c++) {
            string colStr;
            for (int r = 0; r < rows; r++) {
                colStr += (matrix[r][c] + '0');
            }
            if (isPalindrome(colStr)) {
                return to_string(c) + " C";
            }
        }
        
        return "-1";
    }

};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends