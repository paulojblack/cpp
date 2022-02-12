
#include <iostream>
#include <string>

using namespace std;
string CensorString(string text, string censor);

int main() {
    cout << CensorString("THe Text Here", "he");
    return 0;
};

string CensorString(string text, string censor) {
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        bool found = false;
        for (int j = 0; j < censor.length(); j++) {
            if (censor[j] == tolower(text[i])) {
                found = true;
                cout << "Found a match: " << text[i] << "\n";
                break;
            }

        }
        if (found == false) {
            result += text[i];
        }
        found = false;
    }

    return result;
};