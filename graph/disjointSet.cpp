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
int main(){
    // disjointSet ds(7);
    // ds.unoinByRank(1,2);
    // ds.unoinByRank(2,3);
    // ds.unoinByRank(4,5);
    // ds.unoinByRank(6,7);
    // ds.unoinByRank(5,6);
    // if(ds.findUltimateParent(3)==ds.findUltimateParent(7)){
    //     cout<<"same"<<endl;
    // }
    // else{
    //     cout<<"not same"<<endl;
    // }
    // ds.unoinByRank(3,7); 
    // cout<<"after adding 3 and 7"<<endl;
    // if(ds.findUltimateParent(3)==ds.findUltimateParent(7)){
    //     cout<<"same"<<endl;
    // }
    // else{
    //     cout<<"not same"<<endl;
    // }

    disjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    if(ds.findUltimateParent(3)==ds.findUltimateParent(7)){
        cout<<"same"<<endl;
    }
    else{
        cout<<"not same"<<endl;
    }
    ds.unionBySize(3,7); 
    cout<<"after adding 3 and 7"<<endl;
    if(ds.findUltimateParent(3)==ds.findUltimateParent(7)){
        cout<<"same"<<endl;
    }
    else{
        cout<<"not same"<<endl;
    }
    return 0;
}