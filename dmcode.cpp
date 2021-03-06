#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

#define d(i,j) dd[(i) * (m+2) + (j) ]
#define min(x,y) ((x) < (y) ? (x) : (y))
#define min3(a,b,c) ((a)< (b) ? min((a),(c)) : min((b),(c)))
#define min4(a,b,c,d) ((a)< (b) ? min3((a),(c),(d)) : min3((b),(c),(d)))


int dldist2(char *s, char* t, int n, int m){
    int *dd, *DA;
    int i, j, cost, k, i1,j1,DB;
    int INFINITY = n + m;

    DA = (int*) malloc( 256 * sizeof(int));
    dd = (int*) malloc ((n+2)*(m+2)*sizeof(int));

    d(0,0) = INFINITY;
    for(i = 0; i < n+1; i++) {
      d(i+1,1) = i ;
      d(i+1,0) = INFINITY;
    }
    for(j = 0; j<m+1; j++) {
      d(1,j+1) = j ;
      d(0,j+1) = INFINITY;
    }      
    //dprint(dd,n,m);
    for(k = 0; k < 256; k++) 
    DA[k] = 0;
    
  for(i = 1; i< n+1; i++)
   {
      DB = 0;
   
      for(j = 1; j< m+1; j++)
      {
        i1 = DA[t[j-1]];
        j1 = DB;
        cost = ((s[i-1]==t[j-1])?0:1);

        if(cost==0)
          DB = j;
 
        d(i+1,j+1)=min4(d(i,j)+cost,d(i+1,j) + 1, d(i,j+1)+1,d(i1,j1) + (i-i1-1) + 1 + (j-j1-1));
      }
      DA[s[i-1]] = i;
     
    }
    cost = d(n+1,m+1);
    free(dd);
    return cost;
}


int main()
{

 int ans;
 char a[2000],b[2000];
 scanf("%s%s",a,b);
 while(a[0]!='*')
 {
  int cost=dldist2(a,b,strlen(a),strlen(b));
  printf("%d\n",cost);
  scanf("%s%s",a,b);;
 }

return 0;
}
