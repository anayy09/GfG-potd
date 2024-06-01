//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        // code here
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        int x = 0, y = 0;
        for (int i = 0; i < 26; ++i) {
            char c = 'a' + i;
            int position = i + 1; 
            
            if (position % 2 == 0) {
                if (freq[i] > 0 && freq[i] % 2 == 0) {
                    x++;
                }
            } else {
                if (freq[i] > 0 && freq[i] % 2 == 1) {
                    y++;
                }
            }
        }

        return (x + y) % 2 == 0 ? "EVEN" : "ODD";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends