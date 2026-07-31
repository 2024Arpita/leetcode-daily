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
    cin>>n;
    string s;
    cin>>s;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int maxlen=0;
    unordered_map<int,int>last;
    map<pair<int,int>,vector<int>>mp;
    mp[{0,0}].push_back(-1);
    int lo=0;
    int ca=0,cb=0,cc=0;
    for(int i=0;i<n;i++){
        if(s[i]=='A'){
            ca++;
        }else if(s[i]=='D'){
            cb++;
        }else{
            cc++;
        }
        if(last.count(nums[i])){
            lo=max(lo,last[nums[i]]+1);
        }
        last[nums[i]]=i;
        pair<int,int>p={ca-cb,ca-cc};
        if(mp.count(p)){
            auto &vec=mp[p];
            //st=prev+1>=lo ->prev>=lo-1
            auto it=lower_bound(vec.begin(),vec.end(),lo-1);
            if(it!=vec.end()){
                maxlen=max(maxlen,i-*it);
            }
        }
        mp[p].push_back(i);
    }
    cout<<maxlen<<endl;
}
