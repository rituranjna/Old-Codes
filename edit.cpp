#include<iostream>
#include<cstdio>
#include<cctype>
#include<cstring>
int main()
{

int i,co,ce,l;
char st[5000];

while(scanf("%s",st)!=EOF)
{
l=strlen(st);

//pahli bar even number  A wale honge
ce=0;
for(i=0;i<l;i++)
{

if(i%2==0)
  if( isupper(st[i]) )//agar 1-1,3-1,5-1 upper hai to lower me convert karo
     ce++;

if(i%2!=0)
  if(islower(st[i]) )
    ce++;

}



//now odd wale ko try karte hai

co=0;

for(i=0;i<l;i++)
{
  if(i%2==0)
    if( islower(st[i]) )
      co++;
  
  if(i%2!=0)
     if( isupper(st[i]) )
       co++;
}


if(co>ce)
printf("%d\n",ce);
else
printf("%d\n",co);


}
return 0;

}

    
