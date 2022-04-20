#include <iostream>
#include <vector>
using namespace std;

// this function tryies swaping two edges descending from a and b
// requires: array of verticies info (prev, next), matrix of distances, verticies a and b
// returns: were edges swaped or were they not 
bool nodeswap (vector<pair<int,int>> &path, vector<vector<double>> &dist, int a, int b);

// this function goes through all verticies trying to minimize cycle length by swaping edges
// requires: array of verticies info (prev, next), matrix of distances
// returns: were any edges swaped or did the path remain unchaged
bool pathswap (vector<pair<int,int>> &path, vector<vector<double>> &dist);

// this function repeats simple pathswap while there is something to swap until reaching m itterations
// will guarantied work polynomial time
// requires: array of verticies info (prev, next), matrix of distances, max itteration number m
// returns: nothing
void m_pathswap (vector<pair<int,int>> &path, vector<vector<double>> &dist, int m);

// this function repeats simple pathswap while there is something to swap
// will guaranitied find local minimum
// requires: array of verticies info (prev, next), matrix of distances
// returns: number of itterations 
int full_pathswap (vector<pair<int,int>> &path, vector<vector<double>> &dist);
