#include <iostream>
using namespace std;

class Book {
private:
    static int count;
    int bookID;

public:
    Book() {
        bookID = ++count;
    }

    static int getCount() {
        return count;
    }

    int getBookID() const {
        return bookID;
    }
};

int Book::count = 0;

int main() {
    Book b1, b2, b3;
    cout << "Book 1 ID: " << b1.getBookID() << endl;
    cout << "Book 2 ID: " << b2.getBookID() << endl;
    cout << "Book 3 ID: " << b3.getBookID() << endl;
    cout << "Total Books Created: " << Book::getCount() << endl;
    return 0;
}
