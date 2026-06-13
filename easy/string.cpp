// lc 3838
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(auto &it:words){
            int wt=0;
            for(char ch:it){
                wt+=weights[ch-'a'];
            }
            int idx=wt%26;
            ans.push_back(25-idx+'a');
        }
        return ans;
    }
};