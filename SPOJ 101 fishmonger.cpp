/*
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod=1e9+7;
#define eps 1e-7
#define vpi vector<pair<int,int>>
#define vi vector<int>
#define pi pair<int,int>
#define pb push_back
#define umap unordered_map
#define uset unordered_set
#define vvi vector<vector<int>>
ll powmod(ll x,ll y){ll t; for(t=1;y;y>>=1,x=x*x%mod) if(y&1) t=t*x%mod; return t;}
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
void smask(int pos,int &i){ i=i^(1<<pos); }
void clmask(int pos,int &i){ i=i&~(1<<pos); }
bool chmask(int pos,int i){return i&(1<<pos);}
double cordist(pair<double,double> a,pair<double,double> b)
{return sqrt(((a.first-b.first)*(a.first-b.first))+((a.second-b.second)*(a.second-b.second)));}



//ll dp[60];
//int posx[10];
//int posy[10];
//int price[30];
//int dx[]={-1,0,1,0};
//int dy[]={0,1,0,-1};
//char board[26][26];

int n,m,q,r;
vvi toll;
vvi dist;
pi res[55][1011];

pi costs(int a,int timeleft)//toll needed,time left
{
    if(timeleft<0)return {1000000,1000000};
    if(a==n-1)return {0,0};
    if( res[a][timeleft] != make_pair(-1,-1) )return res[a][timeleft];
    pi t={INT_MAX,INT_MAX};
    for(int i=0;i<n;i++)
    {
        if(i==a)continue;
        pi temp=costs(i,timeleft-dist[a][i]);
        if( t.first> (temp.first+toll[a][i]) )
        {
            t.first=temp.first+toll[a][i];
            t.second=temp.second+dist[a][i];
        }
    }
    return res[a][timeleft]=t;
}

void solve()
{
    while(cin>>n>>m and !(n==0 and m==0))
    {
        toll.clear();
        toll.resize(n,vi(n,0));
        dist.clear();
        dist.resize(n,vi(n,0));

        for(int i=0;i<52;i++)
        {   for(int j=0;j<1010;j++)
            {   res[i][j]=make_pair(-1,-1);}
        }

        for(int i=0;i<n;i++)
        {   for(int j=0;j<n;j++)
            {    cin>>dist[i][j];}
        }
        
        for(int i=0;i<n;i++)
        {   for(int j=0;j<n;j++)
            {   cin>>toll[i][j];}
        }

        pi res=costs(0,m);

        printf("%d %d\n",res.first,res.second);

    }



}
    


int main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int k=1;
    //cin>>k;
    while(k--)
    {
        solve();  
    }
    return 0;
}
