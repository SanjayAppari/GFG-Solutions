//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    unordered_map<int,int>m;
	    int i,ans=0,s=arr[0],r=0;
	    for(i=0;i<n;i++){
	        s=r+arr[i];
	        r=s%k;
	        if(r==0) ans=i+1;
	        if(r<0) r+=k;
	        if(m.find(r)!=m.end()){
	            ans=max(ans,i-m[r]+1);
	        }
	        else{
	            m[r]=i+1;
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends