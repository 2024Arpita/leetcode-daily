#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t;
    cin>>n>>t;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<pair<int,int>>vec(t);
    using tt=tuple<int,int,int>;
    vector<tt>aa;
    for(int i=0;i<t;i++){
        cin>>vec[i].first>>vec[i].second;
        vec[i].first--;
        vec[i].second--;
        aa.push_back({vec[i].first,vec[i].second,i});
        
    }
    int winsz=(int)sqrt(n);
    sort(aa.begin(),aa.end(),[&](auto &l,auto &r){
        int winsz1=get<0>(l)/winsz;
        int winsz2=get<0>(r)/winsz;
        if(winsz1!=winsz2){
            return winsz1<winsz2;
        }
        if(winsz1&1){
            return get<1>(l)>get<1>(r);
        }
        return get<1>(l)<get<1>(r);
    });
    vector<long long>freq(1e6+1,0);
    vector<long long>ans(t);
    long long fin=0;
    auto erase=[&](int idx){
        int val=a[idx];
        long long ccontri=freq[val]*freq[val]*val;
        freq[val]--;
        fin-=ccontri;
        if(freq[val]<=0){
            return;
        }
        long long ncontri=freq[val]*freq[val]*val;
        fin+=ncontri;
    };
    auto add=[&](int idx){
        int val=a[idx];
        long long ccontri=freq[val]*freq[val]*val;
        freq[val]++;
        fin-=ccontri;
        long long ncontri=freq[val]*freq[val]*val;
        fin+=ncontri;
    };
    int L=0,R=-1;
    for(auto &it:aa){
        auto[l,r,idx]=it;
        //expand
        while(L>l){
           add(--L); 
        }
        
        while(R<r){
            add(++R);
        }
        
        //shrink 
        while(L<l){
            erase(L++);
        }
        while(R>r){
            erase(R--);
        }
        ans[idx]=fin;
    }
    for(int i=0;i<t;i++){
        cout<<ans[i]<<" ";
    }
}
