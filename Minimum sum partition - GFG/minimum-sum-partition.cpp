//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    
	    int totSum = accumulate(arr, arr+n, 0);
	    /*
	    :-> we need to minimize |s1-s2|
	    :-> possible values of s1 will be in range 0 to totSum.
	    :-> if we find if there exist subset with sum = totSum. we will also have values for
	    subsets with sum = 0, 1, 2......totSum-1 in tabulation table.
	   */
	   
	   // now we will use same method that we used in subset-sum problem
	   vector<vector<bool>> dp(n, vector<bool> (totSum+1, false));
	   
	   int k = totSum;
	   for( int i = 0; i < n; i++)
	   {
	       dp[i][0] = true;
	   }
	   
	   if( arr[0] <= k) dp[0][arr[0]] = true;
	   
	   for( int i = 1; i < n; i++)
	   {
	       for(int target = 1; target <= k; target++)
	       {
	           bool notPick = dp[i-1][target];
	           bool pick = false;
	           if(arr[i] <= target)
	           {
	               pick = dp[i-1][target- arr[i]];
	           }
	           
	           dp[i][target] = pick || notPick;
	       }
	   }
	   
	   // in last row dp we have calculated results for all possible values of s1.
	   int mini = INT_MAX;
	   for( int i = 0; i <=k; i++)
	   {
	       if(dp[n-1][i] == true)
	       {
	           int s1 = i;
	           int s2 = totSum-i;
	           mini = min(mini, abs(s1-s2));
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