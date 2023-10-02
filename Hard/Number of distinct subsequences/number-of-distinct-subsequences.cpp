//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    int n=s.length(),i;
	    unordered_map<char,int>m;
	    vector<int>dp(n+1);
	    dp[0]=1;
	    for(i=1;i<=n;i++){
	        dp[i]=(2*dp[i-1])%1000000007;
	        if(m[s[i-1]]){
	            dp[i]=(dp[i]-dp[m[s[i-1]]-1] + 1000000007)%1000000007;
	        }
	        m[s[i-1]]=i;
	    }
	    return dp[n];
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends