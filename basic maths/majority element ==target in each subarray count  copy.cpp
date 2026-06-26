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

//method 2
target==nums[i]?1:-1;
int cnt=0,ans=0;
for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
        cnt+=(target==nums[i]?1:-1);
        if(cnt>0){
            ans++;
        }
    }
}
return ans;

//or you can use prefic suffix sum trick
pre[j+1]-pre[i]  will give cnt of target in given range
