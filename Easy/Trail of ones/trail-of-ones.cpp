//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int numberOfConsecutiveOnes(int n) {
        // code here
        const int MOD = 1e9 + 7;
        
        if (n == 0) return 0;
        
        long long dp0 = 1, dp1 = 1;
        
        for (int i = 2; i <= n; ++i) {
            long long new_dp0 = (dp0 + dp1) % MOD;
            long long new_dp1 = dp0 % MOD;
            dp0 = new_dp0;
            dp1 = new_dp1;
        }
        
        long long total = 1LL;
        for (int i = 0; i < n; ++i) {
            total = (total * 2) % MOD;
        }
        
        long long no_consecutive_ones = (dp0 + dp1) % MOD;
        
        long long with_consecutive_ones = (total - no_consecutive_ones + MOD) % MOD;
        
        return with_consecutive_ones;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends