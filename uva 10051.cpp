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
int boxes[550][6];
string side[]={"front", "back", "left", "right", "top","bottom"};
int sides[]={1,0,3,2,5,4};
pi parent[550][6];
int dp[550][6];
int besti,bestj;

int cubes(int box,int col)
{
    if(box!=-1)
    {
        if(dp[box][col]!=-1 )
            return dp[box][col];
    }
    //cout<<box<<" "<<col<<endl;
    int temp=0,res;
    for(int i=box+1;i<n;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(col==-1 or boxes[box][col]==boxes[i][j])
            {
  //              if(box==0 and col==1)cout<<i<<" "<<j<<endl;
                res=cubes( i,sides[j] );
                if( (res + 1) > temp )
                {
                    temp=res+1;
                    if(box==-1 and col==-1){besti=i;bestj=sides[j];}
                    if(box!=-1 and col!=-1)parent[box][col]={i,sides[j]};
                }
            }
        }
    }
    if(box==-1 and col==-1)return temp;
    return dp[box][col]=temp;
}   

void printpath(int a,int b)
{
    if(parent[a][b]==make_pair(a,b))
    {
        cout<<a+1<<" "<<side[b]<<endl;
        return;
    }
    cout<<a+1<<" "<<side[b]<<endl;
    printpath(parent[a][b].first,parent[a][b].second);
}


void solve()
{
    int counter=1;
    while(cin>>n and n!=0)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<6;j++)
                cin>>boxes[i][j];
        for(int i=0;i<550;i++)
        {
            for(int j=0;j<6;j++)
            {
                parent[i][j]={i,j};
            }
        }
        memset(dp,-1,sizeof dp);
        int res=cubes(-1,-1);
        printf("Case #%d\n",counter++);
        cout<<res<<endl;
        printpath(besti,sides[bestj]);

        
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
