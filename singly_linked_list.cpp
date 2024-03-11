/*Allow the addition and removal of products dynamically.
Singly Linked List:
1.Implement Library Catalog
- Design a system to keep track of books in a library
-Each node represents a book, and the linked list facilitates easy addition
and removal of books.
-Searching of a book by title / author name.
-Other customisations if you want to add*/ 

#include <iostream>
using namespace std;

class Linklist
{
    private:
        struct Node_B
        {
            int id;
            string title;
            string author;
            int quantity;
            Node_B*link;

            Node_B(int _id, string _title, string _author, int _quantity) : id(_id), title(_title), author(_author), quantity(_quantity), link(nullptr) {}

        }*START;
        struct Node_S
        {
            int id;
            string name;
            int borrowed_count;
            Node_B* borrowed_books[4];
            Node_S*link;

            Node_S(int _id, string _name) : id(_id), name(_name), borrowed_count(0), link(nullptr)
            {
                for (int i = 0; i < 4; ++i) 
                {
                    borrowed_books[i] = nullptr;
                }
            }

        }*HEAD;
    public:
        Linklist();
        ~Linklist();
        void book_list();
        void Students();
        void addBook(int id, string title, string author, int quantity);
        void removeBook(int id);
        void addStudent(int id, string name);
        void removeStudent(int id);
        void borrowBook(int student_id, int book_id);
        void returnBook(int student_id, int book_id);
        void searchByTitle(string title);
        void searchByAuthor(string author);
        void displayAllBooks();
        void displayAllStudents();
        void showMenu();
        string toLowerCase(const string& str);
};

Linklist::Linklist()
{
    START=NULL;
    HEAD=NULL;
}

Linklist::~Linklist()
{
    Node_B*b;
    while (START!=NULL)
    {
        b=START->link;
        delete START;
        START=b;
    }
    
    Node_S*s;
    while (HEAD!=NULL)
    {
        s=HEAD->link;
        delete HEAD;
        HEAD=s;
    }
}

void Linklist::addBook(int id, string title, string author, int quantity)
{
    Node_B* newBook = new Node_B(id,title,author,quantity);

    if (START == nullptr)
    {
        START= newBook;
    }
    else
    {
        Node_B*r =START;
        while (r->link !=nullptr)
        {
            r=r->link;
        }
        r->link = newBook;
    }
}

void Linklist::book_list()
{
    addBook(1, "Introduction to Algorithms", "Ronald L. Rivest", 20);
    addBook(2, "Advanced Data Structures", "Peter Brass", 15);
    addBook(3, "Grokking Algorithms: An Illustrated Guide for Programmers and Other Curious People", " Aditya Bhargava.", 20);
    addBook(4, "Data Structures Using C", "Reema Thareja", 30);
    addBook(5, "Cracking the coding interview", "Gayle Laakmann McDowell", 20);
}

void Linklist::removeBook(int id)
{
    Node_B*PTR=START,*prev;
    prev=nullptr;
    if (START == nullptr || START->link == nullptr) 
    {
        cout << "Cannot delete. library does not have enough books." << endl;
        return;
    }
    while(PTR != nullptr && PTR->id!= id)
    {
        prev=PTR;
        PTR=PTR->link;
    }
    if (PTR == nullptr || PTR == START) 
    {
        cout << "book id  " << id << " not found in library." << endl;
        return;
    }
    if (prev == nullptr) 
    {
        cout << "No book found to delete in library." << endl;
        return;
    }
    prev->link=PTR->link;
    delete PTR;
}

string Linklist::toLowerCase(const string& str)
{
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

void Linklist::searchByTitle(string title)

{
    Node_B* PTR=START;
    bool found=false;

    while (PTR !=nullptr)
    {
        if (!PTR->title.empty() && toLowerCase(PTR->title).find(toLowerCase(title)) != string::npos)
        {
            cout << "ID: " << PTR->id << endl;
            cout << "Title: " << PTR->title << endl;
            cout << "Author: " << PTR->author << endl;
            cout << "Quantity: " << PTR->quantity << endl;
            cout<<endl;
            found = true;
        }
        PTR=PTR->link;
    }

    if (!found)
    {
        cout<< "No books found with the title \"" << title << "\" in the library." << endl;
    }
}

void Linklist::searchByAuthor(string author)
{
    Node_B* PTR=START;
    bool found=false;

    while (PTR !=nullptr)
    {
        if (!PTR->author.empty() && toLowerCase(PTR->author).find(toLowerCase(author)) != string::npos)
        {
            cout << "ID: " << PTR->id << endl;
            cout << "Title: " << PTR->title << endl;
            cout << "Author: " << PTR->author << endl;
            cout << "Quantity: " << PTR->quantity << endl;
            cout<<endl;
            found = true;
        }
        PTR=PTR->link;
    }

    if (!found)
    {
        cout<< "No books found with the author \"" << author << "\" in the library." << endl;
    }
}

void Linklist::addStudent(int id, string name)
{
    Node_S* newStudent= new Node_S(id, name);

    if (HEAD==nullptr)
    {
        HEAD=newStudent;
    }
    else
    {
        Node_S*r=HEAD;
        while (r->link !=nullptr)
        {
            r=r->link;
        }
        r->link=newStudent;
    }
}

void Linklist::Students()
{
    addStudent(1,"Jeevan");
    addStudent(2,"Karunesh");
    addStudent(3,"Chaitanya");
    addStudent(4,"Lakshya");
    addStudent(5,"Rafe");
    addStudent(6,"Husain");
    addStudent(7,"Faheem");
}

void Linklist::removeStudent(int id)
{
    Node_S*PTR=HEAD,*prev;
    prev=nullptr;
    if (HEAD == nullptr || HEAD->link == nullptr) 
    {
        cout << "Cannot delete. list does not have enough Students." << endl;
        return;
    }
    while(PTR != nullptr && PTR->id!= id)
    {
        prev=PTR;
        PTR=PTR->link;
    }
    if (PTR == nullptr || PTR == HEAD) 
    {
        cout << "Student id  " << id << " not found in list." << endl;
        return;
    }
    if (prev == nullptr) 
    {
        cout << "No book found to delete in library." << endl;
        return;
    }
    prev->link=PTR->link;
    delete PTR;
}

void Linklist::borrowBook(int student_id, int book_id)
{
    cout<<"Enter the book id: "<<endl;
    cin>>book_id;
    Node_B*r=START;
    while(r!= nullptr && r->id!=book_id)
    {
        r=r->link;
    }
    if (r == nullptr)
    {
        cout << "Book with ID " << book_id << " not found." << endl;
        return;
    }
    if (r->quantity <= 0)
    {
        cout << "Book " << r->title << " is not available for borrowing." << endl;
        return;
    }

    cout<<"Enter Student id no: "<<endl;
    cin>>student_id;
    Node_S*q=HEAD;
    while (q != nullptr && q->id!=student_id)
    {
        q=q->link;
    }
    
    if (q==nullptr)
    {
        cout << "Student with ID " << student_id << " not found." << endl;
        return;
    }

    if (q->borrowed_count >= 4)
    {
        cout << "Student " << q->name << " has already borrowed the maximum number of books." << endl;
        return;
    }

     for (int i = 0; i < q->borrowed_count; ++i)
    {
        if (q->borrowed_books[i] == r)
        {
            cout << "Book " << r->title << " is already borrowed by " << q->name << "." << endl;
            return;
        }
    }

    q->borrowed_books[q->borrowed_count] = r;
    q->borrowed_count++;
    r->quantity--;

    cout << "Book " << r->title << " borrowed by " << q->name << "." << endl;
}

void Linklist::returnBook(int student_id, int book_id)
{
    Node_S* q = HEAD;
    while (q != nullptr && q->id != student_id)
    {
        q = q->link;
    }

    if (q == nullptr)
    {
        cout << "Student with ID " << student_id << " not found." << endl;
        return;
    }

    Node_B* returned_book = nullptr;
    for (int i = 0; i < q->borrowed_count; ++i)
    {
        if (q->borrowed_books[i]->id == book_id)
        {
            returned_book = q->borrowed_books[i];
            for (int j = i; j < q->borrowed_count - 1; ++j)
            {
                q->borrowed_books[j] = q->borrowed_books[j + 1];
            }
            q->borrowed_count--;
            break;
        }
    }

    if (returned_book == nullptr)
    {
        cout << "Book with ID " << book_id << " not borrowed by student " << q->name << "." << endl;
        return;
    }

    returned_book->quantity++;

    cout << "Book " << returned_book->title << " returned by student " << q->name << "." << endl;
}

void Linklist::displayAllBooks()
{
    book_list();
    Node_B* r = START;

    if (r == nullptr)
    {
        cout << "No books available in the library." << endl;
        return;
    }

    cout << "List of all books in the library:" << endl;
    while (r != nullptr)
    {
        cout << "ID: " << r->id << endl;
        cout << "Title: " << r->title << endl;
        cout << "Author: " << r->author << endl;
        cout << "Quantity: " << r->quantity << endl;
        cout << endl<<endl;

        r = r->link;
    }
}

void Linklist::displayAllStudents()
{
    Node_S* r = HEAD;

    if (r == nullptr)
    {
        cout << "No students registered in the library." << endl;
        return;
    }

    cout << "List of all students in the library:" << endl;
    while (r != nullptr)
    {
        cout << "ID: " << r->id << endl;
        cout << "Name: " << r->name << endl;
        cout << "Borrowed Books: " << endl;
        for (int i = 0; i < r->borrowed_count; ++i)
        {
            cout << "\t" << r->borrowed_books[i]->title << endl;
        }
        cout << endl<<endl;

        r = r->link;
    }
}

void Linklist::showMenu()
{
    int choice;
    int student_id, book_id;
    string title, author;

    do
    {
        cout << "\n======= Nirukti Granthalaya=======\n";
        cout << "1. Display all books\n";
        cout << "2. Display all students\n";
        cout << "3. Add a book\n";
        cout << "4. Remove a book\n";
        cout << "5. Add a student\n";
        cout << "6. Remove a student\n";
        cout << "7. Borrow a book\n";
        cout << "8. Return a book\n";
        cout << "9. Search books by title\n";
        cout << "10. Search books by author\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            displayAllBooks();
            break;
        case 2:
            displayAllStudents();
            break;
        case 3:
            cout << "Enter book details:\n";
            cout << "ID: ";
            cin >> book_id;
            cout << "Title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Author: ";
            getline(cin, author);
            cout << "Quantity: ";
            int quantity;
            cin >> quantity;
            addBook(book_id, title, author, quantity);
            break;
        case 4:
            cout << "Enter the ID of the book to remove: ";
            cin >> book_id;
            removeBook(book_id);
            break;
        case 5:
            cout << "Enter student details:\n";
            cout << "ID: ";
            cin >> student_id;
            cout << "Name: ";
            cin.ignore();
            getline(cin, title);
            addStudent(student_id, title);
            break;
        case 6:
            cout << "Enter the ID of the student to remove: ";
            cin >> student_id;
            removeStudent(student_id);
            break;
        case 7:
            cout << "Enter student ID: ";
            cin >> student_id;
            cout << "Enter book ID: ";
            cin >> book_id;
            borrowBook(student_id, book_id);
            break;
        case 8:
            cout << "Enter student ID: ";
            cin >> student_id;
            cout << "Enter book ID: ";
            cin >> book_id;
            returnBook(student_id, book_id);
            break;
        case 9: 
            cout << "Enter the title to search: ";
            cin.ignore();
            getline(cin, title);
            book_list();
            searchByTitle(title);
            break;
        case 10:
            cout << "Enter the author to search: ";
            cin.ignore();
            getline(cin, author);
            book_list();
            searchByAuthor(author);
            break;
        case 11:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 11);
}

int main()
{
    Linklist library;
    library.Students();
    library.book_list();
    library.showMenu();
    return 0;
}

