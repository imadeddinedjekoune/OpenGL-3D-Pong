#ifndef MAZE_H
#define MAZE_H

#include "string"
#include "vector"
#include "unordered_map"
#include "queue"
#include "cstdlib"
#include "ctime"
#include <iostream>
#include "algorithm"
#include "stack"
using namespace std;


class Maze {
public:
	void maze(vector<vector<char>>& map);
	void showMaze(vector<vector<char>>& map);
	void _maze(vector<vector<char>>& map, int i, int j);
	int countVisitedNeighbor(vector<vector<char>>& map, int i, int j);
	void shuffle(int a[], int n);
	void swap(int& a, int& b);
	static vector<vector<char>> generate(int width, int height);
};

#endif
