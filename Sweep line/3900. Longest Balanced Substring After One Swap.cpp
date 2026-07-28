// very very good ques/
class Solution {
public:
    int longestBalanced(string s) {
        int n=s.length();
        int totone=0,totzero=0;
        vector<int>c1(n,0),c0(n,0);
        unordered_map<int,int>mp,mp0,mp1;
        mp[0]=-1;
        int sum=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                c1[i]=1;
                totone++;
            }else{
                c0[i]=1;
                totzero++;
            }
            if(i){
                c1[i]+=c1[i-1];
                c0[i]+=c0[i-1];
            }
        }
        int maxlen=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                sum++;
            }else{
                sum--;
            }
            if(mp.count(sum)){
                maxlen=max(maxlen,i-mp[sum]);
            }
            //balance +2
            if(mp.count(sum-2)){
                int l=mp[sum-2];
                int r=i;
                int cntzero=c0[r]-(l>=0 ?c0[l]:0);
                if(cntzero<totzero){
                    maxlen=max(maxlen,i-mp[sum-2]);
                }else if(mp0.count(sum-2)){
                    maxlen=max(maxlen,i-mp0[sum-2]);
                }
            }

            //balance -2
            if(mp.count(sum+2)){
                int l=mp[sum+2];
                int r=i;
                int cntone=c1[r]-(l>=0 ? c1[l]:0);
                if(cntone<totone){
                    maxlen=max(maxlen,i-mp[sum+2]);
                }else if(mp1.count(sum+2)){
                    maxlen=max(maxlen,i-mp1[sum+2]);
                }
            }
            if(!mp0.count(sum) && c0[i]>0){
                mp0[sum]=i;
            }
            if(!mp1.count(sum) && c1[i]>0 ){
                mp1[sum]=i;
            }
            if(!mp.count(sum)){
                mp[sum]=i;
            }
        }
        return maxlen;
    }
};

//what we basically do in this question is 
// we have to find when we can swap 0 to 1 suppose we have 4 ones and 2 zeroes so to make it balanced 
// we have to make one swap to make sum==0 so we just need to check for sum-2 and sum+2 and 
// sum itself usong map but now problem is this that we store only firstoccuerence of each sum 
// so it may possible that first occunece is not able to give us swappable ones or zeros 
// so we have tomaintain somehow swappable ones and zero to maintain themm for each sum we will store mp0 and mp1
// which will tell us whether we have some swappable pos again when we have seen this some or not 
// so  when we stores sum wwe will check in mp0 and mp1 if that sum exiist and we have some zero previous to this postion which can be swapped
