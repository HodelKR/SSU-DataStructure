#ifndef gameentry_h
#define gameentry_h

#include <iostream>
#include <string>

using namespace std;

class GameEntry{
public:
    GameEntry(const string n="", const int s=0);
    friend ostream& operator<<(ostream &os, const GameEntry &other);
    bool operator>(const GameEntry &other);
    string getName() const;
    int getScore() const;
private:
    string name;
    int score;
};

GameEntry::GameEntry(const string n, const int s){
    name = n;
    score = s;
}

string GameEntry::getName() const{
    return name;
}

int GameEntry::getScore() const{
    return score;
}

ostream& operator<<(ostream &os, const GameEntry &other){
    os << "[" + other.getName() + "]" + to_string(other.getScore());
    return os;
}

bool GameEntry::operator>(const GameEntry &other){
    return score > other.getScore();
}

#endif