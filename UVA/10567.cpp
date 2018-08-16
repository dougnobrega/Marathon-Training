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
vi letters[150];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a;
	cin >> a;
	REP(i,0,(int)a.size()){
		letters[(int)a[i]].PB(i);
	}
	int q;
	cin >> q;
	string aux;
	REP(i,0,q){
		cin >> aux;
		bool vdc = true;
		int atual = -1,comp;
		int lo = INF, hi = -INF;
		REP(i,0,(int)aux.size()){
			comp = atual;
			atual = lower_bound(all(letters[(int)aux[i]]),atual+1) - letters[(int)aux[i]].begin();
			atual = letters[(int)aux[i]][atual];
			if(atual < comp){
				vdc = false;
				break;
			}
			lo = min(lo,atual);
			hi = max(hi,atual);
		}
		if(vdc){
			cout << "Matched "<< lo << " " << hi << endl;
		}else{
			cout << "Not matched" << endl;
		}
	}
	return 0;
}

