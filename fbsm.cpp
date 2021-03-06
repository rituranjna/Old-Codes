#include<iostream>
#include<cstdio>
typedef long long int lg;
#define m  1000000007

void multiply(lg F[2][2], lg M[2][2]);
 
void power(lg F[2][2], lg n);
 
/* function that returns nth Fibonacci number */
lg fib(lg n)
{
  lg F[2][2] = {{1,1},{1,0}};
  if(n == 0)
    return 0;
  power(F, n-1);
  return (F[0][0])%m;
}
 
/* Optimized version of power() in method 4 */
void power(lg F[2][2], lg  n)
{
  if( n == 0 || n == 1)
      return;
  lg M[2][2] = {{1,1},{1,0}};
 
  power(F, n/2);
  multiply(F, F);
 
  if( n%2 != 0 )
     multiply(F, M);
}
 
void multiply(lg F[2][2], lg M[2][2])
{
  lg x =  (F[0][0]*M[0][0])%m + (F[0][1]*M[1][0])%m;
  lg y =  (F[0][0]*M[0][1])%m + (F[0][1]*M[1][1])%m;
  lg z =  (F[1][0]*M[0][0])%m + (F[1][1]*M[1][0])%m;
  lg w =  (F[1][0]*M[0][1])%m + (F[1][1]*M[1][1])%m;
 
  F[0][0] = x%m;
  F[0][1] = y%m;
  F[1][0] = z%m;
  F[1][1] = w%m;
}
 
/* Driver program to test above function */
int main()
{
  lg n = 9,test,x,an,nl,nu,y;
scanf("%lld",&test);

while(test--)
{
  scanf("%lld%lld",&nl,&nu);

    x=(fib(nl+1)-1)%m;

    y=(fib(nu+2)-1)%m;

   if((y-x)<0)
   an=y-x+m;
  else
   an=y-x;   
 
   

  printf("%lld\n",an);
 } 
  return 0;
}
