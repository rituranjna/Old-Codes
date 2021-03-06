#include<iostream>
#include<time.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#define pros 2
#define tasks 5
#define d 3
using namespace std;

bool allocated[tasks];//Checks whether a task is allocated to any processor or not
float cost[tasks][pros];//This array is used to store Executation-cost-matrix of a task  on a  procesors 1 and 2
float dist[pros][pros];//To store distance  D(kl) as defined ..It'll be a  symmetric matrix and Dii=0
float  resor[pros];//Tell about  the  max. load on  processor i
int  pr[tasks];//task i is assigned to pr[i] processor
float   weit[tasks][tasks];//Assocoiated Weight  with a communicaton  channel between task i and j //Again  its  asymmetric matrix

float crcost(int t);//CAlculate cost if  task t assigned to processor p
float local(float);// To give a better soln ..originaly Loalsearch function in hetro.pdf
float t_cost(); //returns total cost at  calling time
float busy(int p,int t);//retuns the load of processor p if processor  p is loaded with task t
float cload(int);
int rf[tasks];
float rfcost();

	
int main()
{
int i=0,j;
	//take in weit[][]
cout<<"Enter Weight associated with the edge between tasks i and j \n";
for(i=0;i<tasks;i++)
for(j=0;j<tasks;j++)
cin>>weit[i][j];
	//take in cost[][]
cout<<"Entre the Executation-cost-matrix of a task  on a  procesors\n";
for(i=0;i<tasks;i++)
for(j=0;j<pros;j++)
cin>>cost[i][j]; 

	// take in resor[]
cout<<"Enter max. load on  processor i\n";
for(i=0;i<pros;i++)
cin>>resor[i];

	//take in dist[][]
cout<<"Enter distance-related communication cost frm processor k to processor l\n";
for(i=0;i<pros;i++)
for(j=0;j<pros;j++)
cin>>dist[i][j];

	//Intial soln


	for(i=0;i<tasks;i++)
	allocated[i]=false;//Intially no task is assigned to any processors
        
         

	if(cost[0][0]>cost[0][1] && busy(1,0)<=resor[1] )
	pr[0]=1;
       else
        pr[0]=0;
        
        allocated[0]=true;  	//Assiging first task 
     
float ranndom=1,s0,s1,sj,bs;
int bt; 

for(i=1;i<tasks;i++)
{
allocated[i]=true;
bt=-2;
bs=999999;
for(j=0;j<pros;j++)
{
pr[i]=j;
sj=crcost(i);
if(sj<bs && busy(j,i)<=resor[j])
{bs=sj;
bt=j;
}
}//enf inner for

pr[i]=bt;
}


cout<<cload(0)<<"  "<<cload(1)<<"\n";
 //************End Initial sol ***********

//Now IteratedGreedy algo for  TaskAssignment   starts 
for(i=0;i<tasks;i++)
rf[i]=pr[i];//Justing assigning pr[i] to rf[i]

float fi0=t_cost();

float fi=local(fi0);

float fib=fi,fip,fis;
float t=0.025*t_cost();

clock_t t1,t2;
t1=clock();
t2=clock();



float diff=( (float)t2-(float)t1 )/CLOCKS_PER_SEC;


while(diff<1)
{

fi=t_cost();//False karne ke pahle TOtal cost nikal le 

for(i=0;i<tasks;i++)
rf[i]=pr[i];

for(i=0;i<d;i++)
allocated[rand()%tasks]=false;//Destruction phase .Declaring some random tasks as non-assigned


for(i=0;i<tasks;i++)
{
if(allocated[i]==false) 
{
for(j=0;j<pros;j++)
{
if(j!=rf[i] && busy(j,i)<=resor[j])
{rf[i]=j;
break;
}

}//enf inner for
}
}

/*//Construction phase
{allocated[i]=true;
if((rf[i]==0)&&(busy(1,i)<=resor[1]))
rf[i]=1;
else if((rf[i]==0)&&(busy(1,i)>resor[1]))
rf[i]=0;
else if(rf[i]==1 && (busy(0,i)<=resor[0]))
rf[i]=0;
else if(rf[i]==1 && (busy(0,i)>resor[0]) )
rf[i]=1;
}

}*/


fip=rfcost();

if(fip<fi)//man le nahi hai to kya sab "false" hi  bachenge na 
{
for(i=0;i<tasks;i++)//Best sol
pr[i]=rf[i];
}

for(i=0;i<tasks;i++)
allocated[i]=true;

float fic=t_cost();

fis=local(fic);

if(fis<fip)
 {fi=fis;
if(fi<fib)
fib=fi;
}else if(ranndom<exp( -(fis-fi)/t ) )
fi=fis;

t=0.9*t;


t2=clock();
diff=((float)t2-(float)t1)/CLOCKS_PER_SEC;

}


//**************IteratedGreedy algo. for  TaskAssignment ends

cout<<"\nTask    Processor\n";

for(i=0;i<tasks;i++)
cout<<i+1<<"   "<<pr[i]+1<<"\n";


cout<<"\nTotal cost is  "<<t_cost()<<"\n";

cout<<"\nLLoad on processors ";
for(i=0;i<pros;i++)
cout<<cload(i)<<" <-- "<<resor[i]<<"\n";



return 0;
}








//***Local Search function *****
float local(float co)
{
bool impro=true;
int i,k,pi[tasks];

while(impro)
{
	impro=false;
	
for(i=0;i<tasks;i++)
pi[i]=rand()%tasks;

for(k=0;k<tasks;k++)
{
i=pi[k];

if(t_cost()<co && busy(1,i)<=resor[1])
pi[i]=0;
else
pi[i]=1;
}

if(t_cost()<co)
impro=true;

}

return t_cost();
}


	

//******crcost(int i)  it calculate the cost in  intial solution phase where  cost due to task i is passed as parameter 
float crcost(int t)
{
float zero=0;
if(!allocated[t])
return zero;

	float ft;
ft=cost[t][pr[t]];
	for(int i=0;i<tasks;i++)
{if(allocated[i])
	ft=ft+weit[i][t]*dist[pr[i]][pr[t]];
}
	
	return ft;
}



//*********T_COST FUNCTION TO Return total cost at the given time 
	
float t_cost()
{
float tocost;
tocost=0;
int i;
for(i=0;i<tasks;i++)
tocost=tocost+crcost(i);
return tocost;
}



//*********busy(int ,int) function declaration ***

float busy(int p,int t)
{
int i;
float b=0;
for(i=0;i<tasks;i++)
{
if(allocated[i]==true && pr[i]==p )
b=b+cost[i][p];

}

b=b+cost[t][p];
return b;
}


float cload(int p)
{int k;
float load=0;
for(k=0;k<tasks;k++)
{
if(pr[k]==p && allocated[k]==true)
load=load+cost[k][p];
}

return load;
}

float rfcost()
{
int i,j,k;
float co=0;;
for(i=0;i<tasks;i++)
{
co=co+cost[i][rf[i]];
for(j=0;j<tasks;j++)
co=co+weit[i][j]*dist[rf[i]][rf[j]];
}

return co;
} 
