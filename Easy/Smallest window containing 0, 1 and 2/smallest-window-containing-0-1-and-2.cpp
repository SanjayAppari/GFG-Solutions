//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string s) {
        // Code here
        int i=0,j=0,n=s.length(),o=0,t=0,z=0;
        int ans=INT_MAX;
        while(i<n){
            if(s[i]=='1') o++;
            else if(s[i]=='2') t++;
            else z++;
            
            while(o>0 && t>0 && z>0){
                ans=min(ans,i-j+1);
                if(s[j]=='1') o--;
                else if(s[j]=='2') t--;
                else z--;
                j++;
            }
            i++;
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends