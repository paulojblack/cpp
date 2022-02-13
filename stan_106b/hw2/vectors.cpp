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
    cout << emails[0].to;
    return 0;
};

void RemoveEmails(vector<eMailMsg> &emails) {
    // Gonna get real ugly with this
    vector<int> indicesToRemove;
    for (int i = emails.size() - 1; i >=0; i--) {
        // Add idx to removal list if rfind at string idx 0 returns a find
        // if (emails[i].subject.rfind("SPAM", 0) != std::string::npos) {
        //     emails.erase(i);
        // }
    }

    remove_if(emails.begin(), emails.end(), ShouldRemove);
    cout << "inline size: " << emails.size() << endl;
    // for (int i = 0; i < indicesToRemove.size(); i++) {
    //     cout << indicesToRemove[i] << endl;
    //     emails.erase(emails.begin()+indicesToRemove[i]);
    // }

    // cout << emails.size();
};

bool ShouldRemove(eMailMsg &e) {

    if (e.subject.rfind("SPAM", 0) != std::string::npos){
        cout << "FOUND~!" << endl;
        return false;
    }

    return true;
};