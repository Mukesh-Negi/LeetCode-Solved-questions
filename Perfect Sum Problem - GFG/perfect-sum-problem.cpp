//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
	    int m = 1e9 + 7;
	    // space optimized solution
	    // in order to find the value of any row we just need values of previous row
	    vector<int> prev(sum+1, 0);
	    prev[0] = 1;
	    
	    if( arr[0] <= sum) prev[arr[0]]++;
	    
	    for( int i = 1; i < n; i++)
	    {
	        vector <int> curr(sum+1, 0);
	        for( int target = 0; target <= sum; target++)
	        {
	            int notPick = prev[target] %m;
	            int pick = 0;
	            if( arr[i] <= target)
	            {
	                pick = prev[target-arr[i]] %m;
	            }
	            curr[target] = pick + notPick;
	        }
	        prev = curr;
	    }
	    return prev[sum] % m;
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