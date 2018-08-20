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
int bachelors[10010];
int spinsters[65];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int b,s;
	int c = 1;

	while(cin >> b >> s){
		if(b == 0 && s == 0)
			return 0;

		REP(i,0,b){
			cin >> bachelors[i];
		}
		memset(spinsters,0,sizeof spinsters);
		REP(i,0,s){
			int x;
			cin >> x;
			spinsters[x]++;
		}
		if(b <= s){
			cout << "Case " << c++ << ": " << 0 << endl;
			continue;
		}
		sort(bachelors,bachelors+b);
		reverse(bachelors,bachelors+b);
		int ult = 0;
		bool encontrei = false;

		REP(i,0,b){
			int low = bachelors[i];
			int high = low;
			encontrei = false;

			while(2 <= low || 60 >= high){
				if(spinsters[low] > 0){
					encontrei = true;
					spinsters[low]--;
					break;
				}
				if(spinsters[high] > 0){
					encontrei = true;
					spinsters[high]--;
					break;
				}
				if(60 >= high){
					high++;
				}
				if(2 <= low){
					low--;
				}
			}
			if(!encontrei){

				ult = i;
				break;
			}
		}
		if(!encontrei){
			cout << "Case " << c++ << ": " << b-ult << " " << bachelors[b-1] << endl;
			continue;
		}
		cout << "Case " << c++ << ": " << 0 << endl;
		continue;

	}
	return 0;
}

