//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
  bool dfsCheck(int src, vector<int> adj[], int vis[], int pathVis[])
  {
      // step 1: mark node visited and mark it on the current path
      vis[src] = 1;
      pathVis[src] = 1;
      
      // traversing for neighbouring nodes
      for( auto &it : adj[src])
      {
          // if it is not visited : make dfs call for it
          if( !vis[it])
          {
              if( dfsCheck(it, adj, vis, pathVis) == true ) return true;
          }
          // if it is visited check if it is visited on the same path
          else if( pathVis[it]) return true;
      }
      // before moving back we will unmark the node from current path
      pathVis[src] = 0;
      return false;
      
  }
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V] = {0}; //to keep track of visited node in traversal
        
        int pathVis[V] = {0};// to keep track of visited node in the current path
        
        for( int i = 0; i < V; i++)
        {
            if( !vis[i])
            {
                if( dfsCheck(i, adj, vis, pathVis) == true) return  true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends