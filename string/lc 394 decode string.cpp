class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        stack<int>curr;
        int num=0;
        string a="";
        for(char ch:s){
            if(isdigit(ch)){
                num=num*10+(ch-'0');
            }else if(ch=='['){
                curr.push(num);
                st.push(a);
                num=0;
                a="";
            }else if(ch==']'){
                string prev=st.top();
                st.pop();
                int times=curr.top();
                curr.pop();
                while(times--){
                    prev+=a;
                }
                a=prev;
            }else{
                a+=ch;
            }
        }
        return a;
    }
};
