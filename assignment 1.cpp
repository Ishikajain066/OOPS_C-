#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Book {
private:
    int book_id;
    string title;
    string author;
    string genre;
    bool is_available;

public:
    Book(int id, const string& t, const string& a, const string& g)
        : book_id(id), title(t), author(a), genre(g), is_available(true) {}

    int getBookID() const { return book_id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getGenre() const { return genre; }
    bool isAvailable() const { return is_available; }

    void borrowBook() {
        if (is_available) is_available = false;
        else cout << "Book \"" << title << "\" is already borrowed.\n";
    }

    void returnBook() {
        if (!is_available) is_available = true;
        else cout << "Book \"" << title << "\" is already available.\n";
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(int book_id, const string& title, const string& author, const string& genre) {
        for (const auto& book : books) {
            if (book.getBookID() == book_id) {
                cout << "Book with ID " << book_id << " already exists.\n";
                return;
            }
        }
        books.emplace_back(book_id, title, author, genre);
        cout << "Book \"" << title << "\" added to the library.\n";
    }

    void removeBook(int book_id) {
        auto it = remove_if(books.begin(), books.end(),
                            [book_id](const Book& book) { return book.getBookID() == book_id; });
        if (it != books.end()) {
            books.erase(it, books.end());
            cout << "Book with ID " << book_id << " removed from the library.\n";
        } else {
            cout << "Book with ID " << book_id << " not found.\n";
        }
    }

    void borrowBook(int book_id) {
        for (auto& book : books) {
            if (book.getBookID() == book_id) {
                if (book.isAvailable()) {
                    book.borrowBook();
                    cout << "You have borrowed \"" << book.getTitle() << "\".\n";
                } else {
                    cout << "Book \"" << book.getTitle() << "\" is already borrowed.\n";
                }
                return;
            }
        }
        cout << "Book with ID " << book_id << " not found.\n";
    }

    void returnBook(int book_id) {
        for (auto& book : books) {
            if (book.getBookID() == book_id) {
                book.returnBook();
                cout << "Book \"" << book.getTitle() << "\" has been returned.\n";
                return;
            }
        }
        cout << "Book with ID " << book_id << " not found.\n";
    }

    void listAvailableBooks() const {
        cout << "Available books:\n";
        for (const auto& book : books) {
            if (book.isAvailable()) {
                cout << "- " << book.getTitle() << " by " << book.getAuthor() << "\n";
            }
        }
    }

    void listBorrowedBooks() const {
        cout << "Borrowed books:\n";
        for (const auto& book : books) {
            if (!book.isAvailable()) {
                cout << "- " << book.getTitle() << " by " << book.getAuthor() << "\n";
            }
        }
    }
};

int main() {
    Library library;

    library.addBook(1, "The Great Gatsby", "F. Scott Fitzgerald", "Fiction");
    library.addBook(2, "1984", "George Orwell", "Dystopian");
    library.addBook(3, "To Kill a Mockingbird", "Harper Lee", "Classic");

    library.borrowBook(2);

    library.listAvailableBooks();
    library.listBorrowedBooks();

    library.returnBook(2);

    library.removeBook(3);

    library.listAvailableBooks();
    library.listBorrowedBooks();

    return 0;
}

