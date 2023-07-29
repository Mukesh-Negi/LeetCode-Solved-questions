//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        
        
        // tabulation gives tle, let's try space optimization
        int m = 1e9 + 7;
        
        int totSum = accumulate(arr.begin(), arr.end(), 0);
        
        // dp matrix reresents : dp[idx][target]
        vector<int> prev(totSum+1, 0);
        
        prev[0] = 1;
        
        if( arr[0] <= totSum) prev[arr[0]]++;
        
        for( int i = 1; i < n; i++)
        {
            vector <int> curr(totSum+1, 0);
            for( int target = 0; target <=totSum; target++)
            {
                int  notPick = prev[target] % m;
                int pick = 0;
                if( arr[i] <= target)
                {
                    pick = prev[target-arr[i]] % m;
                }
                curr[target] = pick + notPick;
            }
            prev = curr;
        }
        
        // now in last row there will be true for possible values of s1
        int cnt = 0;
        for( int i = 0; i <=totSum; i++)
        {
            if(prev[i] != 0)
            {
                int tot = prev[i] % m ;
                int s1 = i ;
                int s2 = (totSum - i);
                if( (s1 >= s2) && (s1-s2 == d))
                {
                    cnt += tot;
                }
            }
        }
        return cnt%m;
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