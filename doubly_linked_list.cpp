/*Doubly Linked List:
1.Music playlist creation
-Design a system to keep track of songs in a playlist
-Song details are represented by nodes in a doubly linked list.
-Navigate through previous and next song in the list
-Display the songs according to producer, singer and genre.
-Other customisations if you want to add*/

#include <iostream>
// #include <Python.h>
using namespace std;

class Linklist
{
    private:
        struct Node
        {
            Node*prev;
            int id;
            string title;
            string producer;
            string singer;
            string genre;
            string playfile;
            Node*next;

            Node(int _id, string _title, string _producer, string _singer, string _genre, string _playfile) : prev(nullptr), id(_id), title(_title), producer(_producer), singer(_singer), genre(_genre), playfile(_playfile), next(nullptr) {}

        }*START;
        Node* currentSong;
    public:
        Linklist();
        ~Linklist();
        void addSong(int id, string title, string producer, string singer, string genre);
        void removeSong(int id);
        void searchbyProducer(string producer);
        void searchbySinger(string singer);
        void searchbygenre(string genre);
        void searchbytitle(string title);
        void nextSong();
        void previousSong();
        // void playSong(string playfile);
        string toLowerCase(const string& str);
};

Linklist::Linklist()
{
    START=NULL;
    currentSong=NULL;
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

string Linklist::toLowerCase(const string& str)
{
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

void Linklist::searchbyProducer(string producer) {
    Node* PTR = START;
    bool found = false;

    for (; PTR != nullptr; PTR = PTR->next) {
        if (!PTR->producer.empty() && toLowerCase(PTR->producer).find(toLowerCase(producer)) != string::npos) {
            cout << "ID: " << PTR->id << endl;
            cout << "Title: " << PTR->title << endl;
            cout << "Producer: " << PTR->producer << endl;
            cout << "Singer: " << PTR->singer << endl;
            cout << "Genre: " << PTR->genre << endl;
            cout << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No songs found with the producer \"" << producer << "\" in the playlist." << endl;
    }
}

void Linklist::searchbytitle(string title) {
    Node* PTR = START;
    bool found = false;

    for (; PTR != nullptr; PTR = PTR->next) {
        if (!PTR->title.empty() && toLowerCase(PTR->title).find(toLowerCase(title)) != string::npos) {
            cout << "ID: " << PTR->id << endl;
            cout << "Title: " << PTR->title << endl;
            cout << "Producer: " << PTR->producer << endl;
            cout << "Singer: " << PTR->singer << endl;
            cout << "Genre: " << PTR->genre << endl;
            cout << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No songs found with the Title \"" << title << "\" in the playlist." << endl;
    }
}

void Linklist::searchbySinger(string singer) {
    Node* PTR = START;
    bool found = false;

    string searchSinger = toLowerCase(singer);

    for (; PTR != nullptr; PTR = PTR->next) {

        string currentSinger = toLowerCase(PTR->singer);

        if (!PTR->singer.empty() && currentSinger.find(searchSinger) != string::npos) {
            cout << "ID: " << PTR->id << endl;
            cout << "Title: " << PTR->title << endl;
            cout << "Producer: " << PTR->producer << endl;
            cout << "Singer: " << PTR->singer << endl;
            cout << "Genre: " << PTR->genre << endl;
            cout << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No songs found with the Singer \"" << singer << "\" in the playlist." << endl;
    }
}

void Linklist::searchbygenre(string genre) {
    Node* PTR = START;
    bool found = false;

    string searchGenre = toLowerCase(genre);

    for (; PTR != nullptr; PTR = PTR->next) {

        string currentGenre = toLowerCase(PTR->genre);

        if (!PTR->genre.empty() && currentGenre.find(searchGenre) != string::npos) {
            cout << "ID: " << PTR->id << endl;
            cout << "Title: " << PTR->title << endl;
            cout << "Producer: " << PTR->producer << endl;
            cout << "Singer: " << PTR->singer << endl;
            cout << "Genre: " << PTR->genre << endl;
            cout << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No songs found in the Genre \"" << genre << "\" in the playlist." << endl;
    }
}

void Linklist::nextSong()
{
    if (currentSong == nullptr || currentSong->next == nullptr) {
        cout << "No next song available." << endl;
        return;
    }
    
    currentSong = currentSong->next;

    cout << "Now playing: " << currentSong->title << " by " << currentSong->singer << endl;
}

void Linklist::previousSong()
{
    if (currentSong == nullptr || currentSong->prev == nullptr) {
        cout << "No Previous song available." << endl;
        return;
    }
    
    currentSong = currentSong->prev;

    cout << "Now playing: " << currentSong->title << " by " << currentSong->singer << endl;
}

// void Linklist::playSong(string playfile)
// {

// }

void Linklist::addSong(int id, string title, string producer, string singer, string genre)
{
    Node* newNode = new Node(id, title, producer, singer, genre);

    if (START == nullptr) 
    {
        START = newNode;
        currentSong = newNode;
        return;
    }

    if (id < START->id || (id == START->id && title < START->title)) {
        newNode->next = START;
        START->prev = newNode;
        START = newNode;
        return;
    }

    Node* current = START;

    while (current->next != nullptr && (current->next->id < id || (current->next->id == id && current->next->title < title))) {
        current = current->next;
    }

     newNode->next = current->next;
    if (current->next != nullptr) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    newNode->prev = current;

}
void Linklist::removeSong(int id)
{
    Node* current = START;
    Node* prev = nullptr;

    while (current != nullptr) 
    {
        if (current->id == id) 
        {
            if (prev == nullptr) 
            {
                START = current->next;
            }
            else 
            {
                prev->next = current->next;
                if (current->next != nullptr) 
                {
                    current->next->prev = prev;
                }
            }
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "Song with ID " << id << " not found." << endl;
}