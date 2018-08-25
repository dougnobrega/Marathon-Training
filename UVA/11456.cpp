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
vi aux(3000);
deque<int> p;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,t;
	cin >> t;
	while(t--){
		cin >>n;
		p.clear();
		REP(i,0,n){
			int x;
			cin >> x;
			int menor = 0;
			int maior = 0;

			p.push_front(x);
			p.push_back(x);

		}
		int k = 0;

		REP(i,0,p.size()){
			int pos = lower_bound(aux.begin(),aux.begin()+k,p[i]) - aux.begin();
			if(pos == k)
				k++;
			aux[pos] = p[i];
		}
		cout << k << endl;
	}
	return 0;
}

