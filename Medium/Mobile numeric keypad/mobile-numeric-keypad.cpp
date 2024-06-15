//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long getCount(int n) {
        // Your code goes here
        if (n == 1) return 10;

        long long dp[26][10] = {0};

        for (int i = 0; i < 10; i++) {
            dp[1][i] = 1;
        }

        int adj[10][5] = {
            {0, 8, -1, -1, -1},   // from 0
            {1, 2, 4, -1, -1},    // from 1
            {2, 1, 3, 5, -1},     // from 2
            {3, 2, 6, -1, -1},    // from 3
            {4, 1, 5, 7, -1},     // from 4
            {5, 2, 4, 6, 8},      // from 5
            {6, 3, 5, 9, -1},     // from 6
            {7, 4, 8, -1, -1},    // from 7
            {8, 0, 5, 7, 9},      // from 8
            {9, 6, 8, -1, -1}     // from 9
        };

        for (int len = 2; len <= n; len++) {
            for (int digit = 0; digit < 10; digit++) {
                dp[len][digit] = 0;
                for (int k = 0; k < 5; k++) {
                    if (adj[digit][k] != -1) {
                        dp[len][digit] += dp[len - 1][adj[digit][k]];
                    }
                }
            }
        }

        long long totalSeq = 0;
        for (int digit = 0; digit < 10; digit++) {
            totalSeq += dp[n][digit];
        }

        return totalSeq;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends