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
vvi edges;
vpi dist;

pi longpath(int a)
{
    if( dist[a] != make_pair(-1,-1) )return dist[a];
    pi temp={0,a};
    for(int i=0;i<edges[a].size();i++)
    {
        pi temp2=longpath(edges[a][i]);
        temp2.first++;
        if(temp2.first>temp.first or (temp2.first==temp.first and temp2.second<temp.second))
        {
            temp=temp2;
        }
    }
    return dist[a]=temp;
}

void solve()
{
    int counter=1;
    while(cin>>n and n!=0)
    {
        cin>>q;
        int a,b;
        edges.clear();
        edges.resize(n+1);
        dist.clear();
        dist.resize(n+1,make_pair(-1,-1) );//dist,end
        while(cin>>a>>b and !(a==0 and b==0))
        {
            edges[a].pb(b);
        }
        
        pi res=longpath(q);
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n"
            ,counter++,q,res.first,res.second);
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
