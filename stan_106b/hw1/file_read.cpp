#include <iostream>
#include <fstream>

using namespace std;

struct score_stats {
    int min;
    int max;
    int avg;
};

int main() {
    string line;
    int num;
    int sum = 0;
    int counter = 0;
    score_stats s;

    ifstream myfile;
    myfile.open("./scores.txt");
    if(myfile.is_open()) {
        while (getline(myfile, line)) {
            counter++;
            num = stoi(line);
            if (!s.min || num < s.min) {
                s.min = num;
            }
            if (!s.max || num > s.max) {
                s.max = num;
            }
            sum = sum + stoi(line);

        }
    }
    myfile.close();
    s.avg = sum / counter;
    
    cout << "Avg is: " << s.avg << "\n";
    cout << "Min is: " << s.min << "\n";
    cout << "Max is: " << s.max << "\n";

    return 0;
};



