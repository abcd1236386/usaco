/*
Auther:haozy
Problem:77
Language:C++
Description:Prime summations
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<cstring>
using namespace std;
int cents[1000];
const int n=1000;
int method_dp(int rem,int maxn)
{
    int dp[n+1][rem+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=n;i++)
        dp[i][0]=1;
    for(int i=1;i<=rem;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[j][i]=dp[j-1][i];
            if(cents[j-1]<=i)
                dp[j][i]+=dp[j][i-cents[j-1]];
        }
        if(dp[n][i]>=maxn)
            cout<<i<<endl;
    }
    cout<<"max is "<<dp[n][rem]<<endl;
    
}
void init(){
    cents[0]=2;
    int len=1;
    int x=2;
    while(len<n){
        bool is=true;
        for(int i=len-1;i>=0;i--)
        {
            if(x%cents[i]==0){
                is=false;
                break;
            }
        }
        if(is)
            cents[len++]=x;
        x++;
    }
}
int main(){
    int x;
    init();
    while(cin>>x){
        method_dp(x,5000);
    }

}

