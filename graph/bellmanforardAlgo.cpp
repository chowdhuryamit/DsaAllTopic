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

    void bellmanfoard(int src,int n){
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        for(int i=0;i<n-1;i++){
            for(auto a:adjList){
                for(auto b:a.second){
                    //a.fist=u
                    //a.second=list<pair<int,int>>
                    //b.first=v
                    //b.second=wt
                    if(dist[a.first]!=INT_MAX && dist[b.first]>dist[a.first]+b.second){
                        dist[b.first]=dist[a.first]+b.second;
                    }

                }
            }
        }
        for (int i = 0; i < n; i++)
        {
           cout<<dist[i]<<" ";
        }
        cout<<endl;

        bool negativeCyclePresent=false;
        for(auto a:adjList){
                for(auto b:a.second){
                    //a.fist=u
                    //a.second=list<pair<int,int>>
                    //b.first=v
                    //b.second=wt
                    if(dist[a.first]!=INT_MAX && dist[b.first]>dist[a.first]+b.second){
                        //dist[b.first]=dist[a.first]+b.second;
                        negativeCyclePresent=true;
                        break;
                    }

                }
                if(negativeCyclePresent){
                    break;
                }
            }
            if(negativeCyclePresent){
                cout<<"negative cycle present"<<endl;
            }
            else{
                cout<<"no negative cycle present"<<endl;
            }
        
    }

    

};
int main(){

    Graph g;
    // g.addEdge(0,1,-1,1);
    // g.addEdge(0,2,4,1);
    // g.addEdge(1,2,3,1);
    // g.addEdge(1,3,2,1);
    // g.addEdge(1,4,2,1);
    // g.addEdge(3,2,5,1);
    // g.addEdge(3,1,1,1);
    // g.addEdge(4,3,-3,1);
    g.addEdge(0,1,-1,1);
    g.addEdge(1,0,-4,1);

    //g.printAdiList(6);
    g.bellmanfoard(0,2);



    return 0;
}