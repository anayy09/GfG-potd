//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        long long sumA = 0, sumB = 0;
        for (int i = 0; i < n; i++) sumA += a[i];
        for (int i = 0; i < m; i++) sumB += b[i];
        
        long long diff = sumA - sumB;
        if (diff % 2 != 0) return -1;
        
        diff /= 2;
        
        std::sort(b, b + m);
        
        for (int i = 0; i < n; i++) {
            int target = a[i] - diff;
            if (std::binary_search(b, b + m, target)) {
                return 1;
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends