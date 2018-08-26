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
int dp[210][22][20];
int n,q,d,m;
int a[220];
int solve(int i, int resto,int qtd){
	if(qtd == m)
		return resto == 0;
	if(i == n)
		return 0;
	if(resto >= 0 && dp[i][resto][qtd] != -1)
		return dp[i][resto][qtd];
	return dp[i][resto][qtd] = solve(i+1,resto,qtd) + solve(i+1,((d+(resto + a[i])%d))%d ,qtd + 1);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cont = 1;
	while(cin >>n >> q){
		if(n == 0 && q == 0)
			break;
		cout << "SET " << cont++ << ":" << endl;
		REP(i,0,n){
			cin >> a[i];
		}
		REP(i,0,q){
			cin >> d >> m;
			memset(dp,-1,sizeof dp);
			cout << "QUERY " << i+1 << ": " <<solve(0,0,0) << endl;
		}
	}
	return 0;
}

