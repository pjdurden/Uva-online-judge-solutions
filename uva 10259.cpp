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
int dx[]={-1,1,0,0};//N,S,E,W
int dy[]={0,0,-1,1};


int n,m,q,r;
int grid[105][105];
int dp[104][104];

bool isvalid(int i,int j)
{
    return (i>=0 and j>=0 and i<n and j<n);
}

int cubes(int i,int j)
{
    if(dp[i][j]!=-1)return dp[i][j];
    int temp=0;
    for(int k=1;k<=m;k++)
    {
        for(int l=0;l<4;l++)
        {
            int x=i+(dx[l]*k);
            int y=j+(dy[l]*k);
            if(isvalid(x,y) and grid[x][y]>grid[i][j] )
            {
                temp=max(temp,cubes(x,y));
            }
        }
    }
    return dp[i][j]=temp+grid[i][j];
}

void solve()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>grid[i][j];
        }
    }
    memset(dp,-1,sizeof dp);
    cout<<cubes(0,0)<<endl;
}



int main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    int k;
    cin>>k;
    while(k--)
    {
        solve();
        if(k!=0)cout<<"\n";
    }
    return 0;
}
