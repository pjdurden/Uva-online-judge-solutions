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
int dx[]={0,0,1};
int dy[]={1,-1,0};
int arr[78][78];
bool vis[78][78];
ll dp[78][78][6][3];

bool isvalid(int a,int b)
{
    return (a>0 and b>0 and a<=n and b<=n);
}

ll game(int i,int j,int steps,int dir)
{ 
    if(steps>m )return INT_MIN;
    if(i==n and j==n)
        return arr[i][j];            
    //cout<<i<<" "<<j<<" "<<steps<<endl;
    if(dp[i][j][steps][dir]!=-1)return dp[i][j][steps][dir];
    ll count=INT_MIN;
    for(int l=0;l<3;l++)
    {
        int x=i+dx[l];
        int y=j+dy[l];
        if(isvalid(x,y) and !vis[x][y])
        {
            int temp=(arr[x][y]<0?1:0);
            vis[x][y]=true;
            count=max(count,game(x,y,steps+temp,l));
            vis[x][y]=false;
        }
    }
    if(count==INT_MIN)return dp[i][j][steps][dir]=count;
    return dp[i][j][steps][dir]=arr[i][j]+count;
}

void solve()
{
    int counter=1;
    while(cin>>n>>m and !(n==0 and m==0) )
    {
        printf("Case %d: ",counter++);
        memset(dp,-1,sizeof dp);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cin>>arr[i][j];

        memset(vis,false,sizeof(vis));
        vis[1][1]=true;
        int res=game(1,1,arr[1][1]<0?1:0,0);
        if(res>INT_MIN)
            cout<<res<<endl;
        else cout<<"impossible\n";
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
