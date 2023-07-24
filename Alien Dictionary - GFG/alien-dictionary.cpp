//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        /*
        each  group of word of dictionary is giving us some relation between order of charachter.
        */
        
        // converting this problem to graph problem : so that we can use topo sort concept
        vector <int> adj[K];
        
        for( int i = 0; i < N-1; i++)
        {
                string s1 = dict[i];
                string s2 = dict[i+1];
                for( int m = 0; m < s1.size() && m < s2.size(); m++)
                {
                    if( s1[m] != s2[m]) // it means s1[m] should come before s2[m]
                    {
                        // s1[m] -> s2[m]
                        int c1 = s1[m] - 97;
                        int c2 = s2[m] - 97;
                        adj[c1].push_back(c2);
                        break;
                    }
                }
        }
        
        // now we will perfrom topo-sort
        vector<int> inDeg(K, 0);
        for( int i = 0; i < K; i++)
        {
            for(auto it : adj[i])
            {
                inDeg[it]++;
            }
        }
        
        queue<int> Q;
        for( int i = 0; i < K; i++)
        {
            if( inDeg[i] == 0) Q.push(i);
        }
        string ans;
        while(!Q.empty())
        {
            int node = Q.front();
            Q.pop();
            ans.push_back(node+97);
            
            for( auto it : adj[node])
            {
                inDeg[it]--;
                if( inDeg[it] == 0)
                {
                    Q.push(it);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends