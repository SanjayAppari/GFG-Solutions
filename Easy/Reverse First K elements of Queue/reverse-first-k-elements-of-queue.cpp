//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
       queue<int>ans;
        stack<int>s;
        int i =0;
        
        while(k>0 && !q.empty()){
            int z = q.front();
            q.pop();
            s.push(z);
            k--;
        }
        while(s.size()>0){
            int z = s.top();
            s.pop();
            ans.push(z);
        }
        while(!q.empty()){
            int x = q.front();
            q.pop();
            ans.push(x);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends