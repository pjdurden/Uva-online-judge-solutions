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
int dx[]={1,0};//N,S,E,W
int dy[]={0,1};


int n,m,q,r;
bool grid[105][105];
int dp[104][104];

bool isvalid(int i,int j)
{
    return (i>=0 and j>=0 and i<n and j<m and !grid[i][j]);
}

int safeside(int i,int j)
{
    if(i==n-1 and j==m-1)return 1;
    if(dp[i][j]!=-1)return dp[i][j];
    int temp=0;
    for(int l=0;l<2;l++)
    {
        int x=i+(dx[l]);
        int y=j+(dy[l]);
        if(isvalid(x,y))
        {
            temp+=safeside(x,y);
        }
    }
    return dp[i][j]=temp;
}

void solve()
{
    cin>>n>>m;
    memset(dp,-1,sizeof dp);
    memset(grid,false,sizeof grid);
    string s;
    getline(cin,s);
    for( int i = 0 ; i < n ; i++ )
    {
      getline(cin,s);
      stringstream sin(s);
      int p, q; sin >> p;
      while(sin >> q) {
            grid[p-1][q-1] = true;
        }
    }
    cout<<safeside(0,0)<<endl;
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
