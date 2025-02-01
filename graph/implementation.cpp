#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
     map<int,list<int>>adjList;

     void addEdge(int u,int v,bool isDirected){
        if(isDirected==0){
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        else{
            adjList[u].push_back(v);
        }
     }

     void printAdiList(int n){
        // for(auto i:adjList){
        //     cout<<i.first<<"->";
        //     for(auto j:i.second){
        //         cout<<j<<",";
        //     }
        //     cout<<endl;
        // }

        for (int i = 0; i < n; i++)
        {
           cout<<i<<"->";
           list<int>l=adjList[i];
           for(auto j:l){
            cout<<j<<" ";
           }
           cout<<endl;
        }
        
     }

};
int main(){
    Graph g;
    g.addEdge(0,1,1);
    g.addEdge(0,2,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    g.addEdge(3,1,1);

    g.printAdiList(5);


    return 0;
}