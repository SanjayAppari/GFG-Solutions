//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    #define mod 1000000007
 long long power(long long a,long long b)
    {
        if(a==1) return 1;
        if(b==0) return 1;
        if(b==1) return a;
        long long p=power(a,b/2)%mod;
        if(b&1) return (a%mod*p%mod*p%mod)%mod;
        return (p%mod*p%mod)%mod;
    }
    long long power(int N,int R)
    {
       long long r1=power(N,R)%mod;
       return r1%mod;
    }

};

//{ Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}
// } Driver Code Ends