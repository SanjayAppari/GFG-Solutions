//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
    void fun(int i,vector<string>&ans,string S,int n){
        if(i>=n) {
            ans.push_back(S);
            return;
        }
        for(int j=i;j<n;j++){
            swap(S[i],S[j]);
            fun(i+1,ans,S,n);
            swap(S[i],S[j]);
        }
    }
    
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string>ans;
        string v="";
        int n=S.length();
        fun(0,ans,S,n);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends