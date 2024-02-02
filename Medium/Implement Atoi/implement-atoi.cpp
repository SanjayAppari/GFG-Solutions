//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        int i,r=0,c=0;
        if(s[0]=='-') {
            c=1; s=s.substr(1);
        }
        for(auto i:s){
            if(i>='0' && i<='9') {
                r=r*10+(i-48);
            }
            else return -1;
        }
        if(c==1) r=r*(-1);
        return r;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends