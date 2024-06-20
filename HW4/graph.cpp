#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <queue>
#include <stack>
#include "graph.h"

using namespace std;

void Graph::LoadMatrix(string input){
    ifstream inputFile(input);
    if (!inputFile.is_open()) {
        cerr << "파일을 열 수 없습니다." << std::endl;
        return;
    }
    inputFile >> nodes;
    graph.resize(nodes, std::vector<int>(nodes));
    for (int i=0;i<nodes;i++) {
        for (int j=0;j<nodes;j++) {
            inputFile >> graph[i][j];
        }
    }
}
void Graph::PrintMatrix(){
    for (int i=0;i<nodes;i++) {
        for (int j=0;j<nodes;j++) {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
}

int Graph::GetSize(){
    return nodes;
}

void Graph::PrintShortestPathWeight(int s){
    queue<int> q;
    q.push(s);
    vector<int> vst(nodes, 5000);
    vst[s] = graph[s][s];
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=0;i<nodes;i++){
            if(i==now)continue;
            if(graph[now][i]==999)continue;
            int cost = vst[now] + graph[now][i];
            if(cost < vst[i]){
                vst[i] = cost;
                q.push(i);
            }
        }
    }
    for(int i=0;i<nodes;i++){
        if(vst[i]==5000)cout << "999\n";
        else cout << vst[i] <<"\n";
    }
}

void Graph::PrintShortestPath(int s){
    queue<int> q;
    q.push(s);
    vector<int> vst(nodes, 5000);
    vector<int> path(nodes, -1);
    vst[s] = graph[s][s];
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=0;i<nodes;i++){
            if(i==now)continue;
            if(graph[now][i]==999)continue;
            int cost = vst[now] + graph[now][i];
            if(cost < vst[i]){
                vst[i] = cost;
                path[i] = now;
                q.push(i);
            }
        }
    }
    stack<int> st;
    for(int i=0;i<nodes;i++){
        if(i==s)continue;
        for(int x=i; x!=s && x != -1;x=path[x]){
            st.push(x);
        }
        st.push(s);
        while(!st.empty()){
            cout << st.top() << " ";
            st.pop();
        }
        cout << "\n";
    }
}

