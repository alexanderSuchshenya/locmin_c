#include "locmin2nodeswap.h"
using namespace std;

bool nodeswap (vector<pair<int,int>> &path, vector<vector<double>> &dist, int a, int b)
{
	int anext = path[a].second,
	    bnext = path[b].second,
	    aprev = path[a].first,
	    bprev = path[b].first;

	// check if swaping will help minimize
	if (dist[a][anext] + dist[b][bnext] >
			dist[a][b] + dist[anext][bnext])
	{
		cout << "swap found" << endl;

		// replacing edges
		path[a].second = b;
	       	path[b].first = a;
		path[b].second = bprev;
		path[anext].first = path[anext].second;
		path[anext].second = bnext;
		path[bnext].first = anext;

		// flip part of the path
		int cur = bprev;
		while (cur != anext)
		{
			int tmp = path[cur].first;
			path[cur].first = path[cur].second;
			path[cur].second = tmp;
			cur = tmp;
		}
		cout << "-- edges swaped. path flipped";
		return true;
	}
	else
		return false;
}

bool pathswap (vector<pair<int,int>> &path, vector<vector<double>> &dist)
{
	// get path length
	int n = path.size();

	// remember were there any changes
	bool changed = false;

	// look through every verticie
	for (int a = 0; a < n; a++)
	{
		int b = 0;
		cout << "- searching swaps for verticie " << a << endl << "- at ";

		// stop trying to swap if a vertice already swaped
		bool stablenode = true;
		while (b < n && stablenode)
		{
			cout << b << " ";
			if(a != b) stablenode = !nodeswap(path, dist, a, b);
			b = b + 1;
		}
		cout << endl;

		// check were there any changes
		if (!stablenode) changed = true;
	}
	return changed;
}

void m_pathswap (vector<pair<int,int>> &path, vector<vector<double>> &dist, int m)
{
	int count = 0;

	// simple loop
	// try pathswaping
	// if failed or ran out of moves
	// --- stop
	while (pathswap(path, dist) && count < m)
	       count = count + 1;	
}

int full_pathswap (vector<pair<int,int>> &path, vector<vector<double>> &dist)
{
	int count = 0;
	
	// simple loop
	// try swaping
	// until there is nothing to swap
	// you shouldn't be worried about an infinite loop
	// as there is a certain minimum that will eventually be reached
	while (pathswap(path, dist))
		count = count + 1;
	return count;
}

