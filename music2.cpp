#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
struct node
{
char *bs,*cp;
int dp;
};

node a[15];

/*

A	  A# = Bb	B	C	   C# = Db	D
D# = Eb   E	        F   	F# = Gb	   G    	G# = Ab


A major
A# minor
Bb major	B	C	C# = Db	D
D# = Eb	E	F	F# = Gb	G	G# = Ab

*/


int main()
{
a[0].bs=(char *)malloc(100); a[0].bs="A"; a[0].dp=0;
       

a[1].bs=(char*)malloc(100); a[1].bs="A#"; a[1].dp=1; a[1].cp=(char*)malloc(100); a[1].cp="Bb";

a[2].bs=(char*)malloc(100); a[2].bs="B";  a[2].dp=0;

a[3].bs=(char*)malloc(100); a[3].bs="C"; a[3].dp=0;

a[4].bs=(char*)malloc(100); a[4].bs="C#"; a[4].dp=1;  a[4].cp=(char*)malloc(100); a[4].cp="Db";

a[5].bs=(char*)malloc(100); a[5].bs="D"; a[5].dp=0;

a[6].bs=(char*)malloc(100);  a[6].bs="D#"; a[6].dp=1;  a[6].cp=(char*)malloc(100); a[6].cp="Eb";

a[7].bs=(char*)malloc(100); a[7].bs="E"; a[7].dp=0;

a[8].bs=(char*)malloc(100);  a[8].bs="F"; a[8].dp=0;

a[9].bs=(char*)malloc(100);  a[9].bs="F#";  a[9].dp=1;  a[9].cp=(char*)malloc(100); a[9].cp="Gb";

a[10].bs=(char*)malloc(100); a[10].bs="G";  a[10].dp=0;

a[11].bs=(char*)malloc(100);  a[11].bs="G#";  a[11].dp=1;  a[11].cp=(char*)malloc(100); a[11].cp="Ab";


char s[100],t[100];
long long int test=0;

int i,bshai,cphai,ip;

 ip=scanf("%s",s);

 while(ip!=-1)
 {
      scanf("%s",t);
    
  bshai=-1;cphai=-1;
 
 for(i=0;i<12;i++)
   { 
     if(a[i].dp==1)//only if it has two pairs , there exits a duplicate name
       {
        if(strcmp(s,a[i].bs)==0)//matching with ledt sides in upper table
          { bshai=i;break;}
        else if ( strcmp(s,a[i].cp)==0)//if it is not in left side , matching with right side
         {cphai=i;break;}
       }
     }//end for
             
  if(bshai!=-1)
  printf("Case %lld : %s  %s\n",++test,a[bshai].cp,t);
  else if (cphai!=-1)
  printf("Case %lld : %s  %s\n",++test,a[cphai].bs,t);
  else 
  printf("Case %lld : UNIQUE\n",++test);
 
  ip=scanf("%s",s);
 }

return 0;
}




