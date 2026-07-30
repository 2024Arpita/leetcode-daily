#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int m;
    cin>>m;
    vector<pair<int,int>>q(m); using t=tuple<int,int,int>;
    vector<t>vec;
    for(int i=0;i<m;i++){
        cin>>q[i].first>>q[i].second;
        vec.push_back({q[i].first,q[i].second,i});
    }
    int wsz=sqrt(n);
    sort(vec.begin(),vec.end(),[&](auto &l,auto &r){
       int win_size_l=get<0>(l)/wsz;
       int win_size_r=get<0>(r)/wsz;
       if(win_size_r==win_size_l){
           return get<1>(l)<get<1>(r);
       }
       return win_size_l<win_size_r;
    });
    unordered_map<int,int>freq;
    int cnt=0;
    auto add=[&](int idx){
        freq[a[idx]]++;
        if(freq[a[idx]]==1){
            cnt++;
        }
    };
    auto erase=[&](int idx){
        freq[a[idx]]--;
        if(freq[a[idx]]==0){
            cnt--;
        }
    };
    int L=0,R=-1;
    vector<int>ans(m);
    for(auto &it:vec){
       auto[l,r,idx]=it;
        //L ko peeche le ja rhe
        while(L>l){
            add(--L);
        }
        
        //R ko peechc le ja rhe
        while(R<r){
            add(++R);
        }
        
        //L ko remove
        while(L<l){
            erase(L++);
        }
        //R ko remove
        while(R>r){
            erase(R--);
        }
        ans[idx]=cnt;
    }
    for(int i:ans){
        cout<<i<<' ';
    }
}
