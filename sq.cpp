#include<stdio.h>
int main()
{
    int test,n,k,l,p[210][210],x[505],y[505],z,a,b,c,d,i,j,cont;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        for(i=0;i<210;i++)
         for(j=0;j<210;j++)
         p[i][j]=-1;
         
        for(i=0;i<n;i++)
        {scanf("%d%d",&k,&l);
         x[i]=k+50;
         y[i]=l+50;
         p[k+50][l+50]=1;//Present
         }
         
         cont=0;
         
         for(i=0;i<n-1;i++)
         {
                a=x[i];b=y[i];         
                
                for(j=i+1;j<n;j++)
                {
                  c=x[j];d=y[j];                
                     
                     if(b==d)
                     { z=a-c;
                     if(z<0)
                     z*=(-1);
                     if(p[a][b+z]==1 && p[c][d+z]==1 && b+z<101 && d+z<101)
                     cont++;
                     }
                     else if(a<c && b>d)
                     {if(p[a+b-d][b+c-a]==1 && p[c+b-d][d+c-a]==1 && a+b-d <101 && b+c-a <101 && c+b-d<101 && d+c-a <101)
                      cont++;
                      }
                      else if(a>c && b<d)
                      {
                        if(p[c+d-b][d+a-c]==1 && p[a+d-b][b+a-c]==1 && c+d-b <101 && d+a-c <101 && a+d-b<101 && b+a-c <101)
                        cont++;
                        }
                        }
                        }
                        
                        printf("%d\n",cont);
                        }
                      //scanf("%d",&n);   
                     return 0;
                     }                                     
    
