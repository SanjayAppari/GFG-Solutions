//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(vector<int>adj[],vector<int>&vis, vector<int>&pathVis,int src){
        vis[src]=1;
        pathVis[src]=1;
        for(auto i:adj[src]){
            if(vis[i]==0){
                if(dfs(adj,vis,pathVis,i)) return 1;
            }
            else if(pathVis[i]==1) return 1; 
        }
        pathVis[src]=0;
        return 0;
    }
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>vis(V+1,0),pathVis(V+1,0);
        int i,j;
        for(i=0;i<V;i++){
            if(vis[i]==0){
                if(dfs(adj,vis,pathVis,i)) return 1;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends