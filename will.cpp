#include<iostream>
#include<cstdio>
int main()
{
typedef long long int lg;

lg a,k,mila;

scanf("%lld",&a);

k=a;
mila=0;
 
 for(;k>1&& mila==0;)//k < 1 ke lia apne aap rul jaega
   if(k%2==0)
    k=k/2;
   else
   mila=1;
   

 if(mila==1)
 printf("NIE\n");
  else
 printf("TIE\n");

return 0;
}
