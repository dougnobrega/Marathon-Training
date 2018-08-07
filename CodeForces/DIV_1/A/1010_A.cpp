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
#define endl '\n'
double gasolina, peso;
vector<double> a;
vector<double> b;
int n;
bool vdc = false;
bool dfs(int x){
	if(vdc == false){
		vdc = true;
		if(gasolina < (gasolina+peso)/a[x]){
			//cout << "entrou" << endl;
			return 0;
		}
		gasolina -= (gasolina+peso)/a[x];
	}else{
		if(gasolina < (gasolina+peso)/b[x]){
				//cout << "entrou" << endl;
					return 0;
			}
		gasolina -= (gasolina+peso)/b[x];
		if(x == 0){
			//cout << gasolina << endl;
			return 1;
		}
		if(gasolina < (gasolina+peso)/a[x]){
			//cout << "entrou" << endl;
			return 0;
		}
		gasolina -= (gasolina+peso)/a[x];
	}
	return dfs((x+1)%n);
}
							// Define's end //

int main() {
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	int m;
	cin >> n >> m;
	a.resize(n);
	b.resize(n);
	peso = m;
	REP(i,0,n){
		cin >> a[i];
		//a[i] *=1000000;
	}
	REP(i,0,n){
		cin >> b[i];
		//b[i] *=1000000;
	}
	double x = 0, y = 1e9+10;
	double result = -1;
	REP(i,0,1000){
		double mid = (x+y)/2.0;
		gasolina = mid;
		vdc = false;
		if(dfs(0)){
			//cout << mid << endl;
			result = mid;
			y = mid;
		//	break;
		}
		else x = mid;
	}
	printf("%.10lf\n", result);
	return 0;
}
