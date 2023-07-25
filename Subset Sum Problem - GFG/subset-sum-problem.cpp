//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        
        // solving using tabulation
        
        int n = arr.size();
        
        vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
        
        //f(i, target) :-> represents if there is any subset from 0 to i with sum = target.
        
        // for any index i if target = 0 the value is true
        
        for( int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }
        
        // from index 0 only 1 subset can be formed 
        
        if(arr[0] <= sum)
        {
            dp[0][arr[0]] = true;
        }
        
        // now we have filled known values on the basis of this we will
        // unknown values
        for( int i = 1; i < n; i++) // this for loop represents indexes or array
        {
            for( int target = 0; target<= sum; target++) //all possible values of target for each index 
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
        return dp[n-1][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends