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

vector<vpi>edges;//adjacency list
vector<ll> dist;

int dijkstra() {
    ll LINF = 1e15;
    dist.assign(n+1, LINF);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    dist[q] = 0; pq.push({0, q});
    while (pq.size()) {
        pi a = pq.top(); pq.pop();
        if(a.second==r)return dist[a.second];
        if(a.first>dist[a.second])continue;
        for (auto v : edges[a.second]) {
            if (dist[v.first] > dist[a.second] + v.second) {
                dist[v.first] = dist[a.second] + v.second;
                pq.push({dist[v.first], v.first});
            }
        }
    } 
    return -1;
}






void solve()
{
    cin>>n>>m>>q;
    cin>>r;
    int a,b,c;
    edges.clear();
    edges.resize(n);
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        edges[a].pb({b,c});
        edges[b].pb({a,c});
    }
    int res=dijkstra();
    if(res==-1)printf("unreachable\n");
    else printf("%d\n",res);
    
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
    cin>>k;int counter=1;
    while(k--)
    {
        printf("Case #%d: ",counter++);
        solve();
        
    }
    return 0;
}
