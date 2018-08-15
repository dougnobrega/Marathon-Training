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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	vi p;
	while(t--){
		int v,n;
		cin >> v;
		cin >> n;
		p.resize(n);
		REP(i,0,n){
			cin >> p[i];
		}
		int tam = 1 << n;
		bool vdc = false;
		REP(i,0,tam){
			int sum = 0;
			REP(j,0,n){
				if(i & 1 << j)
					sum += p[j];
			}
			if(sum == v){
				cout << "YES" << endl;
				vdc = true;
				break;
			}
		}
		if(vdc)
			continue;
		cout << "NO" << endl;
	}
	return 0;
}

