//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minimumCostHelper(int n, int w, vector<int> &cost, vector<int> &memo) {
        // code here
        if (w == 0) return 0;
        if (w < 0) return INT_MAX;

        if (memo[w] != -1) return memo[w];

        int minCost = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if (cost[i] != -1 && w >= i + 1) {
                int subCost = minimumCostHelper(n, w - (i + 1), cost, memo);
                if (subCost != INT_MAX) {
                    minCost = min(minCost, subCost + cost[i]);
                }
            }
        }

        memo[w] = (minCost == INT_MAX) ? INT_MAX : minCost;
        return memo[w];
    }

    int minimumCost(int n, int w, vector<int> &cost) {
        vector<int> memo(w + 1, -1);
        int result = minimumCostHelper(n, w, cost, memo);
        return (result == INT_MAX) ? -1 : result;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}

// } Driver Code Ends