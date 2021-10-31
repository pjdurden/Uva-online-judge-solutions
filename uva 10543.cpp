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
vvi graph;
int dp[55][20];

int game(int p,int spe)
{
    if(spe>20)return 1000;
    if(p==n-1)
    {
        if(spe>=q)return spe;
    }
    if(dp[p][spe]!=-1)return dp[p][spe];
    int temp=1000;
    for(int i=0;i<graph[p].size();i++)
    {
        temp=min(temp,game(graph[p][i],spe+1));

    }
    return dp[p][spe]=temp;
}

void solve()
{
    while(cin>>n>>m>>q and !(n==0 and m==0 and q==0) )
    {
        graph.clear();
        graph.resize(n);
        int a,b;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            graph[a].pb(b);
        }
        memset(dp,-1,sizeof dp);
        int res=game(0,1);
        if(res<1000)
            cout<<res<<endl;
        else cout<<"LOSER\n";
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
    //int counter=1;
    while(k--)
    {
        //printf("Case %d: ",counter++);
        solve();
    }
    return 0;
}
