/*
ID:haoziyi1
PROG:prefix
LANG:C++
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
ifstream fin("prefix.in");
ofstream fout("prefix.out");
//we can use a trie-tree. to handl this.
struct trie{
    bool end;
    int next[26];
    trie(){
        end=false;
        memset(next,-1,sizeof(next));
    }
    int getNext(char c)
    {
        return next[c-'A'];
    }
    void setNext(char c,int i)
    {
        next[c-'A']=i;
    }
}nd[2005];
int nid=1;
void insert(string &str)
{
    int t=0;
    int i=str.size()-1;
    while(i>=0)
    {
        if(nd[t].getNext(str[i])==-1)
        {
            nd[t].setNext(str[i],nid++);

        }
        t=nd[t].getNext(str[i]);
        i--;
    }
    nd[t].end=1;
}
int main(){
    string str;
    while(fin>>str,str!=".")
    {
        insert(str);
    }
    string tstr;
    fin.get();
    while(getline(fin,str),str!="")
    {
        tstr+=str;
    }
    vector<bool> dp(12,0);
    dp[0]=1;
    int maxlen=0;
    for(int i=1;i<=tstr.size();i++)
    {
        int t=0;
	dp[i%12]=0;
        for(int j=i;;j--)
        {
            if(nd[t].getNext(tstr[j-1])==-1)
                break;
            //have this node.
            t=nd[t].getNext(tstr[j-1]);
            if(nd[t].end&&dp[(j-1)%12])
            {
                // we find one
                dp[i%12]=1;
                break;
            }
        }
        if(dp[i%12])
            maxlen=i;
        
    }
    fout<<maxlen<<endl;

}

