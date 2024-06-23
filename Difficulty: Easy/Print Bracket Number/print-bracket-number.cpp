//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        // Your code goes here
        std::vector<int> result;
        int count = 0;
        std::stack<int> s;
        
        for (char ch : str) {
            if (ch == '(') {
                count++;
                result.push_back(count);
                s.push(count);
            } else if (ch == ')') {
                if (!s.empty()) {
                    result.push_back(s.top());
                    s.pop();
                }
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;

        vector<int> ans = ob.bracketNumbers(s);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends