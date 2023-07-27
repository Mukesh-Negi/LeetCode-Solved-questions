//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    /*
	    let TotalSum be 10
	    if s1 = 1 then s2 will be = 9
	    if s1 = 2 then s2 will be = 8
	    if s1 = 3 then s2 will be = 7
	    if s1 = 4 then s2 will be = 6
	    if s1 = 5 then s2 will be = 5
	    
	    if s1 = 6 then s2 will be = 4
	    if s1 = 7 then s2 will be = 3
	    if s1 = 8 then s2 will be = 2
	    if s1 = 9 then s2 will be = 1
	    
	    we can see that after 5 there are pairs that are already considered
	    we know that as s1 + s2 = s. So even is we consider the half of the values of s1
	    we will cover all the cases.
	    */
	    
	    int totSum = accumulate(arr, arr+n, 0);
	    int k = totSum/2;
	    vector<vector<bool>> dp(n, vector<bool> (k+1, false));
	    
	    for( int i = 0; i < n; i++)
	    {
	        dp[i][0] = true;
	    }
	    if( arr[0] <= k) dp[0][arr[0]] = true;
	    
	    for( int i = 1; i < n; i++)
	    {
	        for( int target = 0; target <= k ; target++)
	        {
	            bool notPick = dp[i-1][target];
	            bool pick = false;
	            if( arr[i] <= target)
	            {
	                pick = dp[i-1][target-arr[i]];
	            }
	            dp[i][target] = pick || notPick;
	        }
	    }
	    
	    int mini = INT_MAX;
	    for( int t = 0; t <=k; t++)
	    {
	        if( dp[n-1][t] ==true)
	        {
	            int s1 = t;
	            int s2 = totSum-s1;
	            mini = min(mini,abs(s1-s2));
	        }
	    }
	    return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends