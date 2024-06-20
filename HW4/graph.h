#ifndef graph_h
#define graph_h
#include <vector>
#include <string>
using namespace std;

class Graph{
private:
	vector<vector<int>> graph;
    int nodes;
public:
    void LoadMatrix(string input);
    void PrintMatrix();
    int GetSize();
    void PrintShortestPathWeight(int s);
    void PrintShortestPath(int s);
};

#endif