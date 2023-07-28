//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        
        vector<int> adj[N];
        for( auto &vect : edges)
        {
            int u = vect[0];
            int v = vect[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector <int> dist(N, -1);
        dist[src] = 0;
        queue<int> Q;
        Q.push(src);
        
        while(!Q.empty())
        {
            int node = Q.front();
            Q.pop();
            
            for( auto it : adj[node])
            {
                if(dist[it] == -1)
                {
                    dist[it] = dist[node] + 1;
                    Q.push(it);
                }
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends