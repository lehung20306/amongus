#include <bits/stdc++.h>
using namespace std;
int n, W;
typedef struct vinh{
	int a;
	int b;
} vinh;
vinh hung[105];
int X[105];
int f = -99999;
int rw, profit;

void nhap(){
	cin >> n >> W;
	for(int i = 1; i <= n; i++){
		cin >> hung[i].a;
	}
	for(int i = 1; i <= n; i++){
		cin >> hung[i].b;
	}
}

bool compare(const vinh& x, const vinh& y){
	return x.a / x.b > y.a / y.b;
}

void tryy(int k){
	int t = W / hung[k].b;
	for(int i = t; i >= 0; i--){
		X[k] = i;
		W -= i* hung[k].b;
		profit += i* hung[k].a;
		if(k == n){
			f = max(f, profit);
		}
		else{
			if(profit + W *  hung[k+1].a /  hung[k+1].b > f){
				tryy(k+1);
			}
		}
		profit -= i* hung[k].a;
		W += i* hung[k].b;
	}
}
int main(){
    nhap();
    sort(hung + 1, hung + n + 1, compare);
    rw = W;
    profit = 0;
    tryy(1);
    cout << f;
    return 0;
}
