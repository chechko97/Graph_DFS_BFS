#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> Graph;
vector<bool> visited;

void DFS(int v) {
	visited[v] = true;
	cout << v + 1 << ' ';
	for (int child : Graph[v]) {
		if (!visited[child]) {
			DFS(child);
		}
	}
}

void BFS(int v) {
	queue<int> q;
	q.push(v);
	visited[v] = true;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		cout << temp + 1 << " ";
		for (int child : Graph[temp]) {
			if (visited[child] == false) {
				visited[child] = true;
				q.push(child);
			}
		}
	}

}

int main()
{
	int n, m;
	cout << "vertices = ";
	cin >> n;
	cout << "edges = ";
	cin >> m;
	Graph.resize(n);
	visited.resize(n);
	for (int i = 0; i < m; i++)	{
		int a, b;
		cout << "Insert edge: ";
		cin >> a >> b;
		Graph[a - 1].push_back(b - 1);
		//Graph[b - 1].push_back(a - 1);
	}

	for (int i = 0; i < n; i++) {
		cout << i + 1 << " --> ";
		for (int j = 0; j < Graph[i].size(); j++) {
			 cout << Graph[i][j] + 1 << ", ";
		}
		cout << '\n';
	}
	cout << "DFS:\n";
	DFS(0);
	visited.clear();
	visited.resize(n);
	cout << "\nBFS:\n";
	BFS(0);

	cout << '\n';
	system("pause");
	return 0;
}