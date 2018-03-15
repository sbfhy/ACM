//  Edu 39
#include<bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
#define rep(i,a,b) for (int i=a; i<=b; ++i)
#define per(i,b,a) for (int i=b; i>=a; --i)
#define mes(a,b)  memset(a,b,sizeof(a))
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define fi  first
#define se  second
typedef long long ll;
const int N = 505;

int n, m, k, f[N], g[N][N], dp[N][N];
char s[N];
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    int sum1 = 0;
    rep(i,1,n)
    {
        scanf("%s", s+1);
        int sum=0;
        rep(j,1,m) if(s[j]=='1') f[++sum]=j;
        sum1 += sum;
        rep(j,0,sum-1) g[i][j]=INF;
        rep(j,0,sum-1) rep(l,0,j)
        {
            if(sum-(j-l)>0)
                g[i][j] = min(g[i][j], f[sum-(j-l)]-f[l+1]+1);
        }
    }
    if(sum1<=k) return printf("0\n"), 0;
    rep(i,1,n) rep(j,0,k)
    {
        dp[i][j] = INF;
        rep(l,0,j)
            dp[i][j] = min(dp[i][j], dp[i-1][j-l]+g[i][l]);
    }
    printf("%d\n", dp[n][k]);

    return 0;
}
