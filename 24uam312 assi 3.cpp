#include <iostream>
#include <cstring>
using namespace std;

class Book {
private:
    char* title;
    char* author;
    int pageCount;
    bool formatType; // true = Hardcover, false = Paperback
    float* chapterPages;
    int numChapters;

public:
    // Default Constructor
    Book() {
        title = new char[1];
        author = new char[1];
        title[0] = '\0';
        author[0] = '\0';
        pageCount = 0;
        formatType = false;
        numChapters = 0;
        chapterPages = nullptr;
    }

    // Parameterized Constructor
    Book(const char* t, const char* a, int pCount, bool format, int nChapters) {
        if (t == nullptr || a == nullptr || nChapters <= 0) {
            cerr << "Error: Invalid input provided." << endl;
            exit(EXIT_FAILURE);
        }

        title = new char[strlen(t) + 1];
        strcpy(title, t);

        author = new char[strlen(a) + 1];
        strcpy(author, a);

        pageCount = pCount;
        formatType = format;
        numChapters = nChapters;

        chapterPages = new float[numChapters];
        for (int i = 0; i < numChapters; i++) {
            chapterPages[i] = static_cast<float>(pageCount) / numChapters;
        }
    }

    // Copy Constructor (Deep Copy)
    Book(const Book& other) {
        title = new char[strlen(other.title) + 1];
        strcpy(title, other.title);

        author = new char[strlen(other.author) + 1];
        strcpy(author, other.author);

        pageCount = other.pageCount;
        formatType = other.formatType;
        numChapters = other.numChapters;

        chapterPages = new float[numChapters];
        for (int i = 0; i < numChapters; i++) {
            chapterPages[i] = other.chapterPages[i];
        }
    }

    // Destructor
    ~Book() {
        delete[] title;
        delete[] author;
        delete[] chapterPages;
    }

    // Modify Chapter Pages
    void modifyChapterPages(int index, float newPageCount) {
        if (index >= 0 && index < numChapters) {
            chapterPages[index] = newPageCount;
        } else {
            cout << "Invalid chapter index!" << endl;
        }
    }

    // Display Book Details
    void display() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Page Count: " << pageCount << endl;
        cout << "Format: " << (formatType ? "Hardcover" : "Paperback") << endl;
        cout << "Chapters: " << numChapters << endl;
        cout << "Pages per Chapter: ";
        for (int i = 0; i < numChapters; i++) {
            cout << chapterPages[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    // Demonstrating Default Constructor
    cout << "Default Constructor Example:\n";
    Book book1;
    book1.display();
    cout << "\n";
    
    // Demonstrating Parameterized Constructor
    cout << "Parameterized Constructor Example:\n";
    Book book2("C++ Programming", "Bjarne Stroustrup", 500, true, 10);
    book2.display();
    cout << "\n";
    
    // Demonstrating Copy Constructor (Deep Copy)
    cout << "Copy Constructor Example:\n";
    Book book3 = book2;
    book3.display();
    cout << "\n";
    
    // Modify a chapter in book3 and show independence from book2
    book3.modifyChapterPages(2, 60);
    cout << "After Modifying Book3 Chapter 2:\n";
    book3.display();
    cout << "\nOriginal Book2 remains unchanged:\n";
    book2.display();
    
    return 0;
}

