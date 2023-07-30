//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int m = int(1e9 + 7);
    int countPartitions(int n, int d, vector<int>& arr) {
        
        // solving using tabulation
        
        int totSum = accumulate(arr.begin(), arr.end(), 0);
        
        // s2 = (totSum - d)/2
        
        if( totSum -d  < 0 ) return 0;
        
        if( (totSum -d) % 2 == 1 ) return 0;
        
        int s2 = (totSum-d)/2;
        
        vector<vector<int>> dp(n, vector<int> (s2+1, 0));
        
        if( arr[0] == 0) dp[0][0] = 2;
        
        else dp[0][0] = 1;
        
        if( arr[0] <= s2 && arr[0] != 0) // we have only handled for arr[0] = 0
        {
            dp[0][arr[0]] = 1;
        }
        
        for( int i = 1; i < n; i++)
        {
            for( int tar = 0; tar <=s2; tar++)
            {
                int notPick = dp[i-1][tar];
                int pick = 0;
                if( arr[i] <= tar)
                {
                    pick = dp[i-1][tar-arr[i]];
                }
                
                dp[i][tar] = (pick + notPick ) %m;
            }
        }
        return dp[n-1][s2];
            
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