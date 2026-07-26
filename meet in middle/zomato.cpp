/******************************************************************************

                              Online C++ Debugger.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Debug" button to debug it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long k;
    cin>>n>>k;
    vector<long long>p(n),q(n);
    for(int i=0;i<n;i++) cin>>p[i];
    for(int i=0;i<n;i++) cin>>q[i];
    
    vector<pair<long long,long long>>l,r;
    int n1=n/2;
    int n2=n-n1;
    for(int mask=0;mask<(1<<n1);mask++){
        long long lp=0,lq=0;
        for(int b=0;b<n1;b++){
            if((1<<b)&mask){
                lp+=p[b];
                lq+=q[b];
            }
        }
        l.push_back({lp,lq});
    }
     for(int mask=0;mask<(1<<n2);mask++){
        long long lp=0,lq=0;
        for(int b=0;b<n2;b++){
            if((1<<b)&mask){
                lp+=p[n1+b];
                lq+=q[n1+b];
            }
        }
        r.push_back({lp,lq});
    }
    vector<long long>mxr(r.size());
    sort(r.begin(),r.end());
    long long maxi=r[0].second;
    mxr[0]=maxi;
    for(int i=1;i<r.size();i++){
        maxi=max(maxi,r[i].second);
        mxr[i]=maxi;
    }
    
    long long ans=0;
    for(auto &a:l){
        long long p1=a.first,q1=a.second;
        if(p1>k) continue;
        auto it=upper_bound(r.begin(),r.end(),make_pair(k-p1,LLONG_MAX));
        
        if(it==r.begin()){
            ans=max(ans,q1);
        }
            --it;
            int i=it-r.begin();
            ans=max(ans,q1+mxr[i]);
        }
    cout<<ans<<endl;
}