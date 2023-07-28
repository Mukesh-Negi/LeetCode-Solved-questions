//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int m = 1e9 + 7;
    int f( int idx, int arr[], int target, vector <vector<int>> &dp)
    {
        if( idx == -1)
        {
            if( target == 0) return 1;
            return 0;
        }
        
        if( dp[idx][target] != -1) return dp[idx][target];
        
        int notPick = f(idx-1, arr, target, dp) % m;
        int pick = 0;
        if( arr[idx] <= target) 
        {
            pick = f(idx-1, arr, target-arr[idx], dp) %m;
        }
        
        return dp[idx][target] =  pick + notPick;
    }
	public:
	int perfectSum(int arr[], int n, int sum)
	{
	    vector <vector<int>> dp(n, vector<int> (sum+1, -1));
	    int ans = f(n-1, arr, sum, dp);
	    ans %= m;
	    return ans;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends