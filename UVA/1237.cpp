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
	bool vdc = false;
	while(t--){
		int n;
		if(vdc)
			cout << endl;
		else
			vdc = true;
		cin >> n;
		vpi p(n);
		vector<string> name(n);
		REP(i,0,n){
			cin >> name[i] >> p[i].F >> p[i].S;
		}
		int q;
		cin >> q;
		while(q--){
			int v;
			cin >> v;
			int ans = 0;
			int cont = 0;
			REP(i,0,n){
				if(p[i].F <= v && p[i].S >= v ){
					ans = i;
					cont++;
				}
			}
			if(cont == 1)
				cout << name[ans] << endl;
			else
				cout << "UNDETERMINED" << endl;
		}
	}
	return 0;
}

