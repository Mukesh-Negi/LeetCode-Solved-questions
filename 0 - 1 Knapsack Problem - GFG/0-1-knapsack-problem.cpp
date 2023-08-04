//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    private:
    int f(int idx, int wt[], int val[], int weight, vector<vector<int>> &dp)
    {
        // base case
        if( idx == 0)
        {
            if( wt[0] <= weight) // then we can pick 0th element in bag
            {
                return val[0];
            }
            
            else // we can't pick
            {
                return 0;
            }
            
        }
        
        if( dp[idx][weight] != -1) return dp[idx][weight];
        
        // we have two options for each index
        int notTake = 0 + f(idx-1, wt, val, weight, dp);
        int take = INT_MIN;
        if( wt[idx] <= weight)
        {
            take = val[idx] + f(idx-1, wt, val, weight-wt[idx], dp);
        }
        
        return dp[idx][weight] = max(take, notTake);
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        // solving using memoization
        
        vector < vector<int> > dp(n, vector <int> (W+1, -1));
        return f(n-1, wt, val, W, dp);
        
        /*
        f('i', 'w') represents max. value we can get from index 0 to index 'i' if capacity
        of bag is 'w'.
        */
 
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends