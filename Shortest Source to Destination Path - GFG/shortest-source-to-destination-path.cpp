//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        
        // edge cases
        if( A[0][0] == 0) return -1;
        
        // each cell of the matrix can be considered as the vertex of the graph
        
        queue < pair <pair<int,int>, int>> Q; // { {row, col} , steps}
        
        Q.push( {{0, 0}, 0});
        
        vector <vector<int>> visited(N, vector<int>(M, 0));
        
        int dRow[] = {-1, 0, 0, +1 };
        int dCol[] = {0, -1, +1, 0 };
        
        while( !Q.empty())
        {
            int r = Q.front().first.first;
            int c = Q.front().first.second;
            int step = Q.front().second;
            Q.pop();
            
            if(r == X && c == Y)
            {
                return step;
            }
            for( int i = 0; i < 4; i++)
            {
                int nRow = r + dRow[i];
                int nCol = c + dCol[i];
                
                if( nRow >= 0 && nRow < N && nCol >=0 && nCol < M&& A[nRow][nCol] == 1
                && !visited[nRow][nCol])
                {
                    visited[nRow][nCol] = 1;
                    Q.push( {{nRow, nCol}, step+1});
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends