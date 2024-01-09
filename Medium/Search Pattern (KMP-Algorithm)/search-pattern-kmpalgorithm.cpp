//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            vector<int>indices;
            // int i,j,n=txt.size(),k=pat.size();
            // string s="";
            // for(i=0;i<k;i++) s+=txt[i];
            // j=0;
            // for(i=k;i<n;i++){
            //     if(s==pat) ans.push_back(j+1);
            //     s.erase(s.begin());
            //     j++;
            //     s+=txt[i];
            // }
            // if(s==pat) ans.push_back(j+1);
            // return ans;
             int n = txt.length();
        int m = pat.length();

        for (int i = 0; i <= n - m; ++i) {
            int j;
            for (j = 0; j < m; ++j) {
                if (txt[i + j] != pat[j]) {
                    break;
                }
            }
            if (j == m) {
                indices.push_back(i + 1);
            }
        }

        return indices;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends