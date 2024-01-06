//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	int sumOfPowers(int a, int b){
	    int i,j,ans=0,c=0;
	    for(i=a;i<=b;i++){
	        int n=i;
	        c=0;
	        while(n%2==0){
	            c++; n/=2;
	        }
	        for(j=3;j<=sqrt(n);j+=2){
	            while(n%j==0){
	                c++; n/=j;
	            }
	        }
	        if(n>2) ans++;
	        ans+=c;
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends