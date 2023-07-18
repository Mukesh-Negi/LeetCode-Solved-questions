//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    void dfs(int bRow, int bCol, int r, int c, vector<vector<int>> &grid, 
    vector<vector<bool>> &visited, vector<pair<int, int>> &vp, int dRow[], int dCol[])
    {
        visited[r][c] = 1;
        vp.push_back({bRow-r,bCol-c});
        int n = grid.size();
        int m = grid[0].size();
        for( int i = 0; i < 4; i++)
        {
            int nRow = r + dRow[i];
            int nCol = c + dCol[i];
            if( nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 1 &&
            !visited[nRow][nCol])
            {
                dfs(bRow, bCol, nRow, nCol, grid, visited, vp, dRow, dCol);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // The main thing to learn from this ques is how can we store two shapes
        // so that we can compare and find out if they are similar or NOT.
        int n = grid.size();
        int m = grid[0].size();
        set <vector<pair<int, int>>> s;
        vector <vector<bool>> visited(n, vector<bool>(m, 0));
        vector < pair<int, int>> vp;
        int dRow[] = {-1, 0, 0, 1 };
        int dCol[]= { 0, 1, -1, 0 };
        for( int i = 0; i < n; i++)
        {
            for( int j = 0; j < m; j++)
            {
                if( grid[i][j] == 1 && !visited[i][j])
                {
                    dfs(i, j, i, j, grid, visited,vp, dRow, dCol);
                    s.insert(vp);
                    vp.clear();
                }
            }
        }
        int ans = s.size();
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends