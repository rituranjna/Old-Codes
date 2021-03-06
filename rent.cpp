#include <iostream>
#include <algorithm>
#include<cstdio>
using namespace std;
 
#define REP(a,b) for(int a=0;a<b;a++)
#define MAXN 10001
 
struct data{
   int start,finish,gain;
   bool operator <(const data &a)const{
        return (finish<a.finish);
   }
};
 
int tes,n,dp[MAXN],maks;
data dat[MAXN];
 
int main(){
    scanf("%d",&tes);
    while (tes--){
          scanf("%d",&n);
          REP(i,n){
             scanf("%d%d%d",&dat[i].start,&dat[i].finish,&dat[i].gain);
             dat[i].finish+=dat[i].start;
          }
          sort(dat,dat+n);
          REP(i,n){
              maks=0;
              REP(j,i){
                 if (dat[j].finish<dat[i].start){
                    maks=max(maks,dp[j]);
                 }
                 else break;
              }
              dp[i]=maks+dp[i]+dat[i].gain;
          }
          REP(i,n){
              dp[n-1]=max(dp[n-1],dp[i]);
          }
          cout<<dp[n-1]<<endl;
    }
    return 0;
}
