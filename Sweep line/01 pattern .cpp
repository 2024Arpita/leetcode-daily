class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[0]=-1;
        int sum=0;
        int maxlen=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                sum++;
            }else{
                sum--;
            }
            if(mp.count(sum)){
                maxlen=max(maxlen,i-mp[sum]);
            }else{
                mp[sum]=i;
            }
        }
        return maxlen;
    }
};
//since we need equal no. of onez and zero if i treat one as 1 and 0 as -1 and 
// them calculate sum and keep on calculating sums thne by seeing rem sum we can get when ot was balanecc
