#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int m;
        cin>>m;
        vector<pair<int,int>>heros(m);
        int mxlim=*max_element(a.begin(),a.end());
        for(int i=0;i<m;i++){
            cin>>heros[i].first>>heros[i].second;
        }
        
        vector<long long>powrs(n+2);
        int mxi=0;
        for(auto &it:heros){
         if(it.second<=n) {
            powrs[it.second]=max(powrs[it.second],(long long)it.first);
         }
        }
        for(int i=n;i>0;i--){
            powrs[i]=max(powrs[i+1],powrs[i]);
        }
        if(powrs[1]<mxlim){
            cout<<-1<<endl;
            continue;
        }
        int cnt=0;
        int i=0;
        while(i<n){
            cnt++;
            int len=0;
            int mx=0;
            while(i<n){
                mx=max(mx,a[i]);
                if(powrs[len+1]<mx){
                    break;
                }
                len++;
                i++;
            }
        }
        cout<<cnt<<endl;
    }
}
