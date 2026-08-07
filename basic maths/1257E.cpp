#include<bits/stdc++.h>
using namespace std;
int main(){
    int k1,k2,k3;
    cin>>k1>>k2>>k3;
    int i=0;
    int n=k1+k2+k3;
    vector<int>a(n+1);
    for(int i=0;i<k1;i++){
        int val;
        cin>>val;
        a[val-1]=-1;
    }
    for(int i=0;i<k2;i++){
        int val;
        cin>>val;
        a[val-1]=1;
    }
    for(int i=0;i<k3;i++){
        int val;
        cin>>val;
        a[val-1]=0;
    }
    vector<int>pre(n+1,0);
    for(int i=0;i<n;i++){
        pre[i+1]=pre[i]+a[i];
    }
    
    int cur=k1+k2;
    int minpre=pre[0];
    int ans=INT_MAX;
    ans=min(ans,cur+pre[0]);
    
    for(int i=1;i<=n;i++){
       if(a[i-1]==1){
          cur--;
       }else if(a[i-1]==0){
           cur++;
       }
       minpre=min(minpre,pre[i]);
       ans=min(ans,cur+minpre);
    }
    cout<<ans<<endl;
}
