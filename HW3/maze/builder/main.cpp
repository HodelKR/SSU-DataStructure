#include <iostream>
#include <ctime>
#include <vector>
#include <random>
using namespace std;

vector<vector<int>> map;

void init( int n, int m){
	map.resize(n, vector<int>(m, 0));
}
void printMap(){
	for(auto i : map){
		for(auto j : i){
			cout << j;
		}
		cout << "\n";
	}
}
void makePath(int x, int y, int n, int m){
	int dx[] = {0, 0, -1, 1};
	int dy[] = {-1, 1, 0, 0};

	map[x][y] = rand() % 9 + 1;

	if(map[n-1][m-2] > 0){
		return;
	}
	int k = rand() % 10;
	for(int i=0;i<4;i++){
		int nx = x + dx[(i+k) % 4];
		int ny = y + dy[(i+k) % 4];
		
		if(nx == n-1 && ny == m-2){
			makePath(nx, ny, n, m);
		}
		if(nx <= 0 || ny <= 0 || nx >= n-1 || ny >= m-1)continue;
		if(map[nx][ny] > 0)continue;
		makePath(nx, ny, n, m);
	}
}
int main(int argc, char *argv[]){
	cin.tie(0),ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	srand(time(0));
	init(n, m);
	makePath(0, 1, n, m);
	printMap();
	return 0;
}