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
int n = 0;
string v;
ll dp[510];
ll solve(int i){

	if(i == n) return 0;
	if(dp[i] != -1LL){
		return dp[i];
	}
	ll ans = 0,tmp = 0;
	for(int j = i; j < n;j++){
		tmp = tmp * 10 + (ll)(v[j] - '0');
		if(tmp > 2147483647)
			break;
		ans = max(ans,solve(j+1) + tmp);
	}
	return dp[i] = ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> v;
		n = v.size();
		memset(dp,-1,sizeof dp);
		// cout << dp[0];
		cout << solve(0) << endl;
	}
	return 0;
}

