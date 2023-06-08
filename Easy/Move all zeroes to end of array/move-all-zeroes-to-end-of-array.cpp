//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    int i=0,j;
	    while(i<n){
	        if(arr[i]==0){
	            break;
	        }
	        i++;
	    }
	    
	    j=i+1;
	    while(i<n && j<n){
	        if(arr[j]!=0){
	            swap(arr[i],arr[j]);
	            i++;
	        }
	        j++;
	    }
	    
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.pushZerosToEnd(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends