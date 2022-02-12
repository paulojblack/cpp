#include <iostream>

using namespace std;

double GetScoresAndAverage(int sentinel = -1);

int main()
{
    cout << GetScoresAndAverage(-1);
    
    return 0;
}

double GetScoresAndAverage(int sentinel) {
    int sum = 0;
    int value;
    int counter = 0;
    while(true) {
        cout << "Next val: ";
        cin >> value;
        if (value == sentinel) break;
        sum += value;
        counter++;
    }

    return double(sum)/counter;
}