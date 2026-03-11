#include <bits/stdc++.h>
using namespace std;
int v, e;
int a[10000][10000] = {0};
int visited[10000] = {0};
void nhap(){
	cin >> v >> e;
	for(int k = 1; k <= e; k++){
		int x, y;
		cin >> x >> y;
		a[x][y] = 1;
		a[y][x] = 1;
	}
}

void dfs(int s){
	if(!visited[s]){
		visited[s] = 1;
		cout << s << " ";
		for(int i = 1; i <= v; i++){
			if(a[s][i] || a[i][s]){
				dfs(i);
			}
		}
	}
}

void bfs(int s){
	queue<int> hung;
	hung.push(s);
	visited[s] = 1;
	while(!hung.empty()){
		int k = hung.front();
		cout << k << " ";
		hung.pop();
		for(int i = 1; i <= v; i++){
			if((a[k][i] || a[i][k]) && !visited[i]){
				hung.push(i);
				visited[i] = 1;
			}
		}
	}
}

int main() {
	nhap();
	for(int i = 1; i <= v; i++){
		if(visited[i]) continue;
		dfs(i);
	}
	return 0;
}
