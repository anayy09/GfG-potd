//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        stack<int> st;
        long long maxArea = 0;

        for (int i = 0; i <= n; ++i) {
            while (!st.empty() && (i == n || arr[st.top()] >= arr[i])) {
                long long height = arr[st.top()];
                st.pop();
                long long width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, width * height);
            }
            st.push(i);
        }

        return maxArea;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends