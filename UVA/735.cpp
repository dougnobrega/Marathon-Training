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
	vi ans;
	set<vi> combi[1000];
	REP(i,0,21){
		p.PB(i);
		if(i * 2>20){
			p.PB(i*2);
		}
		if(i * 3 > 20){
			p.PB(i*3);
		}
	}
	p.PB(50);
	sort(all(p));
	p.erase(unique(all(p)),p.end());
	REP(i,0,p.size()){
		REP(j,0,p.size()){
			REP(k,0,p.size()){
				int a = p[i], b = p[j] , c = p[k];
				vi comb = {a,b,c};
				sort(all(comb));
				ans.PB(a+b+c);
				combi[a+b+c].insert(comb);
			}
		}
	}
	sort(all(ans));

	while(cin >> n && n > 0){
		auto result = equal_range(all(ans),n);
		int combinacoes = combi[n].size();
		int permutacoes = result.S - result.F ;
		if(combinacoes == 0){
			cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS." << endl;
		}else{
			cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << combinacoes << "." << endl;
			cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << permutacoes << "." << endl;
		}
		cout << "**********************************************************************" << endl;
	}
	cout << "END OF OUTPUT" << endl;
	return 0;
}

