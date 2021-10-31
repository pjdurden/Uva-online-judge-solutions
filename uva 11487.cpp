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
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
//char board[26][26];

int n,m,q,r;
char graph[11][11];
int dp[11][11][30];
bool vis[11][11];
int res;

bool isvalid(int i,int j)
{
    return (i>0 and j>0 and i<=n and j<=n and graph[i][j]!='#');
}

ll game(int i,int j,int prev)
{
    if(graph[i][j]!='.')
    {
        if(graph[i][j]!=('A'+prev))return INT_MAX;
        if(graph[i][j]==('A'+n-1))
            return 0;
    }
    //cout<<i<<j<<endl;
    if(dp[i][j][prev]!=-1)return dp[i][j][prev];
    int css=0;
    if(graph[i][j]==('A'+prev))css=1;
    ll count=INT_MAX;
    for(int l=0;l<4;l++)
    {
        int x=i+dx[l];
        int y=j+dy[l];
        int c=0;
        if(isvalid(x,y) and !vis[x][y])
        {
            vis[x][y]=true;
            c=1+game(x,y,prev+css);
            vis[x][y]=false;
            if(c<=count)
            {
                if(i==m and j==q and c==count)
                {
                    res++;
                    continue;
                } 
                count=c;
                res=1;
            }
        }

    }
    return dp[i][j][prev]=count;
}

void solve()
{
    int counter=1;
    while(cin>>n and !(n==0) )
    {
        printf("Case %d: ",counter++);
        memset(dp,-1,sizeof dp);
        res=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>graph[i][j];
                if(graph[i][j]=='A')
                {
                    m=i;q=j;
                }
            }
        }
        memset(vis,false,sizeof vis);
        vis[m][q]=true;
        ll ans=game(m,q,0);
        if(ans<INT_MAX)
            cout<<ans<<" "<<res<<endl;
        else cout<<"Impossible\n";
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
