#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int w,h,n;
        cin>>w>>h>>n;
        vector<int>rows,cols;
        rows.push_back(0);
        cols.push_back(0);
        rows.push_back(w+1);
        cols.push_back(h+1);
        while (n--)
        {
            int x,y;
            cin>>x>>y;
            rows.push_back(x);
            cols.push_back(y);

        }
        sort(rows.begin(),rows.end());
        sort(cols.begin(),cols.end());
        int maxi=INT_MIN;
        int maxHeight=INT_MIN;
        for(int i=1;i<rows.size();i++){
            maxHeight=max(maxHeight,rows[i]-rows[i-1]-1);
        }
        int maxWidth=INT_MIN;
        for(int i=1;i<cols.size();i++){
            maxWidth=max(maxWidth,cols[i]-cols[i-1]-1);
        }
        int ans=maxHeight*maxWidth;
        cout<<ans<<endl;
        
    }
    
}