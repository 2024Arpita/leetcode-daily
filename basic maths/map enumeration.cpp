//lc-3020
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        map<long long,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        int maxlen=1;
        for(auto &it:mp){
            if(it.first==1){
                if(it.second%2){
                    maxlen=max(maxlen,it.second);
                }else{
                    maxlen=max(maxlen,it.second-1);
                }
            }
            else if(it.second>=2){
                int len=1;
                long long val=it.first;
                long long num=it.first;
                while(mp.count(num*num) && mp[num*num]>=2){
                    num=num*num;
                    maxlen=max(maxlen,2*len+1); 
                    len++;
                }
                if(mp.count(num*num)==1){
                    len=1+len*2;
                    maxlen=max(maxlen,len);
                }
            }
        }
        return maxlen;
    }
};

