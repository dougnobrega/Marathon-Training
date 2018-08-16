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
	int n;
	vi p;
	while(cin >> n){
		p.resize(n);
		REP(i,0,n){
			cin >> p[i];
		}
		sort(all(p));
		int v;
		cin >> v;
		int x = INF,y = 0;
		REP(i,0,n){
			int atual = v - p[i];
			int pos = lower_bound(all(p),atual) - p.begin();
			if(p[i] + p[pos] == v){
				if(abs(p[i] - p[pos]) < abs(x - y)){
					x = p[i];
					y = p[pos];
				}
			}
		}
		if(x > y)
			swap(x,y);
		cout << "Peter should buy books whose prices are "<< x <<" and "<< y <<"." << endl;
		cout << endl;
	}
	return 0;
}

