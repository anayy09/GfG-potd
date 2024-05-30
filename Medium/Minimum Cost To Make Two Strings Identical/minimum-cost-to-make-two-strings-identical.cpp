//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findMinCost(string x, string y, int costX, int costY) {
        // Your code goes here
        int lenX = x.length();
        int lenY = y.length();
        std::vector<std::vector<int>> dpTable(lenX + 1, std::vector<int>(lenY + 1, 0));
        
        for (int i = 1; i <= lenX; ++i) {
            dpTable[i][0] = i * costX;
        }
        for (int j = 1; j <= lenY; ++j) {
            dpTable[0][j] = j * costY;
        }
        
        for (int i = 1; i <= lenX; ++i) {
            for (int j = 1; j <= lenY; ++j) {
                if (x[i - 1] == y[j - 1]) {
                    dpTable[i][j] = dpTable[i - 1][j - 1];
                } else {
                    dpTable[i][j] = std::min(dpTable[i - 1][j] + costX, dpTable[i][j - 1] + costY);
                }
            }
        }
        
        return dpTable[lenX][lenY];
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;

        int costX, costY;
        cin >> costX >> costY;

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends