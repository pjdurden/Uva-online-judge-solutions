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

vector<pi> edges[105];//adjacency list
vector<ll> dist;

void dijkstra() {
    ll LINF = 1e15;
    dist.assign(n+1, LINF);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    dist[m] = 0; pq.push({0, m});
    while (pq.size()) {
        pi a = pq.top(); pq.pop();
        if(a.first>dist[a.second])continue;
        for (auto v : edges[a.second]) {
            if (dist[v.first] > dist[a.second] + v.second) {
                dist[v.first] = dist[a.second] + v.second;
                pq.push({dist[v.first], v.first});
            }
        }
    } 
}






void solve()
{
    cin>>n>>m>>q;
    cin>>r;
    int a,b,c;
    for(int i=0;i<=n;i++)edges[i].clear();
    for(int i=0;i<r;i++)
    {
        cin>>a>>b>>c;
        edges[b].pb({a,c});
    }
    dijkstra();
    int res=0;
    for(int i=1;i<=n;i++)
    {
        if(dist[i]<=q)
            res++;
    }
    cout<<res<<endl;
    
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
        if(k!=0)cout<<endl;
    }
    return 0;
}
