//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
  bool dfsCheck(int src, vector<int> adj[], int vis[])
  {
      // step 1: mark node visited and mark it on the current path
      vis[src] = 1;
      vis[src]++;
      
      // traversing for neighbouring nodes
      for( auto &it : adj[src])
      {
          // if it is not visited : make dfs call for it
          if( !vis[it])
          {
              if( dfsCheck(it, adj, vis) == true ) return true;
          }
          // if it is visited check if it is visited on the same path
          else if( vis[it] == 2) return true;
      }
      // before moving back we will unmark the node from current path
      vis[src]--;
      return false;
      
  }
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // using only 1 array for keeping track of visited and 
        // 0 -> unvisited
        // 1 -> visited but not on current path
        // 2 -> visited previosly on the current path
        int vis[V] = {0}; //to keep track of visited nodes and nodes in current path
        
        for( int i = 0; i < V; i++)
        {
            if( !vis[i])
            {
                if( dfsCheck(i, adj, vis) == true) return  true;
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