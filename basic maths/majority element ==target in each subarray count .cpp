//method1
int cnt=0;
for(int i=0;i<n;i++){
    unorderd_map<int,int>mp;
    for(int j=i;j<n;j++){
        mp[nums[j]]++;
        if(mp[target]>(j-i+1)/2){
            cnt++;
        }
    }
}
return cnt;