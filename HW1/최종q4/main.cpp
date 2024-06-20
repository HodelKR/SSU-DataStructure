// 아래와 같이 main함수에서 여러분이 작성한 list.h와 gameentry.h 파일을
// include 하여 주어진 동작을 실행하게 됩니다.
// *** 주의! 아래의 내용을 변경할 경우 오답처리될 수 있습니다. **
#include <iostream>
#include <string>
#include <sstream>
#include "list.h"
#include "gameentry.h"

using namespace std;

void handleInteger()
{
    int maxEntry;
    cin >> maxEntry;
    LinkedList<int> list(maxEntry);
    int score;
    while (true) {
        cin >> score;
        if (score < 0)
            break;
        list.add(score);
    }
    list.printReverse();
    cout << list.length() << endl;
}

void handleGameEntry()
{
    int maxEntry;
    cin >> maxEntry;
    LinkedList<GameEntry> list(maxEntry);
    string name;
    int score;
    while (true) {
        cin >> name;
        if (name == "quit")
        {
            break;
        }
        cin >> score;
        list.add(GameEntry(name, score));
    }
    list.print();
    cout << list.length() << endl;
}

int main(void)
{
    handleInteger();
    handleGameEntry();

    return 0;
}