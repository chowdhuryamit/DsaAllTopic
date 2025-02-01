//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int findMinNodeFromKeys(vector<int>& keys,vector<int>& mst){
        int temp=INT_MAX;
        int index=-1;
        for(int i=0;i<keys.size();i++){
            if(keys[i]<temp && mst[i]==false){
                temp=keys[i];
                index=i;
            }
        }
        return index;
    }
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<int>keys(V,INT_MAX);
        vector<int>mst(V,false);
        vector<int>parent(V,-1);
        
        keys[0]=0;
        
        while(true){
            int u=findMinNodeFromKeys(keys,mst);
            if(u==-1){
                break;
            }
            mst[u]=true;
            for(auto nbr:adj[u]){
                int v=nbr[0];
                int w=nbr[1];
                if(mst[v]==false && w<keys[v]){
                    keys[v]=w;
                    parent[v]=u;
                }
            }
        }
        
        int sum=0;
        for(int i=0;i<parent.size();i++){
            if(parent[i]==-1){
                continue;
            }
            else{
                for(auto nbr:adj[i]){
                    int v=nbr[0];
                    int w=nbr[1];
                    if(v==parent[i]){
                        sum+=w;
                    }
                }
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends