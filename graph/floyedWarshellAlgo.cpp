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

    void floyedWarshell(int n){
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        for (int i = 0; i < n; i++)
        {
            dist[i][i]=0;
        }
        for(auto a:adjList){
            for(auto b:a.second){
                dist[a.first][b.first]=b.second;
            }
        }
        
        for (int helper = 0; helper < n; helper++)
        {
            for(int u=0;u<n;u++){
                for(int v=0;v<n;v++){
                    dist[u][v]=min(dist[u][v],dist[u][helper]+dist[helper][v]);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<dist[i][j]<<" ";
            }
            cout<<endl;
            
        }
    }

    

    

};
int main(){

    Graph g;
    g.addEdge(0,2,-2,1);
    g.addEdge(1,0,4,1);
    g.addEdge(1,2,3,1);
    g.addEdge(3,1,-1,1);
    g.addEdge(2,3,2,1);

    g.floyedWarshell(4);



    return 0;
}