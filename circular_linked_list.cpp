/*Circular Linked List:
1.Round-Robin Scheduling: (Please follow the different constraints as
discussed in the class)
-Simulate a round-robin scheduling for a set of users in an department for
printing task.
-Users are represented by nodes in a circular linked list, and each iteration
of the algorithm selects the next user in the circle.
-Other customisations if you want to add*/

#include <iostream>
#include <string>
using namespace std;

class Linklist
{
    private:
        struct Node
        {
            string name;
            int no_pg;
            Node*next;

            Node(string n,int p):name(n),no_pg(p),next(nullptr){}
        }*START;
    public:
        Linklist();
        ~Linklist();
        void addUser(string name, int pages);
        void printing();
        void menu();
};

Linklist::Linklist()
{
    START=NULL;
}

Linklist::~Linklist()
{
    Node*b;
    while (START!=NULL)
    {
        b=START->next;
        delete START;
        START=b;
    }
}

void Linklist::addUser(string name, int pages)
{
    Node* newUser = new Node(name, pages);
        if (!START)
        {
            START = newUser;
            newUser->next = START;
        }
        else
        {
            Node* temp = START;
            while (temp->next != START)
            {
                temp = temp->next;
            }
            temp->next = newUser;
            newUser->next = START;
        }
}

void Linklist::printing()
{
    if (!START)
    {
        cout << "No users added for printing." << endl;
        return;
    }

    int totalPages = 0;
    Node* current = START;

    do
    {
        totalPages += current->no_pg;
        current = current->next;
    } while (current != START);

    int round = 1;
    int pagesPrinted = 0;

    while (pagesPrinted < totalPages)
    {
        cout << "Round " << round << ":" << endl;

        current = START;

        do
        {
            int pagesToPrint = min(current->no_pg, 5);
            current->no_pg -= pagesToPrint;
            pagesPrinted += pagesToPrint;

            cout << current->name << " printed " << pagesToPrint << " pages." << endl;

            current = current->next;
        } while (current != START);

        round++;
    }

    cout << "All users have finished printing." << endl;
}



void Linklist::menu()
{
    int numPeople;
    cout << "Enter the number of people: ";
    cin >> numPeople;

    string name;
    int pages;

    for (int i = 0; i < numPeople; ++i)
    {
        cout << "Enter name for person " << i + 1 << ": ";
        cin >> name;
        cout << "Enter number of pages for person " << i + 1 << ": ";
        cin >> pages;
        addUser(name, pages);
    }

    int choice;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Print\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            printing();
            break;
        case 2:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 2);
}

int main()
{
    Linklist Printer;
    Printer.menu();
    return 0;
}