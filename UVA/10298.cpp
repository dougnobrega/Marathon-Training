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
string p,t;
int b[MAXN];
int cont = 0;
void kmpPreprocess(int i = 0, int j = -1){
	b[0] = -1;
	while(i < m){
		while(j >= 0 && p[i] != p[j]) j = b[j];
		i++;
		j++;
		b[i] = j;
	}
}
void kmpSearch(){
	int i = 0,j = 0;
	cont = 0;
	while(i < n){
		while(j>=0 && t[i] != p[j]) j = b[j];
		i++;
		j++;
		if(j == m){
			cont++;
			j = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	while(cin >> t){
		if(t == ".")
			break;
		n = t.size();
		p = t;
		m = 1;
		cont = 0;
		while(1){
			if(n%m == 0){
				kmpPreprocess();
				kmpSearch();
				if(cont == n/m){
					break;
				}
			}
			if(m > n/2){
				cont = 1;
				break;
			}
			m++;
		}
		cout << cont << endl;
	}
	return 0;
}

