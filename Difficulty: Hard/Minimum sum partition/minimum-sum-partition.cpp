//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    bool subsetSum(int arr[], int n, vector<vector<bool>>& dp, int sum) {
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        for (int j = 1; j <= sum; j++) {
            dp[0][j] = false;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][sum];
    }

    int minDifference(int arr[], int n) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }

        vector<vector<bool>> dp(n + 1, vector<bool>(sum / 2 + 1, false));
        subsetSum(arr, n, dp, sum / 2);

        int minDiff = INT_MAX;
        for (int i = 0; i <= sum / 2; i++) {
            if (dp[n][i]) {
                minDiff = min(minDiff, sum - 2 * i);
            }
        }
        return minDiff;
    }
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends