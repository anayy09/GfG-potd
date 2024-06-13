//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int padovanSequence(int n)
    {
       //code here
       int MOD = 1000000007;
       if ( n == 0 || n == 1 || n == 2){
           return 1;
       }
       
       int pPrevPrev = 1, pPrev = 1, pCurr = 1, pNext = 1;
       for (int i = 3 ; i <= n ; i++)
       {
           pNext = (pPrevPrev + pPrev) % MOD;
           pPrevPrev = pPrev;
           pPrev = pCurr;
           pCurr = pNext;
       }
       return pNext;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout<<ob.padovanSequence(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends