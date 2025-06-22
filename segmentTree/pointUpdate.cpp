#include<bits/stdc++.h>
using namespace std;
int arr[100005],seg[4*100005];

void buildSeg(int idx,int left,int right){
    if(left==right){
        seg[idx]=arr[left];
        return;
    }
    int mid=(left+right)/2;
    buildSeg(2*idx+1,left,mid);
    buildSeg(2*idx+2,mid+1,right);
    seg[idx] = seg[2*idx+1]+seg[2*idx+2];
}

int traverse(int idx,int l,int r,int left,int right){
    if(l>=left && r<=right){
        return seg[idx];
    }
    if(r<left || l>right){
        return 0;
    }
    int mid=(l+r)/2;
    int leftMax = traverse(2*idx+1,l,mid,left,right);
    int rightMax = traverse(2*idx+2,mid+1,r,left,right);
    return leftMax+rightMax;
}

void pointUpdate(int targetIdx,int targetValue,int idx,int left,int right){
    if(left==right && left==targetIdx){
        seg[idx]=targetValue;
        return;
    }
    int mid=(left+right)/2;
    if(targetIdx<=mid && targetIdx>=left){
      pointUpdate(targetIdx,targetValue,2*idx+1,left,mid);
    }
    else{
        pointUpdate(targetIdx,targetValue,2*idx+2,mid+1,right);
    }
    seg[idx] = seg[2*idx+1]+seg[2*idx+2];
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    buildSeg(0,0,n-1);
    pointUpdate(3,3,0,0,n-1);
    int q;
    cin>>q;
    while(q--){
        int left,right;
        cin>>left>>right;
        cout<<traverse(0,0,n-1,left,right)<<endl;
    }
}