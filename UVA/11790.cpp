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
int h[10000];
int w[10000];
int dp[10000];
int t,n;
int lis,lds;
int cont = 1;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while(t--){
		cin >> n;
		REP(i,0,n){
			cin >> h[i];
		}
		REP(i,0,n){
			cin >> w[i];
		}
		memset(dp,0,sizeof dp);
		lis = 0;
		REP(i,0,n){
			dp[i] = w[i];
			REP(j,0,i){
				if(h[j] < h[i]){
					dp[i] = max(dp[i],dp[j] + w[i]);
				}
			}
			lis = max(lis,dp[i]);
		}
		memset(dp,0,sizeof dp);
		lds = 0;
		REP(i,0,n){
			dp[i] = w[i];
			REP(j,0,i){
				if(h[j] > h[i]){
					dp[i] = max(dp[i],dp[j] + w[i]);
				}
			}
			lds = max(lds,dp[i]);
		}
		cout << "Case " << cont++ << ". ";
		if(lis >= lds){
			cout << "Increasing ("<< lis << "). Decreasing (" << lds << ")." << endl;
		}else{
			cout << "Decreasing (" << lds << "). Increasing ("<< lis << ")." << endl;
		}
	}
	return 0;
}

