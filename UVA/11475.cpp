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
#define MAXN 1000010
string t,p;
int m, n;
int b[MAXN];

void kmpPreprocess(){
	int j = -1,i = 0;
	b[0] = -1;
	while(i < m){
		while(j >= 0 && p[i] != p[j]) j = b[j];
		i++;
		j++;
		b[i] = j;
	}
}
int kmpSearch(){
	int j = 0, i = 0;
	while(i < n){
		while(j < m){
			if(t[i] == p[j]){
				i++; j++;
			}else{
				break;
			}
		}
		if(j == 0)
			i++;
		if(i == n)
			return j;
		j = b[j];
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while(cin >> p){
		t = p;
		reverse(all(p));
		m = p.size();
		n = t.size();
		kmpPreprocess();
		int ans = kmpSearch();
		p = t.substr(0,p.size() - ans);
		cout << t + string(p.rbegin(),p.rend())<< endl;
	}
	return 0;
}

