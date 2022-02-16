#include <iostream>
#include <set>

using namespace std;

struct entryT
{
    string firstName;
    string lastName;
    string phoneNumber;
};

struct Compyrator {
    bool operator() (const entryT &lh, const entryT &rh) {
        if (lh.lastName < rh.lastName) {
            return 1;
        } else if (lh.lastName > rh.lastName) {
            return -1;
        } else if (lh.firstName < rh.firstName) {
            return 1;
        } else if (lh.firstName > rh.firstName) {
            return -1;
        }
        return 0;
    }
};

int main() {
    set<entryT, Compyrator> seeeet;
    entryT e1 = {"name1", "name1", "123"};
    entryT e2 = {"name2", "name2", "223"};
    entryT e3 = {"name3", "name3", "323"};
    seeeet.insert(e1);
    seeeet.insert(e2);
    seeeet.insert(e3);

    cout << seeeet.size() << endl;
    // for (int i; i < seeeet.size(); i++) {
    //     cout << seeeet;
    // }

    return 0;
};

