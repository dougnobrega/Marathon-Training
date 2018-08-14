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

vi p;
int n;
bitset<16> vis;
bitset<32> primos;
void backtracking(int i){
	if(i == n){
		if(primos[p.back() + 1])
			return;
		cout << p[0];
		REP(j,1,p.size()){
			cout << " " << p[j];
		}
		cout << endl;
		return;
	}
	REP(j,2,n+1){
		if(!vis[j] && !primos[p.back() + j]){
			vis[j] = 1;
			p.PB(j);
			backtracking(i+1);
			p.pop_back();
			vis[j] = 0;
		}
	}
	//cout << "loop";
}
void crivo(){
	REP(i,2,33){
		if(!primos[i]){
			REP(j,2,33){
				if(j*i >= 33)
					break;
				primos[j*i] = 1;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cont = 1;
	bool vdc = false;
	crivo();
	while(cin >> n){
		if(vdc)
			cout << endl;
		else
			vdc = true;
		cout << "Case " << cont++ << ':' << endl;
		vis[1] = 1;
		p.PB(1);
		backtracking(1);
		p.pop_back();

	}
	return 0;
}

