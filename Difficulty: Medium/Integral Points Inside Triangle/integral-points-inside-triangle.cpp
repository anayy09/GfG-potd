//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  long long gcd(long long a, long long b) {
    //   code here
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    long long InternalCount(long long p[], long long q[], long long r[]) {
        // Calculate the area of the triangle using the determinant method
        long long area = 0;
        area += (p[0] * q[1]) - (p[1] * q[0]);
        area += (q[0] * r[1]) - (q[1] * r[0]);
        area += (r[0] * p[1]) - (r[1] * p[0]);

        // Calculate the number of boundary points using gcd
        long long boundaryPoints = 0;
        boundaryPoints += gcd(abs(p[0] - q[0]), abs(p[1] - q[1]));
        boundaryPoints += gcd(abs(r[0] - q[0]), abs(r[1] - q[1]));
        boundaryPoints += gcd(abs(p[0] - r[0]), abs(p[1] - r[1]));

        // Use Pick's Theorem to find the number of interior points
        return abs(area) / 2 - boundaryPoints / 2 + 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int p[2], q[2], r[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1];
        Solution ob;
        long long int ans = ob.InternalCount(p, q, r);
        cout << ans << "\n";
    }
}
// } Driver Code Ends