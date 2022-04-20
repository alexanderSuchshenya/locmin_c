#include "locmin2nodeswap.h"
#include <math.h>
using namespace std;

int main()
{
	vector<double> x;
	vector<double> y;
	int N;

	cout << "number of verticies: ";
	cin >> N;
	cout << "verticies (pair {x,y}" << endl;
	for (int i = 0; i < N; i++)
	{
		double xin, yin;
		cin >> xin >> yin;
		x.push_back(xin);
		y.push_back(yin);
	}
	cout << "verticies initialized" << endl;

	vector<vector<double>> dist(N, vector<double>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			dist[i][j] = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
	cout << "distances initialized" << endl;

	vector<pair<int, int>> path(N);
	for (int i = 0; i < N-1; i++) path[i].second = i+1;
	for (int i = 1; i < N; i++) path[i].first = i-1;
	path[0].first = N-1;
	path[N-1].second = 0;
	cout << "path initialized" << endl;

	int m = 10;
	m_pathswap(path, dist, m);
	cout << 0 << " ";
	double sum = dist[0][path[0].second];
	int cur = path[0].second;
	while (cur != 0)
	{
		cout << cur << " ";
		sum = sum + dist[cur][path[cur].second];
		cur = path[cur].second;
	}
	cout << "reached local minimum of: " << sum << " at itteration " << m << endl << endl << endl;
	return 0;
}
