//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    long long ExtractNumber(const std::string& sentence) {
        // code here
        std::stringstream ss(sentence);
        std::string word;
        std::vector<long long> numbers;

        while (ss >> word) {
            if (std::all_of(word.begin(), word.end(), ::isdigit)) {
                if (word.find('9') == std::string::npos) {
                    numbers.push_back(std::stoll(word));
                }
            }
        }

        if (numbers.empty()) {
            return -1;
        }

        return *std::max_element(numbers.begin(), numbers.end());
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
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends