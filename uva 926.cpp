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
int dy[]={0,0,1,-1};



int n,m,q,r;
int sx,sy,ex,ey;
bool grid[70][70];
ll dp[70][70];

bool isvalid(int i,int j)
{
    return (i>=2 and j>=2 and i<=2*(ey) and j<=2*(ex));
}

ll safeside(int i,int j)
{
    if(i==2*(ey) and j==2*(ex) )return 1;
    if(dp[i][j]!=-1)return dp[i][j];
    ull temp=0;
    //cout<<i<<j<<endl;
    for(int l=1;l<3;l++)
    {
        int x=i+(dx[l]);
        int y=j+(dy[l]);
        int tx=x+dx[l];
        int ty=y+dy[l];
        if(isvalid(tx,ty) and !grid[x][y] )
        {
            temp+=safeside(tx,ty);
        }
    }
    return dp[i][j]=temp;
}

void solve()
{
    cin>>n;
    cin>>sx>>sy>>ex>>ey;
    cin>>m;
    memset(grid,false,sizeof grid);
    memset(dp,-1,sizeof dp);
    int a,b;
    char ar;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>ar;
        int dir;
        if(ar=='N')dir=1;
        else if(ar=='S')dir=0;
        else if(ar=='E')dir=2;
        else dir=3;
        grid[(2*b)+dx[dir]][(2*a)+dy[dir]]=true;
    }
    /*for(int i=1;i<=2*n;i++)
    {
        for(int j=1;j<=2*n;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<safeside(2*sy,2*sx)<<endl;
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
    }
    return 0;
}
