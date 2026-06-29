class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_map<string,int>mp;
        int n=word.length();
        for(int len=1;len<=n;len++){
            for(int i=0;i+len<=n;i++){
                mp[word.substr(i,len)]++;
            }
        }
        int ans=0;
        for(auto &wrd :patterns){
            if(mp.count(wrd)){
                ans++;
            }
        }
        return ans;
    }
};
//we can also do this with kmp
