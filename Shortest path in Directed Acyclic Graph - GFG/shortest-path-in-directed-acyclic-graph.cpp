//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    void dfsTopoSort(int src, vector <pair<int, int>> adj[],  vector<int> &visited,
    stack <int> &st)
    {
        visited[src] = 1;
        
        for( auto &pr : adj[src])
        {
            int v = pr.first;
            if(!visited[v])
            {
                dfsTopoSort(v, adj, visited, st);
            }
        }
        st.push(src);
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        
        // creating adjacency list for the given graph
        vector <pair<int, int>> adj[N];
        
        for( auto &vect : edges)
        {
            int u = vect[0];
            int v = vect[1];
            int wt = vect[2];
            adj[u].push_back({v, wt}); // u->v 
        }
        
        // step 1 : find the topological ordering
        stack <int> st; 
        vector <int> visited(N,0);
        for(int i = 0; i < N; i++)
        {
            if(!visited[i])
            {
                dfsTopoSort(i, adj, visited, st);
            }
        }
        
        vector<int> dist(N, INT_MAX);
        dist[0] = 0; // distance of src node will always be 0
        
        /*
        step 2 :->
        pop all the nodes till src node from stack bcz all the nodes before
        source node in topological ordering will be unreachable from source node
        */
        while( st.top() != 0) // 0 is the src node here for all the test cases
        {
            int val = st.top();
            dist[val] = -1;
            st.pop();
        }
        
        // step 3 : now relax edges one by one for adjacents of each node
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            
            // now relax its adjacent nodes
            for( auto &pr : adj[node])
            {
                int v = pr.first;
                int wt = pr.second;
                if( dist[node] + wt < dist[v])
                {
                    dist[v] = dist[node]+wt;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends