//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &a) {
        // code here
        if(a[0]==10 || a[0]==20) return 0;
        int i,j,c=0,f=0,t=0,tw=0;
        for(i=0;i<N;i++){
            if(a[i]==5){
                c+=5; f++;
            }
            else if(a[i]==10){
                if(f>0){
                    f--; c+=5; t++;
                }
                else return 0;
            }
            else if(a[i]==20){
                if(f>0 && t>0){
                    f--; t--;
                    c+=5; tw++;
                }
                else if(f>3){
                    f-=3;
                }
                else return 0;
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends