
//since pre[j+1]-pre[i]>0 to target be majority elem
so pre[j+1]>pre[j]
use map to track orev solve cnt and one var to store valid left traversals

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        long long ans=0;
        //if(Arr[i]==target)==1 else consider -1;
        int cursum=0, leftside=0;
        int n=nums.size();

        unordered_map<int ,int>mp;
        mp[0]=1;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                leftside+=mp[cursum];
                cursum++;         
            }else{
                cursum--;
                leftside-=mp[cursum];
            }
            mp[cursum]++;
            ans+=leftside;
        }
        return ans;
    }
};
