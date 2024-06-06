//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
        // Your code here
        long long sumAll = 0;
        long long currVal = 0;
        for (int i = 0; i < n; ++i) {
            sumAll += a[i];
            currVal += i * (long long)a[i];
        }
        
        long long maxVal = currVal;
        
        for (int i = 1; i < n; ++i) {
            currVal = currVal + sumAll - n * (long long)a[n - i];
            if (currVal > maxVal) {
                maxVal = currVal;
            }
        }
        
        return maxVal;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends