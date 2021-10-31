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
int bestTime[26];
int cost[26];
vector<vi>edges;

int costs(int a)
{
    if(bestTime[a]!=-1)return bestTime[a];
    int t=0;
    for(int i=0;i<edges[a].size();i++)
        t=max(t,costs(edges[a][i]));
    t+=cost[a];
    return bestTime[a]=t;
}

void solve()
{
  
    string line;
    char task;
    string dependencies;
    edges.clear();
    edges.resize(26);
    memset(cost,0,sizeof cost);
    while (getline(cin, line) && line != "")
    {
        int pos = line[0] - 'A';
        stringstream ss(line);
        ss >> task >> cost[pos];
        
        if (ss >> dependencies)
        {
            for (int i = 0; i < dependencies.size(); ++i)
                edges[pos].push_back(dependencies[i] - 'A');
        }
    }
    memset(bestTime,-1,sizeof bestTime);
    for (int i = 0; i < 26; ++i)
    {
        costs(i);
    }
    int worstTime = 0;
    for (int i = 0; i < 26; ++i)
    {
        //cout<<bestTime[i]<<endl;
        worstTime = max(worstTime, bestTime[i]);
    }
    
    
    cout << worstTime << '\n';
    


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
    cin.ignore();
    cin.ignore();
    while(k--)
    {
        solve();  
        if(k!=0) cout<<endl;
    }
    return 0;
}
