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
int graph[110][110];
ll dp[110][210];
uset<int> dest;

ll game(int p,int tour)
{
    if(tour>r)return INT_MIN;
    if(tour==r)
    {
        if(dest.count(p)!=0)
            return 0;
        return INT_MIN;
    }
    if(dp[p][tour]!=-1)return dp[p][tour];
    ll temp=INT_MIN;
    for(int i=1;i<=n;i++)
    {
        if(i==p)continue;
        temp=max( temp , graph[p][i] + game(i,tour+1) );

    }
    return dp[p][tour]=temp;
}

void solve()
{
    int counter=1;
    while(cin>>n>>m>>q>>r and !(n==0 and m==0 and q==0 and r==0) )
    {
        if(counter!=1)
        {
            cin.ignore();
        }
        counter++;
        memset(dp,-1,sizeof dp);
        int a,b;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>graph[i][j];
            }
        }
        dest.clear();
        for(int i=0;i<q;i++)
        {
            cin>>b;
            dest.insert(b);
        }
        memset(dp,-1,sizeof dp);
        cout<<max(0LL,game(m,0))<<endl;
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
