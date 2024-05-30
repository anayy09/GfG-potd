//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findWinner(int n, int x, int y) {
        // code here
        vector<bool> dp(n + 1, false);
        dp[0] = false;
        
        for (int i = 1; i <= n; ++i) {
            if (i >= 1 && !dp[i - 1]) dp[i] = true;
            else if (i >= x && !dp[i - x]) dp[i] = true;
            else if (i >= y && !dp[i - y]) dp[i] = true;
            else dp[i] = false;
        }
        return dp[n] ? 1 : 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        Solution obj;
        int res = obj.findWinner(n, x, y);

        cout << res << endl;
    }
}

// } Driver Code Ends