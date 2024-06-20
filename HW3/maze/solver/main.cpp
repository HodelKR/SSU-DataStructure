#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

vector<string> map;
vector<vector<int>> cost;
vector<vector<pair<int, int>>> path;

void findPath(int n, int m){
	int dx[] = {0, 0, -1, 1};
	int dy[] = {-1, 1, 0, 0};
	
	queue<pair<int, int>> q;
	q.push({0, 1});
	cost[0][1] = map[0][1] - '0';
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if(nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
			if(map[nx][ny] == '0')continue;
            int newCost = cost[now.first][now.second] + map[nx][ny] - '0';
			if (newCost < cost[nx][ny]) {
				cost[nx][ny] = newCost;
				path[nx][ny] = {now.first, now.second};
				q.push({nx, ny});
			}
		}
	}
}
void printPath(int n, int m) {
    vector<pair<int, int>> vt;
    int x = n - 1, y = m - 2;
    while (x != -1 && y != -1) {
        vt.push_back({x, y});
        tie(x, y) = path[x][y];
    }
    reverse(vt.begin(), vt.end());
    int totalCost = 0;
    for (auto cur : vt) {
        totalCost += map[cur.first][cur.second] - '0';
        map[cur.first][cur.second] = '-';
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == '-') cout << '*';
            else cout << map[i][j];
        }
        cout << "\n";
    }
	cout << totalCost << "\n";
}
int main(int argc, char *argv[]){
	cin.tie(0),ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	cost.resize(n, vector<int>(m, INT_MAX));
	path.resize(n, vector<pair<int, int>>(m, {-1, -1}));
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		map.push_back(s);
	}
	findPath(n, m);
	printPath(n, m);
	return 0;
}
