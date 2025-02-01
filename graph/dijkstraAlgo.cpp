#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
     unordered_map<int,list<pair<int,int>>>adjList;

    void addEdge(int u,int v,int wt,bool direction){
        if(direction ==0){
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
        else{
            adjList[u].push_back({v,wt});
        }
    } 

    void printAdiList(int n){
        for (int i = 0; i < n; i++)
        {
           cout<<i<<"->";
           list<pair<int,int>>l=adjList[i];
           for(auto j:l){
            cout<<"("<<j.first<<","<<j.second<<"),";
           }
           cout<<endl;
        }
        
    }

    void dijkstraAlgo(int src,int n){
       vector<int>dist(n,INT_MAX);
       set<pair<int,int>>st;
       dist[src]=0;
       st.insert({0,src});

       while(!st.empty()){
         auto topEle=*(st.begin());
         int topNodeDist=topEle.first;
         int topNode=topEle.second;
         st.erase(st.begin());
         for(auto nbr:adjList[topNode]){
            int nbrNode=nbr.first;
            int nbrWeight=nbr.second;
            if(dist[nbrNode]>nbrWeight+topNodeDist){
              auto result=st.find({dist[nbrNode],nbrNode});
              if(result!=st.end()){
                st.erase(result);
              }
              dist[nbrNode]=nbrWeight+dist[topNode];
              st.insert({nbrWeight+dist[topNode],nbrNode});
            }
         }
       }
       for(int i=0;i<dist.size();i++){
        cout<<dist[i]<<endl;
       }
    }


};
int main(){

    Graph g;
    g.addEdge(0,5,9,0);
    g.addEdge(0,3,6,0);
    g.addEdge(5,4,2,0);
    g.addEdge(5,1,14,0);
    g.addEdge(4,1,9,0);
    g.addEdge(4,2,10,0);
    g.addEdge(4,3,11,0);
    g.addEdge(1,2,7,0);
    g.addEdge(3,2,15,0);

    //g.printAdiList(6);
    g.dijkstraAlgo(0,6);



    return 0;
}