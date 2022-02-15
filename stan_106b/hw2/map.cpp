#include <iostream>
#include <fstream>
#include <map>

using namespace std;
char MostFrequentCharacter(ifstream &file, int &numOccurrences);

int main() {
    ifstream file;
    
    int numOccurences;
    char mostOccuredChar = MostFrequentCharacter(file, numOccurences);
}

char MostFrequentCharacter(ifstream &file, int &numOccurrences) {
    map<char, int> butts;
    string line;
    file.open("./map.txt");
    while(getline(file, line)) {
        for(int i = 0; i < line.length(); i++) {
            cout << line[i] << endl;
        }
        cout << line << endl;
    }
    butts.insert(std::pair<char, int>('a', 100));
    cout << butts.count('a') << endl;
    cout << butts.count('b') << endl;
    return 'a';
}