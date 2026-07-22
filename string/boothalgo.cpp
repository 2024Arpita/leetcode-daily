//leetcode-3999
class Solution {
private:    
    string findorg(string &s){
        string ans=s;
        int len=s.length();
        string cur=s+s;
        int i=0,j=1,k=0;
        while(i<len && j<len && k<len){
            if(cur[i+k]==cur[j+k]){
                k++;
            }
            else if(cur[i+k]>cur[j+k]){
                i=i+k+1;
                k=0;
                if(i==j) i++;
            }else if(cur[j+k]>cur[i+k]){
                j=j+k+1;
                k=0;
                if(i==j) j++;
            }
        }
        int st=min(i,j);
        ans=cur.substr(st,len);
        return ans;
    }
public:
    int minimumGroups(vector<string>& words) {
        unordered_set<string>sortforms;
        for(auto &it:words){
            string s=it;
            string e="",o="";
            for(int i=0;i<s.length();i++){
                if(i%2==0){
                    e+=s[i];
                }else{
                    o+=s[i];
                }
            }
            string orgo=findorg(o);
            string orge=findorg(e);
            sortforms.insert(orgo+'#'+orge);
        }
        return (int)sortforms.size();
    }
};
