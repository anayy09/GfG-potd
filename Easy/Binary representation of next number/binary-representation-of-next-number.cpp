//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        int n = s.size();
        bool carry = true;

        for (int i = n - 1; i >= 0 && carry; i--) {
            if (s[i] == '1') {
                s[i] = '0';
            } else {
                s[i] = '1';
                carry = false;
            }
        }

        if (carry) {
            s = '1' + s;
        }

        int start = 0;
        while (start < s.size() && s[start] == '0') {
            start++;
        }

        return s.substr(start);

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends