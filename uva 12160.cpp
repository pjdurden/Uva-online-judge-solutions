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
double corknight(pair<double,double> a,pair<double,double> b)
{return sqrt(((a.first-b.first)*(a.first-b.first))+((a.second-b.second)*(a.second-b.second)));}



//ll dp[60];
//int posx[10];
//int posy[10];
//int price[30];
//int dx[]={-1,0,1,0};
//int dy[]={0,1,0,-1};
//char board[26][26];

int n,m,q,r;
vi edges;

bool vis[10000];
int dist[10000];

int bfs(int node,int dsc)
{
    memset(dist,-1,sizeof(dist));
    memset(vis,false,sizeof(vis));
    queue<int>q;
    q.push(node);
    dist[node]=0;
    vis[node]=true;
    while(!q.empty())
    {
        int a=q.front();
        q.pop(); 
        if(a==dsc)return dist[a];
        for(int i=0;i<edges.size();i++)
        {
            int x=(a+edges[i])%10000;
            if(vis[x])continue;
            vis[x]=true;
            dist[x]=dist[a]+1;
            q.push(x);
        }
    }
    return -1;
}






void solve()
{
    int counter=1;
    while(cin>>n>>m>>q)
    {
        if(n==0 and m==0 and q==0)break;
        edges.clear();
        for(int i=0;i<q;i++)
        {
            cin>>r;
            edges.pb(r);
        }
        int res=bfs(n,m);
        printf("Case %d: ",counter++);
        if(res==-1)cout<<"Permanently Locked"<<endl;
        else cout<<res<<endl;

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
