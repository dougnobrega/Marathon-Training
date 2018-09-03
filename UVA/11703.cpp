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
ll dp[1000100];
int solve(int i){
	if(i == 0) return 1;
	if(dp[i] != -1)
		return dp[i];
	return dp[i] = (solve((int)floor(i-sqrt(i)))%1000000 + solve((int)floor(log(i)))%1000000 + solve((int)floor(i*sin(i)*sin(i)))%1000000)%1000000;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(dp,-1,sizeof dp);
	int x;
	solve(1000000);
	while(cin >> x){
		if(x == -1)
			break;
		cout << solve(x) << endl;
	}
	return 0;
}

