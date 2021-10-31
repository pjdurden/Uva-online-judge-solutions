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
vvi arr;
int dp[33];
int parent[33];



void printpath(int ind)
{
    if(parent[ind]==ind)
    {
        cout<<arr[ind][m]<<" ";
    }
    else
    {
        cout<<arr[ind][m]<<" ";
        printpath(parent[ind]);
    }
}

bool comp(vi a,vi b)
{
    bool flag=true;
    for(int k=0;k<m;k++)
    {
        if(a[k]>b[k])
            {flag=false;break;}
    }
    return flag;
}

bool comps(vi a,vi b)
{
    bool flag=true;
    for(int k=0;k<m;k++)
    {
        if(a[k]>=b[k])
            {flag=false;break;}
    }
    return flag;
}

int longestpath(int ind)
{
    if(dp[ind]!=-1)return dp[ind];
    int res=1,temp;
    for(int i=ind+1;i<n;i++)
    {
        if(i==ind)continue;
        if(comps(arr[ind],arr[i]))
        {
            temp=longestpath(i);
            if( temp+1 > res )
            {
                res=temp+1;
                parent[ind]=i;
            }
        }
    }
    return dp[ind]=res;
}

void solve()
{
    while(cin>>n>>m and !(n==0 and m==0))
    {
        arr.clear();
        arr.resize(n);
        int k;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>k;
                arr[i].pb(k);
            }
            sort(begin(arr[i]),end(arr[i]));
            arr[i].pb(i+1);
        }
        sort(begin(arr),end(arr),comp);
        for(int i=0;i<n;i++)parent[i]=i;

        /* using LIS 
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            dp[i]=1;
            for(int j=0;j<i;j++)
            {
                bool flag=comp(arr[j],arr[i]);
                if(flag and dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                    parent[i]=j;
                }
            }
        }
        int maxind=0;
        int maxres=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]>maxres)
            {
                maxres=dp[i];
                maxind=i;
            }
        }
        */
        memset(dp,-1,sizeof dp);
        int maxres=longestpath(0);
        cout<<maxres<<endl;
        printpath(0);cout<<endl;

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
