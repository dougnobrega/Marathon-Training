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
int dp[20010];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,m;

		cin >> m;
		cin >> n;
		vi moedas(n);

		REP(i,0,n){
			cin >> moedas[i];

		}
		memset(dp,0x3f,sizeof dp);
		dp[0] = 0;
		for(auto atual : moedas){
			for(int i = 20000;i >= atual;i--){
				dp[i] = min(dp[i],1 + dp[i - atual]);
			}
		}

		for(int i = m;i <= 20000 ;i++){
			if(dp[i] != INF){
				cout << i << " " << dp[i] << endl;
				break;
			}
		}

	}
	return 0;
}

