#include <iostream>
#include <fstream>
#include <map>

using namespace std;
char MostFrequentCharacter(ifstream &file, int &numOccurrences);

int main() {
    ifstream file;
    
    int numOccurences = 0;
    //stupid signature but w/e im just following orders :(
    char mostOccuredChar = MostFrequentCharacter(file, numOccurences);

    cout << "The most frequently seen character is: " << mostOccuredChar << " occurring " << numOccurences << " times." << endl;
}

char MostFrequentCharacter(ifstream &file, int &numOccurrences) {
    char result;
    map<char, int> mymap;
    string line;
    file.open("./map.txt");

    // Build frequency map
    while(getline(file, line)) {
        for(int i = 0; i < line.length(); i++) {
            char letter = tolower(line[i]);
            if (!mymap[letter]) {
                mymap[letter] = 1;
            } else {
                mymap[letter] = ++mymap[letter];
            }
        }
    }

    for(std::map<char,int>::iterator iter = mymap.begin(); iter != mymap.end(); ++iter) {
        char k = iter->first;
        int v = iter->second;

        // Set new most occured val/char
        if (v > numOccurrences) {
            numOccurrences = v;
            result = k;
        }
        cout << numOccurrences << endl;
        cout << "Key: " << k << " Val: " << v << endl;
    }
    return result;
}