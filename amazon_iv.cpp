/* we have one company which has offices along straight line n offices in straight line 
 office=[1,3,7] and another employee array with emp=[2,5,1] and have to minimze the 
total distance travelled by all employee like for this case we will choose office 3*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>offices(n),employees(n);
    for(int i=0;i<n;i++){
        cin>>offices[i];
    }
    for(int i=0;i<n;i++){
        cin>>employees[i];
    }
    long long totemp=accumulate(employees.begin(),employees.end(),0LL);
    long long sum=0;
    for(int i=1;i<n;i++){
        sum+=((abs(offices[i]-offices[0]))*employees[i]);
    }
    vector<long long>dis(n,0);
    dis[0]=sum;
    long long cemp=employees[0];
    for(int i=1;i<n;i++){
        long long disbw=abs(offices[i]-offices[i-1]);
        dis[i]=dis[i-1]+(2*cemp-totemp)*disbw;
        cemp+=employees[i];
    }
    long long mindis=LLONG_MAX;
    int ansi=-1;
    for(int i=0;i<n;i++){
        if(mindis>dis[i]){
            mindis=dis[i];
            ansi=i;
        }
    }
    cout<<offices[ansi]<<endl;
}
