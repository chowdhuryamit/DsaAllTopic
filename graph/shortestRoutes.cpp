#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    unordered_map<int,list<pair<int,int>>>adjList;
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        adjList[u].push_back({v,w});
        adjList[v].push_back({u,w});
    }
    set<pair<int,int>>st;
    st.insert({0,1});
    vector<int>dist(n,INT_MAX);
    dist[0]=0;
    while(!st.empty()){
        auto topEle=*(st.begin());
        int node=topEle.second;
        int weight=topEle.first;
        st.erase(st.begin());
        for(auto nbr:adjList[node]){
            int nbrNode=nbr.first;
            int nbrWeight=nbr.second;
            if(dist[nbrNode-1]>weight+nbrWeight){
                auto result=st.find({dist[nbrNode-1],nbrNode});
                if(result!=st.end()){
                    st.erase(result);
                }
                dist[nbrNode-1]=weight+nbrWeight;
                st.insert({dist[nbrNode-1],nbrNode});
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
    }
    return 0;
}