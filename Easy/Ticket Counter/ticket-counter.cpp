//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int n, int k) {
        int i=0,j=n,c=0;
        while(n>0){
            if(c==0){
                if(n>=k){ i=i+k;}
                else return i+n;
                c=1;
            }
            else{
                if(n>=k) j-=k-1;
                else return  i+1;
                c=0;
            }
            n-=k;
        }
        if(c==1)
        return i;
        return i+1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends