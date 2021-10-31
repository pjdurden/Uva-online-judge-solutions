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
vvi graph;
uset<int>special;
int dp[26][33];

int game(int p,int move)
{
    if(move==q)
    {
        if(special.count(p)!=0)
            return 1;
        return 0;
    }
    if(dp[p][move]!=-1)return dp[p][move];
    int temp=0;
    for(int i=0;i<2;i++)
    {
        temp+=game(graph[p][i],move+1);
    }
    return dp[p][move]=temp;
}

void solve()
{
    while(cin>>n)
    {
        char a,b,c,d;
        graph.clear();
        graph.resize(n);
        special.clear();
        for(int i=0;i<n;i++)
        {
            cin>>a>>b>>c>>d;
            graph[a-'A'].pb(b-'A');
            graph[a-'A'].pb(c-'A');
            if(d=='x')
            {
                special.insert(a-'A');
            }

        }
        cin>>q;
        memset(dp,-1,sizeof(dp));
        cout<<game(0,0)<<endl;

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
