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
vector<vi> edges;
umap<int,int> dist;
vector<bool> vis;
pi bfs(int node)
{
    dist.clear();
    vis.clear();
    vis.resize(n,false);
    vis[node]=true;
    queue<pi>q;
    q.push({node,0});
    dist[0]=0;
    while(!q.empty())
    {
        pi a=q.front();
        q.pop(); 
        for(int i=0;i<edges[a.first].size();i++)
        {
            if(vis[edges[a.first][i]]==false)
            {
                vis[edges[a.first][i]]=true;
                dist[a.second+1]++;
                q.push({edges[a.first][i],a.second+1});
            }
        }
    }
    int maxt=0,maxind=INT_MAX;
    for(auto j:dist)
    {
        if(j.second>=maxt)
        {
            maxt=j.second;
            maxind=min(maxind,j.first);
        }
    }
    return {maxt,maxind};
}

void solve()
{
    cin>>n;
    edges.clear();
    edges.resize(n);
    int a,k;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        for(int j=0;j<a;j++)
        {
            cin>>k;
            edges[i].pb(k);
        }
    }
    cin>>a;
    for(int i=0;i<a;i++)
    {
        cin>>k;
        pi res=bfs(k);
        if(res.first==0)cout<<"0\n";
        else cout<<res.first<<" "<<res.second<<endl;
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
    //cin>>k;int counter=1;
    while(k--)
    {
        solve();
        
    }
    return 0;
}
