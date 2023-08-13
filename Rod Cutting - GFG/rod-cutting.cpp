//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        
        // space opimization using single row
        
        vector <int> prev(n+1, 0);
        
        for( int len = 0; len <= n; len++)
        {
            prev[len] = price[0]*len;
        }
        
        for( int i = 1; i < n; i++)
        {
            for( int len = 1; len <= n; len++)
            {
                int notTake = 0 + prev[len];
                
                int take = 0;
                
                int currLen = i+1;
                
                if( currLen <= len)
                {
                    take = price[i] + prev[len - currLen];
                }
                prev[len] = max(take, notTake);
            }
        }
        return prev[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends