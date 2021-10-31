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

int dx[]={-1,-1};
int dy[]={1,-1};

int n,m,q,r;
char board[110][110];
int dp[110][110];

bool isvalid(int i,int j)
{
    return (i>=0 and j>=0 and i<n and j<n);
}

int safeside(int i,int j)
{
    if(i==0)return 1;
    if(dp[i][j]!=-1)return dp[i][j];
    int temp=0;
    //cout<<i<<endl;
    for(int l=0;l<2;l++)
    {
        int x=i+dx[l];
        int y=j+dy[l];
        if(isvalid(x,y))
        {
            if(board[x][y]!='B')
            {
                temp=(temp+safeside(x,y))%1000007;
            }
            else 
            {
                x+=dx[l];
                y+=dy[l];
                if(isvalid(x,y) and board[x][y]!='B')
                    temp=(temp+safeside(x,y))%1000007;
            }
        }
    }
    return dp[i][j]=temp;
}

void solve()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>board[i][j];
            if(board[i][j]=='W')
                {m=i;q=j;}
        }
    }
    memset(dp,-1,sizeof dp);
    cout<<safeside(m,q)<<endl;

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
    int counter=1;
    while(k--)
    {
        printf("Case %d: ",counter++);
        solve();
    }
    return 0;
}
