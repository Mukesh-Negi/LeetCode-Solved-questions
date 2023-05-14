//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph using dfs
    bool dfsCheck(int src, int parent, vector<bool> &visited, vector<int> adj[])
    {
        visited[src] = 1;
        for( auto &val : adj[src])
        {
            if(!visited[val])// if NOT visisted simply visit it
            {
                // if cycle is found no need to check further
                if( dfsCheck(val, src, visited, adj) == true) return true;
            }
            else // it means the node is already visited
            {
                // if visited node is not parent it means cycle is present in graph
                if(val != parent) return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // cycle detection using dfs traversal
        vector<bool> visited (V,0);
        for( int i = 0; i < V; i++)
        {
            if(!visited[i])
            {
                if( dfsCheck(i, -1, visited, adj) == true)
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends