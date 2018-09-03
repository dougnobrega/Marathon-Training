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
int ans = 0,OK = 0;
int v[16];
void backtracking(int row,int leftd,int rightd,int atual){
	if(row == OK){
		ans++;
		return;
	}
	int mask = OK & (~(row | leftd | rightd));
	mask &= v[atual];
	while(mask){
		int i = mask & -mask;
		mask ^= i;
		backtracking(row | i,(leftd | i) << 1, (rightd | i) >> 1,atual + 1);
	}
	return;
}
int main() {
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	int n;
	int cont = 1;
	while(cin >> n){
		if(n == 0)
			return 0 ;
		char x;
		ans = 0;
		OK = (1 << n)-1;
		REP(i,0,n){
			v[i] = OK;
		}
		REP(i,0,n){
			REP(j,0,n){
				cin >> x;
				if(x == '*'){
					v[j] = v[j] & ~(1<<i);
				}
			}
		}
		backtracking(0,0,0,0);
		cout << "Case " << cont++ << ": " << ans << endl;
	}
	return 0;
}

