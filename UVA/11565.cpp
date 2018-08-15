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
	int a,b,c;
	int t;
	cin >> t ;
	while(t--){
		cin >> a >> b >> c;
		bool vdc = true;
		int xx=INF,yy=INF,zz=INF;
		REP(x,-100,101){
			REP(y,-100,101){
				int z = a - x - y;
				if(x == z || x == y || z == y)
					continue;
				if((x*y*z == b) && (x*x + y*y + z*z == c) && (x + y + z == a)){
					vdc = false;
					if(xx > x){
						xx = x;
						yy = y;
						zz = z;
					}else if(xx == x){
						if(yy > y){
							yy = y;
							zz = z;
						}
					}
				}
			}
		}

		if(vdc){
			cout << "No solution." << endl;
		}else{
			cout << xx << " " << yy <<  " " << zz << endl;
		}
	}
	return 0;
}

