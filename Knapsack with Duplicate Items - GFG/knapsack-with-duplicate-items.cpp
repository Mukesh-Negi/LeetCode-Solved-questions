//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // space optimization using single array
        
        vector <int> prev(W+1, 0);
        
        for( int cap = 0; cap <=W; cap++)
        {
            prev[cap] = val[0] * (cap/wt[0]);
        }
        
        for( int i = 1; i < N; i++)
        {
            for( int cap = 1; cap <= W; cap++)
            {
                int notTake = 0 +  prev[cap];
                
                int take = 0;
                
                if( wt[i] <= cap)
                {
                    take = val[i] + prev[cap - wt[i]];
                }
                
                prev[cap] = max(take, notTake);
            }
        }
        return prev[W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends