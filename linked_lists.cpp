#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cctype>
#include <fstream>                      // file stream library (file IO)
using namespace std;

// KI TAE HAN
// Linked Lists

// GLOBAL CONSTANTS
const int MIN = 3;
const int MAX = 15 - MIN;
const int NUM = 100;

// STRUCTS & CLASSES
struct Node {
    int data;
    Node* next;
};

// try changing this to inheritance(?) : linkedlist parent class + linear, circular, doubly children classes (polymorphism)
class Linearll {
    public :

        // constructors & destructors
        Linearll();
        ~Linearll();

        // wrapper functions
        int display();
        int add(int num);
        int import(const int array[]);
        int remove_head();
        int remove_tail();
        int remove(int num);

    private :
        Node* head;

        // recursive functions
        int display(Node* node);

};

class Circularll {
    public :

        // constructor & destructor
        Circularll();
        ~Circularll();

        // wrapper functions
        int display();
        int add(int num);
        int remove_head();
        int remove_tail();
        int remove(int num);

    private : 
        Node* tail;
};

class Doublyll {
    public :
        Doublyll();
        ~Doublyll();
        int display();
        int add(int num);
        int remove_head();
        int remove_tail();
        int remove(int num);

    private : 
        Node* head;
        Node* tail;
};

// FUNCTION PROTOTYPES
int random_sequence(int array[], int size);


// MAIN CPP FILE
int main() {

    // set up / preparation
    srand(time(0));                     // seed random object
    int size = rand()%MAX + MIN;        // size of array (at least MIN, at most MAX)
    int array[size];                    // create an array of size size
    int result = 0;                     // catch function return
    Linearll LLL;                       // linear linked list object

    // 1. generate random sequence of numbers (in array) & print it 
    result = random_sequence(array,size);
    cout << "RANDOM SEQUENCE (n = " << size << ")\n";
    for(int i=0; i<size-1; ++i) {
        cout << array[i] << "  ";
    }
    cout << array[size-1] << endl;


    // 2. create a LLL, CLL, DLL data structure to hold the sequence of numbers
    LLL.display();

    // 3. display the linked list & perform operations on it



    return 0;
}

// fill passed int array with randomly generated sequence of integers
int random_sequence(int array[], int size) {

    for(int i=0; i<size; ++i) {
        array[i] = rand()%NUM;
    }
    return 1;
}


// LLL CLASS
// constructor
Linearll::Linearll() {
    this->head = NULL;
}

// destructor
Linearll::~Linearll() {
    if(this->head) {
        // deallocate linked list 
    }
}

// display the list
int Linearll::display() {

    // base case : empty list
    if(!this->head) {
        cout << "List is empty.\n";
        return 0;
    }

    // if list is not empty
    return display(this->head);
}

int Linearll::display(Node* node) {

    // base case : when we reach the end of LLL
    if(!node) {
        cout << endl;
        return 0;
    }

    // resursive action : if node is not empty, display node data & move to next Node
    cout << node->data << "  ";
    return display(node->next);

}



// CLL CLASS

// DLL CLASS
