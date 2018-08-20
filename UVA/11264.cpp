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
vi coins;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 0;
	cin >> t;
	ll sum = 0;
	while(t--){
		int c;
		cin >> c;
		coins.resize(c);
		REP(i,0,c){
			cin >> coins[i];
		}
		sum = 0;
		REP(i,0,c){
			if(coins[i] <= sum){
				sum -= coins[i-1];
				sum += coins[i];
			}else{
				sum += coins[i];
			}
		}
		int i = c-1;
		int cont = 0;
		while(sum != 0){
			while(coins[i] > sum) i--;
			sum %= coins[i];
			cont ++;
			i--;
		}
		cout << cont << endl;
	}
	return 0;
}

