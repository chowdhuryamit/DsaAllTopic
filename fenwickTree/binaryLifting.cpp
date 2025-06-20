#include<bits/stdc++.h>
using namespace std;

void update(vector<int>& fen,int i,int x){
  int n=fen.size();
  while (i<=n)
  {
    fen[i]+=x;
    i=i+(i&(-i));
  }
}

int lowerBound(vector<int>& fen,int n,int target){
    int currIdx=0,prevSum=0;
    for(int i=log2(n-1);i>=0;i--){
        if(currIdx+(1<<i)<=n-1){
          if(fen[currIdx+(1<<i)]+prevSum<target){
            currIdx=currIdx+(1<<i);
            prevSum+=fen[currIdx];
          }
        }
    }
    return currIdx+1;
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for (int i = 1; i <=n; i++)
    {
        int ele;
        cin>>ele;
        v[i]=ele;
    }
    vector<int>fen(n,0);
    for (int i = 1; i <=n; i++)
    {
        update(fen,i,v[i]);
    }
    cout<<lowerBound(fen,n,27);
    
}