//Profile a connected undirected unweighted graph for the following properties.
#include <stdlib.h>
#include "graphprofile.h"

// 1. What is average degree of a vertex in the graph?
int avgDegree(int **g, int n) {
int count=0,i,j,ans=0;
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(g[i][j] == 1)
count++;
}
}
if(n!=0)
ans = count/n;
    return ans;
}

// 2. Is the graph a regular graph?
int isRegular(int **g, int n) {
int i,j,count1;
int degree[n];


for(i=0;i<n;i++)
{
count1 = 0;
for(j=0;j<n;j++)
{
if(g[i][j]==1)
count1 ++;
}
degree[i] = count1;
}

int flag=1,temp;
temp=degree[0];
for(i=0;i<n;i++)
{
if(degree[i]!=temp)
flag = 0;
}

if(flag==0)
return 0;

return 1;
}

// 3. Is the graph a complete graph?
int isComplete(int **g, int n) {

int i,j,flag=1;
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(i!=j)
{
if(g[i][j] == 0)
flag = 0;
}
}
}

if(flag==0)
return 0;

return 1;
}

// 4. Is the graph a cycle graph?
int isCycleGraph(int **g, int n) {

int i,j,flag=1,count;
int degree[n];

for(i=0;i<n;i++)
{
count = 0;
for(j=0;j<n;j++)
{
if(g[i][j]==1)
count ++;
}
degree[i]=count;
}


for(i=0;i<n;i++)
{
if(degree[i] != 2)
flag = 0;
}

if(flag==0)
return 0;

return 1;
}

// 5. Is the graph a path graph but not a cycle graph?
int isPathGraph(int **g, int n) {

int i,j,count;
int degree[n];

for(i=0;i<n;i++)
{
count = 0;
for(j=0;j<n;j++)
{
if(g[i][j] == 1)
count ++;
}
degree[i] = count;
}

int d1=0,d2=0;
for(i=0;i<n;i++)
{
if(degree[i] == 1)
d1 ++;
if(degree[i] == 2)
d2 ++;
}

if( (d1+d2)!=n )//guarantees that all nodes have degrees 1 or 2.
    return 0;
if( d1==2 )//guarantees that exactly two nodes are of degree 1.
return 1;
else
return 0;
}

// 6. Does the graph has an Euler circuit?
int hasEulerCkt(int **g, int n) {

int i,j,count;
int degree[n];

for(i=0;i<n;i++)
{
count = 0;
for(j=0;j<n;j++)
{
if(g[i][j]==1)
count ++;
}
degree[i] = count;
}

int flag=1;
for(i=0;i<n;i++)
{
if(degree[i]%2!=0)
flag = 0;
}

if(flag == 0)
return 0;

return 1;

}





 

// 7. Does the graph has an Euler path but not an Euler circuit?
int hasEulerPath(int **g, int n) {

int i,j,count;
int degree[n];

for(i=0;i<n;i++)
{
count = 0;
for(j=0;j<n;j++)
{
if(g[i][j]==1)
count ++;
}
degree[i] = count;
}


int odd_degree=0;
for(i=0;i<n;i++)
{
if(degree[i]%2 == 1)
odd_degree ++;
}

if(odd_degree != 2)
return 0;

return 1;
}





// 8. Does the graph satisfy the sufficient condition of the Ore's theorem?
// Sufficient condition for the graph to have a Hamilton according the Ore's theorem:
// deg(u) + deg(v) ≥ n for every pair of nonadjacent vertices u and v in the graph
int satifiesOresTheorem(int **g, int n) {




int u,v,i,degU,degV;
for(u=0;u<n-1;u++)
{
for(v=u+1;v<n;v++)
{
if(!g[u][v])
{
degU=degV=0;
for(i=0;i<n;i++)
{
if(g[u][i])
degU++;
if(g[v][i])
degV++;
}
if((degU+degV)<n)
return 0;
}
}
}
return 1;
}

