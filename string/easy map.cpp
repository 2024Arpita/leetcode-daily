//1189
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>mp;
        string reqd="balloon";
        for(char ch:reqd){
            mp[ch]=0;
        }
        for(char ch:text){
            if(mp.find(ch)!=mp.end()){
                mp[ch]++;
            }
        }
        int mini=INT_MAX;
        for(auto &it:mp){
            if(it.first=='l' || it.first=='o'){
                mini=min(mini,it.second/2);
            }else{
                mini=min(mini,it.second);
            }
        }
        return mini;
    }
};