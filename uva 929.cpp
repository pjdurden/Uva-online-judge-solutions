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
int board[1000][1000];

ll dist[1000][1000];
int dx[]={-1,1,0,0};//N,S,E,W
int dy[]={0,0,-1,1};

int dijkstra() {
    ll LINF = 1e15;
    for(int i=0;i<1000;i++)
        for(int j=0;j<1000;j++)
            dist[i][j]=LINF;
    
    priority_queue<pair<int,pi>, vector<pair<int,pi>>, greater< pair<int,pi> >> pq;
    dist[0][0] = board[0][0]; pq.push({board[0][0], {0,0}});
    while (pq.size()) {
        int x=pq.top().second.first;
        int y=pq.top().second.second;
        int w=pq.top().first;
        pq.pop();
        if(x==n-1 and y==m-1)
            return dist[x][y];
        for(int i=0;i<4;i++)
        {
            int tx=x+dx[i];
            int ty=y+dy[i];
            if(tx<0 or ty<0 or tx>=n or ty>=m)continue;
            if (dist[tx][ty] > dist[x][y] + board[tx][ty] ) {
                dist[tx][ty] = dist[x][y] + board[tx][ty];
                pq.push({dist[tx][ty],{tx,ty}});
            }
        }
    } 
    return -1;
}






void solve()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>board[i][j];
        }
    }
    int res=dijkstra();
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
    }
    return 0;
}
