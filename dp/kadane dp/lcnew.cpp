//lc 3976
class Solution {
private:
    long long solve(vector<int>& nums, int k,bool mul){
        long long mini=-4e18;
        long long before=mini,after=mini,inside=mini,ans=mini;
        for(long long x:nums){
            long long nval;
            if(mul){
                nval=x*k;
            }else{
                nval=x/k;
            }
            long long nbefore=max(x,before+x);
            long long ninside=max({inside+nval,nval,before+nval});
            long long nafter=max(after+x,inside+x);
            
            before=nbefore;
            after=nafter;
            inside=ninside;
            ans=max({ans,before,inside,after});
        }

        return ans;
    }
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        return max(solve(nums,k,true),solve(nums,k,false));
    }
};