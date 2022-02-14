#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void ReverseQueue(queue<int> &q);
int main() {
    queue<int> qoo;
    qoo.push(1);
    qoo.push(2);
    qoo.push(3);
    qoo.push(4);

    cout << "Before, Front: " << qoo.front() << "\nBack: " << qoo.back() << endl;
    ReverseQueue(qoo);
    cout << "After, Front: " << qoo.front() << "\nBack: " << qoo.back() << endl;
    return 0;
}

void ReverseQueue(queue<int> &q) {
    stack<int> tmp;
    while (q.size()) {
        tmp.push(q.front());
        q.pop();
    }

    while(tmp.size()) {
        q.push(tmp.top());
        tmp.pop();
    }
    // cout << "tmpFront: " << tmp.front() << "\nBack: " << tmp.back() << endl;
    // q.swap(tmp);
};