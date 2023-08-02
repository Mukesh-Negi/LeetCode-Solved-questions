//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    int f(int day, int next, vector<vector<int>> &points, vector<vector<int>> &dp)
    {
        // base case
        if( dp[day][next] != -1) return dp[day][next];
        
        if( day == 0)
        {
            int maxi = INT_MIN;
            for( int i = 0; i <=2; i++)
            {
                if( i != next)
                {
                    maxi = max( maxi, points[day][i] );
                }
            }
            return dp[0][next] =  maxi;
        }
        
        
        int maxi = INT_MIN;
        for( int act = 0; act <=2; act++)
        {
            if( act != next)
            {
                int pt = f(day-1, act, points, dp) + points[day][act];
                maxi = max(maxi, pt);
            }
        }
        return dp[day][next] = maxi;
    }
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        
        // solving using memoization
        vector<vector<int>> dp(n, vector <int>(4, -1));
        
        return f(n-1, 3, points, dp); // passing 3 bcz we will have all 3 options on last day
        
        // f(d, i) : represents max. points till day 'd' if activity 'i' was selected
        // on next day.
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends