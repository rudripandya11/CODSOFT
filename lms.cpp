#include <iostream>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
    string isbn;
    bool borrowed;
    string issueDate;
    string returnDate;
};

Book library[100]; // Assuming a maximum of 100 books
int bookCount = 0;

void addBook() {
    Book newBook;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, newBook.title);
    cout << "Enter book author: ";
    getline(cin, newBook.author);
    cout << "Enter book ISBN: ";
    getline(cin, newBook.isbn);
    newBook.borrowed = false;
    library[bookCount] = newBook;
    bookCount++;
    cout << "Book added successfully!" << endl;
}

void viewBooks() {
    if (bookCount == 0) {
        cout << "The library is empty." << endl;
    } else {
        cout << "Books in the library:" << endl;
        for (int i = 0; i < bookCount; i++) {
            cout << "Title: " << library[i].title << endl;
            cout << "Author: " << library[i].author << endl;
            cout << "ISBN: " << library[i].isbn << endl;
            cout << "Borrowed: " << (library[i].borrowed ? "Yes" : "No") << endl;
            if (library[i].borrowed) {
                cout << "Issued on: " << library[i].issueDate << endl;
                cout << "Return by: " << library[i].returnDate << endl;
            }
        }
    }
}

string calculateReturnDate(string issueDate) {
    // Assuming date format is DD/MM/YYYY
    int day = stoi(issueDate.substr(0, 2));
    int month = stoi(issueDate.substr(3, 2));
    int year = stoi(issueDate.substr(6, 4));

    day += 7; // Adding 7 days

    // Adjust for month overflow
    int daysInMonth = 30; // Simplified; for actual implementation, consider different days in each month
    if (day > daysInMonth) {
        day -= daysInMonth;
        month++;
    }

    // Adjust for year overflow
    if (month > 12) {
        month -= 12;
        year++;
    }

    // Formatting the return date back to DD/MM/YYYY
    string returnDate = (day < 10 ? "0" : "") + to_string(day) + "/" + (month < 10 ? "0" : "") + to_string(month) + "/" + to_string(year);
    return returnDate;
}

void borrowBook() {
    string isbn;
    string issueDate;
    cout << "Enter the ISBN of the book you want to borrow: ";
    cin.ignore();
    getline(cin, isbn);
    cout << "Enter the borrow date (DD/MM/YYYY): ";
    getline(cin, issueDate);

    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].isbn == isbn) {
            found = true;
            if (!library[i].borrowed) {
                library[i].borrowed = true;
                library[i].issueDate = issueDate;
                library[i].returnDate = calculateReturnDate(issueDate);
                cout << "Book borrowed successfully!" << endl;
                cout << "Please return the book by: " << library[i].returnDate << endl;
            } else {
                cout << "This book is already borrowed." << endl;
            }
            break;
        }
    }

    if (!found) {
        cout << "We don't have that book in the library." << endl;
    }
}

void returnBook() {
    string isbn;
    string returnDate;
    cout << "Enter the ISBN of the book you want to return: ";
    cin.ignore();
    getline(cin, isbn);
    cout << "Enter the return date (DD/MM/YYYY): ";
    getline(cin, returnDate);

    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].isbn == isbn) {
            found = true;
            if (library[i].borrowed) {
                int issueDay = stoi(library[i].issueDate.substr(0, 2));
                int issueMonth = stoi(library[i].issueDate.substr(3, 2));
                int issueYear = stoi(library[i].issueDate.substr(6, 4));
                int returnDay = stoi(returnDate.substr(0, 2));
                int returnMonth = stoi(returnDate.substr(3, 2));
                int returnYear = stoi(returnDate.substr(6, 4));

                int issueDate = (issueYear * 10000) + (issueMonth * 100) + issueDay;
                int returnDate = (returnYear * 10000) + (returnMonth * 100) + returnDay;

                if (returnDate > issueDate) {
                    int fine = (returnDate - issueDate) *7;
                    cout << "Fine: " << fine << "Rs" << endl;
                } else {
                    cout << "Book returned successfully!" << endl;
                }

                library[i].borrowed = false;
                library[i].issueDate = "";
                library[i].returnDate = "";
            } else {
                cout << "This book is not borrowed." << endl;
            }
            break;
        }
    }

    if (!found) {
        cout << "We don't have that book in the library." << endl;
    }
}

void searchBook() {
    string searchQuery;
    cout << "Enter the ISBN, title, or author of the book to search: ";
    cin.ignore();
    getline(cin, searchQuery);

    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].title.find(searchQuery) != string::npos || library[i].author.find(searchQuery) != string::npos || library[i].isbn.find(searchQuery) != string::npos) {
            cout << "Title: " << library[i].title << endl;
            cout << "Author: " << library[i].author << endl;
            cout << "ISBN: " << library[i].isbn << endl;
            cout << "Borrowed: " << (library[i].borrowed ? "Yes" : "No") << endl;
            if (library[i].borrowed) {
                cout << "Issued on: " << library[i].issueDate << endl;
                cout << "Return by: " << library[i].returnDate << endl;
            }
            found = true;
        }
    }

    if (!found) {
        cout << "No book found matching the search query." << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "Library Management System" << endl;
        cout << "1. Add a book" << endl;
        cout << "2. View all books" << endl;
        cout << "3. Borrow a book" << endl;
        cout << "4. Return a book" << endl;
        cout << "5. Search for a book" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                borrowBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                searchBook();
                break;
            case 6:
                cout << "Exiting the library management system..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 6);

    return 0;
}