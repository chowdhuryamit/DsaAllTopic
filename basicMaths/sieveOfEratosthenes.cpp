#include<bits/stdc++.h>
using namespace std;
vector<bool>Seive(int n){
   vector<bool>seive(n,true);
   seive[0]=seive[1]=false;
   for(int i=2;i*i<=n;i++){//optimization outer loop
        if(seive[i]){
            int j=i*i;//optimization inner loop
            while(j<=n){
                seive[j]=false;
                j+=i;
            }
        }
   }
   return seive;
}
int main(){
    vector<bool>seive=Seive(25);
    for (int i = 2; i < seive.size(); i++)
    {
        if(seive[i]){
            cout<<i<<" ";
        }
    }
    


    return 0;
}