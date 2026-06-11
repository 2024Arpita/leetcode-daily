//in this question check the range for each num possible
// thhen it is converted to check range for each num
// which is standard prefix sum / sweep line question
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int opr) {
        int ans=0;
        unordered_map<int,int>freq;
        map<int,int>mp;
        for(int num:nums){
            freq[num]++;
            int l=num-k;
            int r=num+k;
            mp[l]++; 
            mp[num]+=0; ///very importamt as we want to see variation of values here also
            
            mp[r+1]--;
        }
        int csum=0;
        int cnt=1;
        for(auto &it:mp){
            csum+=it.second;
            int cfreq=freq[it.first];
            int minopr=min(opr,csum-cfreq);
            ans=max(ans,minopr+cfreq);
        }
        return ans;
    }
};
