//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int>dfsPath;
    
    void dfs(int node , vector<int>adj[] , vector<int>& vis){
      
       vis[node]=1;
       dfsPath.push_back(node);
       for(auto it : adj[node]){
           if(!vis[it]) dfs(it,adj,vis);
       }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
            }
        }
        return dfsPath;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends