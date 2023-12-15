#include <iostream>
#include <string>

using namespace std;

const int MAX_BOOKS = 100;

// Book structure
struct Book {
    string title;
    string author;
    int year;
};

// Library class
class Library {
private:
    Book books[MAX_BOOKS];
    int bookCount;

public:
    Library() : bookCount(0) {}

    // Function to add a book to the library
    void addBook(const Book& book) {
        if (bookCount < MAX_BOOKS) {
            books[bookCount++] = book;
            cout << "Book added successfully.\n";
        } else {
            cout << "Library is full. Cannot add more books.\n";
        }
    }

    // Function to display all books in the library
    void displayBooks() {
        if (bookCount == 0) {
            cout << "No books in the library.\n";
        } else {
            cout << "Library Books:\n";
            for (int i = 0; i < bookCount; ++i) {
                cout << "Title: " << books[i].title << ", Author: " << books[i].author << ", Year: " << books[i].year << endl;
            }
        }
    }

    // Function to search for a book by title
    void searchBook(const string& title) {
        bool found = false;
        for (int i = 0; i < bookCount; ++i) {
            if (books[i].title == title) {
                cout << "Book found:\n";
                cout << "Title: " << books[i].title << ", Author: " << books[i].author << ", Year: " << books[i].year << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Book not found.\n";
        }
    }
};

int main() {
    Library library;

    // Menu
    int choice;
    do {
        cout << "\nLibrary Management System Menu:\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Book newBook;
                cout << "Enter Book Title: ";
                cin.ignore(); // Ignore the newline character left in the buffer
                getline(cin, newBook.title);
                cout << "Enter Author: ";
                getline(cin, newBook.author);
                cout << "Enter Publication Year: ";
                cin >> newBook.year;
                library.addBook(newBook);
                break;
            }
            case 2:
                library.displayBooks();
                break;
            case 3: {
                string searchTitle;
                cout << "Enter Book Title to Search: ";
                cin.ignore(); // Ignore the newline character left in the buffer
                getline(cin, searchTitle);
                library.searchBook(searchTitle);
                break;
            }
            case 4:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 4);

    return 0;
}
