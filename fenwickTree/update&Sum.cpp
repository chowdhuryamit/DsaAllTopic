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

int sum(int i,vector<int>& fen){
  int s=0;
  while(i>0){
    s+=fen[i];
    i=i&(i-1);
  }
  return s;
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
    cout<<sum(13,fen);
}