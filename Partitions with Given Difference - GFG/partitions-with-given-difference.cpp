//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    int m = 1e9 + 7;
    int f( int idx, int target, vector<int> &arr, vector <vector<int>> &dp)
    {
        if( idx == 0)
        {
            if( target == 0 && arr[0] == 0) return 2;
            
            if( target == 0) return 1;// target is 0 but arr[0] is not 0
            
            if( arr[0] == target) return 1;
            
            return 0;
        }
        
        if( dp[idx][target] != -1) return dp[idx][target];
        
        int notPick = f(idx-1, target, arr, dp);
        
        int pick = 0;
        
        if( arr[idx] <= target)
        {
            pick = f(idx-1, target-arr[idx], arr, dp);
        }
        
        return dp[idx][target] = (pick + notPick) % m;
    }
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        
        // using striver's approach
        
        /*
        s1 - s2 = d    && s1 > s2
        s1 + s2 = s
        s2 = (s - d)/2
        */
        
        int totSum = accumulate(arr.begin(), arr.end(), 0);
        // edge cases
        if( totSum - d < 0) return 0;
        
        if( (totSum - d) % 2 == 1) return 0;
        
        int target = (totSum-d)/2;
        
        vector <vector<int>> dp(n, vector<int>(target + 1, -1) );
        
        return  f(n-1,target, arr, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends