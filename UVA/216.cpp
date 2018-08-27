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
int n;
double dist[20][20];
double dp[20][1<<16];
vpi cord;
double solve(int last, int mask){
	if(mask == (1 << n) - 1){
		return dp[last][mask] = 0;
	}
	if(dp[last][mask] != -1)
		return dp[last][mask];
	double ans = INF;
	REP(i,0,n){
		if(i != last && !(mask & (1 << i))){
			ans = min(ans,dist[last][i] + solve(i,mask | (1 << i)));
		}
	}
	return dp[last][mask] = ans;
}

int main() {
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	int cont = 1;
	while(cin >> n && n){
		cout << "**********************************************************" << endl;
		cord.resize(n);
		REP(i,0,n){
			cin >> cord[i].F >> cord[i].S;
		}
		REP(i,0,n){
			REP(j,0,n){
				dist[i][j] = sqrt((cord[i].F-cord[j].F)*(cord[i].F-cord[j].F) + (cord[i].S-cord[j].S)*(cord[i].S-cord[j].S));
				if(i != j)
					dist[i][j] += 16;
			}
		}
		cout << "Network #" << cont++ << endl;
		double ans = INF;
		REP(i,0,n){
			REP(j,0,n){
				REP(k,0,(1 << n) + 1){
					dp[j][k] = -1;
				}
			}
			ans = min(ans,solve(i,1<<i));
		}
		int k = 0, mask = 0;
		REP(i,0,n){
			REP(j,0,n){
				REP(k,0,(1 << n) + 1){
					dp[j][k] = -1;
				}
			}
			if(ans == solve(i,1<<i)){
				mask = 1<<i;
				k = i;
				break;
			}
		}
		int i = k;
		while(dp[i][mask] != 0 ){
			REP(j,0,n){
				if(j != i && !(mask & (1 << j)) && dp[i][mask] == dist[i][j] + dp[j][mask|(1<<j)]){
					cout << "Cable requirement to connect (" << cord[i].F << ',' << cord[i].S << ") to (";
					cout << cord[j].F << ',' << cord[j].S << ") is " <<setprecision(2) << fixed << dist[i][j] << " feet." << endl;
					i = j;
					mask |= 1<<j;
					break;
				}
			}
		}
		cout << "Number of feet of cable required is "<< setprecision(2) << fixed << ans << "." << endl;

	}
	return 0;
}

