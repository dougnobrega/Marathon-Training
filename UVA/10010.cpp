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
char grid[55][55];
int dx[] = {-1,-1,-1,0,0,1,1,1} , dy[] = {-1,0,1,-1,1,-1,0,1};
int n,m;
int p = 0, linha, coluna;
string a;

bool find(int i, int j,int atual,int k){
	 if(atual == p)
		 return 1;
	 if(i < 0 || j < 0)
		 return 0;
	 if(i >= n || j >= m)
		 return 0;
	 int x = dx[k] + i;
	 int y = dy[k] + j;
	 if(grid[x][y] == a[atual]){
		return find(x,y,atual+1,k);
	 }
	 return 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	bool end = false;
	while(t--){
		cin >> n >> m;
		if(end == true)
			cout << endl;
		else
			end = true;
		REP(i,0,n){
			REP(j,0,m){
				cin >> grid[i][j];
				grid[i][j] = tolower(grid[i][j]);
			}
		}
		int q;
		cin >> q;
		REP(i,0,q){
			cin >> a;
			p = a.size();
			REP(i,0,p){
				a[i] = tolower(a[i]);
			}
			bool deu = false;
			REP(j,0,n){
				REP(o,0,m){
					if(a[0] == grid[j][o]){
						linha = j + 1;
						coluna = o + 1;
						REP(l,0,8){
							if(find(j,o,1,l)){
								cout << linha << " " << coluna << endl;
								deu = true;
								break;
							}
						}
						if(deu) break;
					}
				}
				if(deu) break;
			}
		}
	}
	return 0;
}

