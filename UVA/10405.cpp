#include <bits/stdc++.h>

using namespace std;
							// Typedef's  start //
typedef long long   ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii > vpi;

							//	Typedef's end //
							//	Define's start //
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i = a; i < (b); i++)
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)*(b))/__gcd((a), (b)))

							// Define's end //
#define MAXN 1000010
int dp[1010][1010];
char a[1010],b[1010];
int main() {
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	while(scanf(" %[^\n]",a) != EOF){
		scanf(" %[^\n]",b);
		memset(dp,0,sizeof dp);
		int tam_a = strlen(a), tam_b = strlen(b);
		REP(i,1,tam_a + 1){
			REP(j,1,tam_b + 1){
				int aux = 1;
				if(a[i-1] != b[j-1])
					aux = 0;
				dp[i][j] = max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1] + aux));
			}
		}
		cout << dp[tam_a][tam_b] << endl;
	}

	return 0;
}

