#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
#include<algorithm>
typedef int  lg;
using namespace std;

 
int main()
{
int test;

for(scanf("%d",&test);test--;)
{


  struct node
 {
 vector<lg> list;
 bool used;
 }base[600000];//1048576

char st[1001],token[1001][1001]={0};

lg r,c,x,k,i,j,cn=0;

scanf("%d%d",&c,&r);
//cin>>c>>r;

cn=1;

  for(i=0;i<r;i++)
   {
    scanf("%s",st);
       for(j=0;j<c;j++)  
          if(st[j]=='.')
            token[i][j]=cn++;

   }

// cout<<"cn is   "<<cn<<endl;

for(i=0;i<r;i++)
 for(j=0;j<c;j++)
   {
    x=token[i][j];
   
    if(x!=0)
       {
        if(i>0)
           if(token[i-1][j]!=0)
             base[x].list.push_back(token[i-1][j]);

        if(j>0)
           if(token[i][j-1]!=0)
             base[x].list.push_back(token[i][j-1]);

        if(i+1<r)
             if(token[i+1][j]!=0)
                base[x].list.push_back(token[i+1][j]);

        if(j+1<c)
          if(token[i][j+1]!=0)
            base[x].list.push_back(token[i][j+1]);

     }//end main if

   }//end for

/*
//now rinting the tree

 for(i=1;i<cn;i++)
 {
     k=base[i].list.size();
 
      for(j=0;j<k;j++)
          cout<<base[i].list[j]<<"   ";
      
      cout<<endl;
 }*/
//upar verifed input correct
//bfa one


  queue<lg> bfs1;
  vector<lg>::iterator p;

 for(i=1;i<=cn;i++)
   base[i].used=false;

 
 
  lg dist[600000]={0};//distance i contains the distance of  from sorce 1
   
  dist[1]=0;
  lg in=-1,mx=0,y;//in stores the maximun of the values  and  in its indsex

   bfs1.push(1);
   base[1].used=true;
 
  while(!bfs1.empty())
  { 
    
     x=bfs1.front();
      bfs1.pop();
        
   
   for(p=base[x].list.begin();p!=base[x].list.end();p++)
      { 
        y=*p;
            if(!base[y].used)
              { bfs1.push(y);
                base[y].used=true;
                dist[y]=dist[x]+1;
                 
                 if(dist[y]>mx)
                   {mx=dist[y];in=y;}
               
              }
      }//end for

  }//end while
//cout<<"--->  "<<in<<" <---\n";
//now plot for second visit

for(i=0;i<=cn;i++)
 {base[i].used=false;
 dist[i]=0;
 }

 
   dist[in]=0;
  

 while(bfs1.size())
  bfs1.pop();

   base[in].used=true;

  mx=0;

  while(!bfs1.empty() )
{
  x=bfs1.front();
    bfs1.pop();

  for(p=base[x].list.begin();p!=base[x].list.end();p++)
   {
      y=*p;
         if(!base[y].used)
            {bfs1.push(y);
              base[y].used=true;
              dist[y]=dist[x]+1;
            
                if(dist[y]>mx)
                    mx=dist[y];
             }
    }
}    
   
 //Maximum rope length is 0. 
printf("Maximum rope length is %d.\n",mx);

}




return 0;
}


 







