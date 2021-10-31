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

int n,m,q,r,maxl,maxr;
int dx[]={-1,1,0,0};//N,S,E,W
int dy[]={0,0,-1,1};

int board[2002][2002];
int dist[2002][2002];
int vis[2002][2002];


int bfs(queue<pi> q)
{
    while(!q.empty())
    {
        int tx=q.front().first;
        int ty=q.front().second;
        q.pop();
        if(board[tx][ty]==2)
        {
            return dist[tx][ty];
        }
        for(int i=0;i<4;i++)
        {
            int x=tx+dx[i];
            int y=ty+dy[i];
            if(x<0 or y<0 or x>2000 or y>2000 or vis[x][y] )continue;
            vis[x][y]=true;
            dist[x][y]=dist[tx][ty]+1;
            q.push({x,y});
        }
    }
    return -1;
}



void solve()
{
	while(cin>>n and n!=0)
    {
        int a,b;
        memset(board,0,sizeof(board));
        vector<pi> temp2;
        queue<pi>q;
        memset(dist,-1,sizeof(dist));
        memset(vis,false,sizeof(vis));
        for(int i=0;i<n;i++)
        {
            cin>>a>>b;
            q.push({a,b});
            vis[a][b]=true;
            dist[a][b]=0;
            board[a][b]=1;
        }
        cin>>m;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            temp2.pb({a,b});
            board[a][b]=2;
        }
        
        
        /*for(int i=0;i<maxl;i++)
        {
            for(int j=0;j<maxr;j++)
            {
                cout<<dist[i][j]<<" ";
            }
            cout<<endl;
        }*/
        int res=bfs(q);
        cout<<(res==0?1:res)<<endl;

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
