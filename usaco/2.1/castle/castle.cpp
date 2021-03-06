/*
ID: haoziyi1
PROG: pprime
LANG: C++                
*/
#include<fstream>
#include<iostream>
using namespace std;
int rm[50][50];
int lb[50][50];
int sz[50*51]={0};
int sid=0;
#define west(x) (x&1)
#define north(x) (x&2)
#define east(x) (x&4)
#define south(x) (x&8)
void dfs(int i,int j,int cl)
{
    if(lb[i][j]!=-1)
        return;
    lb[i][j]=cl;
    sz[cl]++;
    if(!west(rm[i][j]))
        dfs(i,j-1,cl);
    if(!north(rm[i][j]))
        dfs(i-1,j,cl);
    if(!east(rm[i][j]))
        dfs(i,j+1,cl);
    if(!south(rm[i][j]))
        dfs(i+1,j,cl);

}
int main(){
    ifstream fin("castle.in");
    ofstream fout("castle.out");
    int m,n;
    fin>>m>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            fin>>rm[i][j];
            lb[i][j]=-1;
        }
    }
    int clss=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(lb[i][j]==-1)
            {
                dfs(i,j,clss);
                clss++;
            }
        }
    }
    //find a wall to rmove.
    int mxrm=0;
    for(int i=0;i<clss;i++)
    {
        if(sz[i]>mxrm)
            mxrm=sz[i];
    }
    int nrm=mxrm;
    int ti,tj;
    char w;
    for(int j=0;j<m;j++)
    {
        for(int i=n-1;i>=0;i--)
        {
            if(i!=0)
            {
                if(north(rm[i][j])&&lb[i][j]!=lb[i-1][j]
                    &&sz[lb[i][j]]+sz[lb[i-1][j]]>nrm){
                    nrm=sz[lb[i][j]]+sz[lb[i-1][j]];
                    ti=i;
                    tj=j;
                    w='N';
                }
            }
            if(j!=m-1)
            {

                if(east(rm[i][j])&&lb[i][j]!=lb[i][j+1]
                    &&sz[lb[i][j]]+sz[lb[i][j+1]]>nrm){
                    nrm=sz[lb[i][j]]+sz[lb[i][j+1]];
                    ti=i;
                    tj=j;
                    w='E';
                }
            }
        }
    }
    fout<<clss<<'\n';
    fout<<mxrm<<'\n';
    fout<<nrm<<'\n';
    fout<<ti+1<<' '<<tj+1<<' '<<w<<'\n';

}
