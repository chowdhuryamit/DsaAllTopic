#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
     map<int,list<int>>adjList;

    void addEdge(int u,int v){
        adjList[u].push_back(v);
    } 

    bool isCyclic(int src,map<int,bool>& visited,map<int,bool>& path){
        visited[src]=true;
        path[src]=true;
        for(auto i:adjList[src]){
            if(!visited[i]){
                int ans=isCyclic(i,visited,path);
                if(ans){
                    return ans;
                }
            }
            else if(visited[i]==true && path[i]==true){
                return true;
            }
        }
        path[src]=false;
        return false;
    }

};
int main(){
    Graph g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    //g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);

    map<int,bool>visited;
    bool ans=false;
    for (int i = 0; i < 5; i++)
    {   map<int,bool>path;
        if(!visited[i]){
           ans=g.isCyclic(i,visited,path);
           if(ans==true){
            break;
           }
        }
    }
    if(ans){
        cout<<"cycle found"<<endl;
    }
    else{
        cout<<"no cycle "<<endl;
    }
    


    return 0;
}