///very good greedy approach
//you have to substract from all ahead or previous to do it in o(1)
//maintain one variable and add changes in that and whenever need that udated value use that variable for getting actual value
#include <bits/stdc++.h>
using namespace std;

long long getMinimumCost( vector<long long> &packages) {
    int n=packages.size();
    long long fxcost=accumulate(packages.begin(),packages.end(),0LL);
    long long fromstrt=0;
    long long carry=0;
    for(int i=n-1;i>=0;i--){
        int val=packages[i];
        val-=carry;
        if(val>0){
        carry+=val;
        fromstrt+=(1LL*val*(i+1));
        }
    }
    long long fromend=0;
    carry=0;
    for(int i=0;i<n;i++){
        packages[i]-=carry;
        if(packages[i]>0){ 
            carry+=packages[i];
            fromend+=(1LL*packages[i]*(n-i));
        }
    }
    return min(fromend,fromstrt)+fxcost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin >> n;
    vector<long long> packages(n);
    for (long long i = 0; i < n; ++i) cin >> packages[i];
    cout << getMinimumCost(packages) << "\n";
    return 0;
}
