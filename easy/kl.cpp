class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>allnums;
        for(int i=1;i<9;i++){
            long long  st=i;
            int next=i+1;
            while(next<=9){
                st=st*10+next;
                if(st>=low && st<=high )allnums.push_back(st);
                next++;
            }
        }
        sort(allnums.begin(),allnums.end());
        return allnums;
    }
};