//lc-1358
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int cnt=0;
        int i=0,j=0;
        unordered_map<int,int>mp;
        while(j<n){
            mp[s[j]-'a']++;
            while(i<n && mp.size()==3){
                cnt+=(n-j);
                mp[s[i]-'a']--;
                if(mp[s[i]-'a']==0){
                    mp.erase(s[i]-'a');
                }
                i++;
            }
            j++;
        }
        return cnt;
    }
};
//standard two pointer approach
