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
ll arr[610];
ll dp[610][310];

bool check(int res)
{
    ll sum=0,count=0;
    //cout<<res<<endl;
    for(int i=1;i<=n+1;i++)
    {
        sum+=arr[i];
        if(arr[i]>res)return false;
        if(sum>res)
        {
            sum=arr[i];count++;
        }
    }
    if(sum)
        count++;
    return count<=m;
}

/*
ll safeside(int day,int night)
{
    if(night==m)
    {
        return arr[n]-arr[day];
    }
    if(dp[day][night]!=-1)return dp[day][night];
    ll ans=INT_MAX;
    ll temp=0;
    for(int i=day+1;i<=n;i++)
    {
        temp=max( arr[i]-arr[day] , safeside(i,night+1) );
        ans=min(temp,ans);
    }
    return dp[day][night]=ans;
}
*/

int bisection()
{
    int l=0;int r=100000,mid;
    arr[n+1]=0;
    m++;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(check(mid))
            r=mid-1;
        else l=mid+1;
    }
    return r+1;
}

void solve()
{
    while(cin>>n>>m)
    {
        n++;
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
        }
        arr[0]=0;
        /*
        memset(dp,-1,sizeof dp);
        for(int i=1;i<=n;i++)
        {
            arr[i]+=arr[i-1];
        }
        cout<<safeside(0,0)<<endl;
        */
        cout<<bisection()<<endl;

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
