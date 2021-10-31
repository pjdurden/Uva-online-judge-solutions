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
int dx[]={1,0};//N,S,w,E
int dy[]={0,1};
bool grid[104][104];
int dp[104][104];

bool isvalid(int i,int j)
{
    return (i>=0 and j>=0 and i<=n and j<=m);
}

int safeside(int i,int j)
{
    if(i==n and j==m)return 1;
    if(dp[i][j]!=-1)return dp[i][j];
    int temp=0;
    //cout<<i<<endl;
    for(int l=0;l<2;l++)
    {
        int x=i+dx[l];
        int y=j+dy[l];
        if(isvalid(x,y) and !grid[x][y])
        {
            temp+=safeside(x,y);
        }
    }
    return dp[i][j]=temp;
}

void solve()
{
    while(cin>>m>>n and !(n==0 and m==0))
    {
        memset(dp,-1,sizeof(dp));
        memset(grid,false,sizeof grid);
        cin>>q;
        int a,b;
        for(int i=0;i<q;i++)
        {
            cin>>a>>b;
            grid[b][a]=true;
        }
        int res=safeside(0,0);

        if(res==0)
            printf("There is no path.\n");
        else if(res==1)
            printf("There is one path from Little Red Riding Hood's house to her grandmother's house.\n");
        else
            printf("There are %d paths from Little Red Riding Hood's house to her grandmother's house.\n",res);


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
