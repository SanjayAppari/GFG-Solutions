//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:
	void leftRotate(int arr[], int k, int n) 
	{ 
	    vector<int>v;
	    k=k%n;
	    int i,j=k;
	   // cout<<k<<" ";
	    for(i=0;i<k;i++){
	        v.push_back(arr[i]);
	    }
	    for(i=0;i<n-k;i++){
	        arr[i]=arr[j];
	        j++;
	    }
	    j=0;
	    for(i=n-k;i<n;i++){
	        arr[i]=v[j]; 
	        j++;
	    }
	} 
		 

};

//{ Driver Code Starts.

int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin >> n;
	    int k;
	    cin >> k;
	    int a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	        // um[a[i]]++;
	    }


       

        Solution ob;
        ob.leftRotate(a,k,n);
        
        for (int i = 0; i < n; i++) 
        	cout << a[i] << " "; 

	    cout << "\n";
	     
    }
    return 0;
}



// } Driver Code Ends