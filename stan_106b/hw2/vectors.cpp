#include <iostream>
#include <vector>

using namespace std;

struct eMailMsg {
    string to;      // i.e. "professor@stanford.edu"
    string from;    // i.e. "student@stanford.edu"
    string message; // body of message
    string subject; // i.e. "CS106 Rocks!"
    int date;       // date email was sent
    int time;       // time email was sent
};

void RemoveEmails(vector<eMailMsg> &emails);
bool ShouldRemove(eMailMsg &e);

    int main()
{
    vector<eMailMsg> emails;
    eMailMsg em1 = {"to@one.com", "from@one.com", "msgone", "SPAM: smd", 10, 1};
    eMailMsg em2 = {"to@two.com", "from@two.com", "msgtwo", "SPAM: kys lol", 10, 1};
    eMailMsg em3 = {"to@three.com", "from@three.com", "msgthree", "not SPAM: save mee", 10, 1};
    emails.push_back(em1);
    emails.push_back(em2);
    emails.push_back(em3);

    cout << "Size before removal: " << emails.size() << endl;
    RemoveEmails(emails);
    cout << "Size after removal: " << emails.size() << endl;

    for (int i = 0; i < emails.size(); i++) {
        cout << "Email " << i << " subject is: " << emails[i].subject << endl;
    }

    return 0;
};

void RemoveEmails(vector<eMailMsg> &emails) {
    // this is batshit
    // idk why i cant stick a lambda in the third arg of remove_if, but the compiler slaps me
    emails.erase(remove_if(emails.begin(), emails.end(), ShouldRemove), emails.end());
    cout << "inline size: " << emails.size() << endl;
 
};

bool ShouldRemove(eMailMsg &e) {
    // rfind, index 0 of subject string, if does NOT evaluate to not npos, i.e. does eval to found, return true, rm from vector
    if (e.subject.rfind("SPAM", 0) != std::string::npos){
        return true;
    }

    return false;
};