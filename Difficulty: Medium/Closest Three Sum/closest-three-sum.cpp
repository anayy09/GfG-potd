//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> nums, int target) {
        // Your code goes here
        int closestDiff = INT_MAX;
        int closestSum = INT_MIN;
        
        sort(nums.begin(), nums.end());
        
        int totalNums = nums.size();
        
        for(int i = 0; i < totalNums - 2; i++) {
            int left = i + 1, right = totalNums - 1;
            int currentSum = 0;
            
            while(left < right) {
                currentSum = nums[i] + nums[left] + nums[right];
                int currentDiff = abs(target - currentSum);
                
                if(currentDiff == closestDiff) {
                    closestSum = max(currentSum, closestSum);
                } else if(currentDiff < closestDiff) {
                    closestSum = currentSum;
                    closestDiff = currentDiff;
                }
                
                if(currentSum < target) left++;
                else right--;
            }
        }
        
        return closestSum;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends