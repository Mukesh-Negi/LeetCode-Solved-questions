//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    private:
    void insertAtBottom(stack <int> &st, int x)
    {
        
        
        if( st.empty())
        {
            st.push(x);
            return ;
        }
        
        int t = st.top();
        st.pop();
        insertAtBottom(st,x);
        st.push(t);
    }
public:
    void Reverse(stack<int> &St){
        
      // here we will use rcn. stack space to reverse the stack using rcn.
      if(!St.empty())
      {
          int t = St.top();
          
          St.pop();
          
          Reverse(St);
          
          insertAtBottom(St, t);
      }
        
        return;
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends