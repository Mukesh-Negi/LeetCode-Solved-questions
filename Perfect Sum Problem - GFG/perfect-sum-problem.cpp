//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
	    int m = 1e9 + 7;
	    // tabulation solution
	    vector <vector<int>> dp(n, vector<int> (sum+1, 0));
	    
	    dp[0][0] = 1;// if target is 0 it means we have already picked req. elements in subset.
	    
	    if(arr[0] <= sum)
	    {
	        /*
	        if value is 0 at 0th index then target can be achieved by 
	        both ways : picking & not-picking that element.
	        so we are doing dp[0][arr[0]]++ so that in case if arr[0]= 0 its value will
	        be updated to 2
	        */
	        
	        dp[0][arr[0]]++;
	    }
	    
	    // now we will fill the remaining rows using these rows.
	    for( int i = 1; i < n; i++)
	    {
	        for( int target = 0; target <= sum; target++)
	        {
	            int notPick = dp[i-1][target] %m;
	            int pick = 0;
	            if( arr[i] <= target)
	            {
	                pick = dp[i-1][target-arr[i]] %m;
	            }
	            dp[i][target] = pick + notPick;
	        }
	    }
	    return dp[n-1][sum] % m;
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