#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stack {
    vector<T> elements;
public:
    void push(T value) { elements.push_back(value); }
    void pop() { if (!elements.empty()) elements.pop_back(); }
    T top() const { return elements.back(); }
    bool isEmpty() const { return elements.empty(); }
};

int main() {
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.pop();
    if (!s.isEmpty()) cout << s.top() << endl;
    return 0;
}
