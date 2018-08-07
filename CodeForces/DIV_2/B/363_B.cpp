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
#define REP(i,a,b) for(int i = a; i < (int)(b); i++)
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define endl '\n'

							// Define's end //
bitset<100010> vis;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vi p(n+1);
	p[0] = 0;
	REP(i,1,n+1){
		cin >> p[i];
		p[i] += p[i-1];
	}

	int menor = INF;
	int ind = 0;
	REP(i,1,n+1){
		if(i+k-1 >= n+1){
			break;
		}
		if(menor > p[i+k-1] - p[i-1]){
			ind = i;
			menor = p[i+k-1] - p[i-1];
		}
	}
	cout << ind << endl;

	return 0;
}
