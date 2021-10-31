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
int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,1,1,1,0,-1,-1,-1};



int n,m,q,r;
vvi tasks;
int dp[110];
bool vis[110];

int safeside(int i)
{
    if(dp[i]!=-1)return 0;
    int temp=0;
    //cout<<i<<endl;
    for(int j=0;j<tasks[i].size();j++)
    {
        temp+=safeside(tasks[i][j]);
    }
    return dp[i]=temp+1;
}

void solve()
{
    while(cin>>n and n!=0)
    {
        tasks.clear();
        tasks.resize(n);
        for(int i=0;i<n;i++)
        {
            cin>>m;
            for(int j=0;j<m;j++)
            {
                cin>>r;
                tasks[i].pb(r-1);
            }
        }
        int maxind=0;
        int maxres=0;
        for(int i=0;i<n;i++)
        {
            memset(dp,-1,sizeof dp);
            int temp=safeside(i);
            if(temp>maxres)
            {
                maxres=temp;
                maxind=i;
            }
        }
        cout<<maxind+1<<endl;
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
