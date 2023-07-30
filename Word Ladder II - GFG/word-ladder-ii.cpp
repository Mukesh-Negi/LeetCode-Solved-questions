//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        
        // unordered set for faster search and deletion
        unordered_set <string> s(wordList.begin(), wordList.end());
        
        queue < vector<string>> Q;
        
        Q.push({beginWord});
        
        vector<string> usedOnLevel; // to store string used in a particular level
        
        usedOnLevel.push_back(beginWord);
        
        int level = 0;
        
        vector <vector<string>> ans;
        
        while( !Q.empty())
        {
            vector <string> v = Q.front();
            Q.pop();
            
            
            // deleting the nodes used in last level
            if( v.size() > level)
            {
                level++;
                for(auto str : usedOnLevel)
                {
                    s.erase(str);
                }
                usedOnLevel.clear();
            }
            
            string word = v.back();
            
            if( word == endWord)
            {
                if( ans.size() == 0) // 1st seq found will always be shortest transformation
                {
                    ans.push_back(v);
                }
                else if( v.size() == ans[0].size())
                {
                    ans.push_back(v);
                }
            }
            
            for( int i = 0; i < word.size(); i++)
            {
                char orig = word[i];
                for( char ch = 'a'; ch <='z'; ch++)
                {
                    word[i] = ch;
                    if( s.find(word) != s.end())
                    {
                        v.push_back(word);
                        Q.push(v);
                        usedOnLevel.push_back(word);
                        v.pop_back(); // if any other word is found it goes after last word
                    }
                    word[i] = orig;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends