//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    
	    int fun(int n,vector<int>&dp){
	        if(dp[n]!=-1) return dp[n];
	        if(n==0 || n==1) return 1;
	        return dp[n] = (fun(n-1,dp)%1000000007+fun(n-2,dp)%1000000007)%1000000007;
	    }
	
		int nthPoint(int n){
		   vector<int>dp(n+1,-1);
		   return fun(n,dp);
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends