//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    bool check(int i,int j,int n){
        if(i>=0 && i<n && j>=0 && j<n) return 1;
        return 0;
    }
    void fun(int i,int j, vector<string>&ans,string s,int n,vector<vector<int>>&v,vector<vector<int>>&a){
        if(i==n-1 && j==n-1){
            ans.push_back(s);
            return ;
        }
        
        if(check(i+1,j,n)){
            if(v[i+1][j]==0 && a[i+1][j]==1){
                v[i][j]=1;
                fun(i+1,j,ans,s+'D',n,v,a);
                v[i][j]=0;
            } 
        }
        if(check(i,j-1,n)){
            if(v[i][j-1]==0 && a[i][j-1]==1){
                v[i][j]=1;
                fun(i,j-1,ans,s+'L',n,v,a);
                v[i][j]=0;
            }
        }
        if(check(i,j+1,n)){
            if(v[i][j+1]==0 && a[i][j+1]==1){
                v[i][j]=1;
                fun(i,j+1,ans,s+'R',n,v,a);
                v[i][j]=0;
            } 
        }
        if(check(i-1,j,n)){
            if(v[i-1][j]==0 && a[i-1][j]==1){
                v[i][j]=1;
                fun(i-1,j,ans,s+'U',n,v,a);
                v[i][j]=0;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
       vector<vector<int>>v(n,vector<int>(n,0));
       vector<string>ans;
       if(m[0][0]==1) fun(0,0,ans,"",n,v,m);
       return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends