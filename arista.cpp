#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&arr){
    int n=arr.size();
    unordered_map<int,int>mp;
    for(int num:arr){
        mp[num]++;
    }
    int maxlen=0,maxel=-1;
    for(auto &it:mp){
        if(it.second>maxlen){
            maxlen=it.second;
            maxel=it.first;
        }else if(it.second==maxlen){
            maxel=max(maxel,it.first);
        }
    }
    long long ans=0;
    int last=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==maxel){
            last=i;
        }
        ans+=last+1;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<solve(arr)<<endl;
}
