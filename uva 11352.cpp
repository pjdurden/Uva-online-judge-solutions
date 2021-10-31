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

int n,m,q,r,maxl,maxr;
int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,1,1,1,0,-1,-1,-1};

int dxk[]={-2,-1,1,2,2,1,-1,-2};
int dyk[]={1,2,2,1,-1,-2,-2,-1};

string board[105];
int knight[105][105];
int king[105][105];


void bfs(queue<pi>q)
{
    

    while(!q.empty())
    {
        pi a=q.front();
        q.pop();
        if(knight[a.first][a.second]==1)continue;
        for(int i=0;i<8;i++)
        {
            int x=a.first+dxk[i];
            int y=a.second+dyk[i];
            if(x<0 or y<0 or x>=n or y>=m)continue;
            if(knight[x][y]!=-1 or board[x][y]=='A' or board[x][y]=='B')continue;
            knight[x][y]=knight[a.first][a.second]+1;
            q.push({x,y});
        }
    }
}

int bfsking(int i,int j,int k,int l)
{
    memset(king,-1,sizeof(king));
    queue<pi>q;
    king[i][j]=0;
    q.push({i,j});
    while(!q.empty())
    {
        pi a=q.front();
        q.pop();
        if(a.first==k and a.second==l)return king[a.first][a.second];
        
        for(int i=0;i<8;i++)
        {
            int x=a.first+dx[i];
            int y=a.second+dy[i];
            if(x<0 or y<0 or x>=n or y>=m )continue;
            if(king[x][y]!=-1)continue;
            if(knight[x][y]!=-1)continue;
            king[x][y]=king[a.first][a.second]+1;
            q.push({x,y});
        }
    }
    return -1;
}



void solve()
{
    memset(knight,-1,sizeof(knight));
    cin>>n>>m;
    pi src,dst;
    queue<pi> q;
    for(int i=0;i<n;i++)
    {
        cin>>board[i];
        for(int j=0;j<m;j++)
        {
            if(board[i][j]=='A')
            {
                src.first=i;src.second=j;
            }
            else if(board[i][j]=='B')
            {
                dst.first=i;dst.second=j;
            }
            if(board[i][j]=='Z')
            {
                knight[i][j]=0;
                q.push({i,j});
            }
        }
    }
    bfs(q);
    int res=bfsking(src.first,src.second,dst.first,dst.second);
    if(res==-1)
        cout<<"King Peter, you can't go now!"<<endl;
    else cout<<"Minimal possible length of a trip is "<<res<<endl;

    
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
