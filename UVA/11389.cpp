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
int morning[101];
int evening[101];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,d,r;
	while(cin >> n >> d >> r){
		if(n == 0 && d == 0 && r == 0)
			return 0;
		REP(i,0,n){
			cin >> morning[i];
		}
		REP(i,0,n){
			cin >> evening[i];
		}
		sort(morning,morning+n);
		sort(evening,evening+n);
		reverse(evening,evening+n);
		int cont = 0;
		REP(i,0,n){
			//cout << evening[i] << " ";
			morning[i]+= evening[i];
			if(morning[i] > d )
				cont += morning[i] - d;
		}
		//cout << endl;
		cout << cont * r << endl;
	}
	return 0;
}

