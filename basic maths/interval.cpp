//lc 1732
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        int maxi=0,a=0;
        for(int i=0;i<n;i++){
            int b=gain[i]+a;
            maxi=max(maxi,b);
            a=b;
        }
        return maxi;
    }
};