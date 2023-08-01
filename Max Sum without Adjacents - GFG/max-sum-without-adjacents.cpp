//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    
	    /* space optmimized solution
	    dp[i] = max( dp[i-1], dp[i-2] + arr[i])
	    to calculate any value of i we just need last two values.
	    */
	    int prev2 = 0;
	    int prev1 = arr[0];
	    
	    for( int i = 1; i < n; i++)
	    {
	        int currMax;
	        int pick = arr[i] + prev2;
	        int notPick = prev1;
	        currMax = max(pick, notPick);
	        prev2 = prev1;
	        prev1 = currMax;
	    }
	    return prev1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends