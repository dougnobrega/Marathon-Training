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
#define MAXN 1100
string a,b;
int dp[MAXN][MAXN];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int  t;
	cin >> t;
	cin.ignore();
	while(t--){

		getline(cin,a);
		memset(dp,0,sizeof dp);
		int tam = a.size();
		REP(i,1,tam+1){
			REP(j,1,tam+1){
				int aux = 1;
				if(a[i-1] != a[tam-j]){
					aux = -INF;
				}
				dp[i][j] = max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1] + aux));
			}
		}
		cout << dp[tam][tam] << endl;
	}
	return 0;
}

