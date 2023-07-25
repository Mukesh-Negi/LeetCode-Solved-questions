//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        
        // space- optimiezed solution
        
        int n = arr.size();
        
        vector<bool> prev(sum+1, false);
        
        prev[0] = true;
        
        if(arr[0] <= sum)
        {
            prev[arr[0]] = true;
        }
        
        for( int i = 1; i < n; i++)
        {
            vector<bool> curr(sum+1, false);
            for( int target = 0; target <= sum; target++)
            {
                bool notTake = prev[target];
                
                bool take = false;
                
                if( arr[i] <= target)
                {
                    take = prev[target-arr[i]];
                }
                
                curr[target] = take || notTake;
            }
            prev = curr;
        }
        return prev[sum];
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