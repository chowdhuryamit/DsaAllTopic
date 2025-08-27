// User function Template for C++
#include<bits/stdc++.h>
using namespace std;

class disjointSet{
    vector<int>rank,parent,size;
    public:
    disjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findUltimateParent(int node){
        if(node==parent[node]){
            return node;
        }
        else{
            return parent[node] = findUltimateParent(parent[node]);
        }
    }
    
    void unoinByRank(int u,int v){
        int ulp_u=findUltimateParent(u);
        int ulp_v=findUltimateParent(v);
        if(ulp_u==ulp_v){
            return;
        }
        else{
            if(rank[ulp_u]<rank[ulp_v]){
                parent[ulp_u]=ulp_v;
            }
            else if(rank[ulp_v]<rank[ulp_u]){
                parent[ulp_v]=ulp_u;
            }
            else{
                parent[ulp_v]=ulp_u;
                rank[ulp_u]++;
            }
        }
    }

    void unionBySize(int u,int v){
        int ulp_u=findUltimateParent(u);
        int ulp_v=findUltimateParent(v);
        if(ulp_u==ulp_v){
            return;
        }
        else{
            if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }
            else{
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }
    }
};

class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        vector<pair<int,pair<int,int>>>edgeList;
        for(int i=0;i<edges.size();i++){
            edgeList.push_back({edges[i][2],{edges[i][0],edges[i][1]}});
        }
        int sum=0;
        sort(edgeList.begin(),edgeList.end());
        disjointSet ds(V);
        for(int i=0;i<edgeList.size();i++){
            int wt=edgeList[i].first;
            int u=edgeList[i].second.first;
            int v=edgeList[i].second.second;
            if(ds.findUltimateParent(u)!=ds.findUltimateParent(v)){
                sum+=wt;
                ds.unoinByRank(u,v);
            }
        }
        return sum;
    }
};