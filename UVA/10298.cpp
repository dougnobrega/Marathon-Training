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
#define MAXN 1000100
int n,m;
string p;
int b[MAXN];
int cont = 0;
int kmpPreprocess(int i = 0, int j = -1){
	b[0] = -1;
	while(i < m){
		while(j >= 0 && p[i] != p[j]) j = b[j];
		i++;
		j++;
		b[i] = j;
	}
	return b[i];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	while(cin >> p){
		if(p == ".")
			break;
		m = p.size();
		int result = kmpPreprocess();
		if(m%(m-result) == 0)
			cout << m/(m-result) << endl;
		else
			cout << 1 << endl;
	}
	return 0;
}

