
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



using namespace std;

const int maxn = 121;
const int maxm = 16;
const int inf = 1e9;

char name[15];
int n, m;
int dist[maxn][maxm];

void reset(){
    for (int i=0; i < maxn; i++){
        for (int j=0; j < maxm; j++){
            dist[i][j] = (i == 0 ? 0 : inf);
        }
    }
}

bool input(){
    int cont = scanf(" %s", &name);

    if (cont != 1) return false;

    reset();

    scanf(" %d %d", &n, &m);

    for (int k=0; k < (n - 1); k++){
        for (int i=1; i <= m; i++){
            for (int j=1; j <= m; j++){
                int travel_cost;
                scanf(" %d", &travel_cost);
                dist[k + 1][j] = min(dist[k + 1][j], dist[k][i] + travel_cost + 2);
            }
        }
    }

    return true;

}

void output(){
    int lo = 1e9;

    for (int i=1; i <= m; i++){
        lo = min(lo, dist[n - 1][i]);
    }

    printf("%s\n%d\n", name, lo);
}

int main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);

    while (input()){
        output();
    }
}