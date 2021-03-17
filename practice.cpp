#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cctype>
#include <fstream>                      // file stream library (file IO)
using namespace std;

// KI TAE (PAUL) HAN
// C++ practice

// heade file : these can be in a file together for modular abstraction
// GLOBAL CONSTANTS
const int MAX = 100;
const int NAME = 100;
const int AGE = 100;
const int SEX = 10;

// STRUCTS & CLASSES
// person struct
struct person {
    char name[NAME];
    char age[AGE];
    char sex[SEX];
};

// employee class
class employee {
    public : 
        employee();                      // constructor : set data members to NULL
        employee(person info);           // copy constructor
        ~employee();                     // destructor : deallocate dynamically allocated memory (data members)

        int display();

    private : 
        char* eid;
        char* name;
        char* age;
        char* sex;
};

// employee node
struct node {
    employee* emp;
    node* next;
};

// list class (data structure)
class list {
    public :
        list();
        ~list();

        int add(employee new_emp);
        //int search();
        //int remove();
        //int display();
        //int count();
        //int destroy();

    private : 
        node * head;
};

// FUNCTION PROTOTYPES
void intro();
int file_output(person person_instance);
int file_input();


// main cpp file : this can be in its own file for modular abstration & linked together before compilation
// main 
int main(int argc, char *argv[]) {

    /*
    // practice 1 : arrays, ptrs, input & output, rand()
    // declare a character array of size 20 (last index should reserved for terminating null, '\0')
    char array[20];
    // ptr is a character pointer that points to the first index of array (address)
    char *ptr = array;

    // IO
    cout << "Hello World" << endl;
    cout << "What is your name? : ";
    // read input into array, up to 19 characters, saves last index for terminating null, '\0'
    cin.get(array, 20, '\n'); 
    // ignores up to 20 elements in the input stream, or the delimeter ('\n' in this case), whichever comes first
    cin.ignore(20, '\n');
    cout << "Welcome " << ptr << ", hope you are having a nice day." << endl;

    // strlen(char*);                                       // return length of str
    // strcpy(char* copy_to, char* copy_from);              // copy one string to another 
    // strcmp(char* str1, char* str2);                      // compare if two strings are identical
    cout << "Your name contains " << strlen(ptr) << " characters." << endl;

    // seed random with current system time
    srand(time(NULL));
    cout << "Random number between 0 and MAX : " << rand() % MAX << endl;
    */


    /*
    // practice 2 : structs & file input & output
    person human;

    cout << "Enter a person's name, age, and sex (enter after each input)." << endl;
    cin.get(human.name,NAME,'\n'); cin.ignore(MAX,'\n');
    cin.get(human.age,AGE,'\n'); cin.ignore(MAX,'\n');
    cin.get(human.sex,SEX,'\n'); cin.ignore(MAX,'\n');
    file_output(human);                 // add a person to practice.txt
    file_input();                       // read current contents of practice.txt
    */

    // practice 3 : create class object & play around with it 


    return 0;
}



// similar functions in each cpp file : these can be in different files for modular abstraction & linked later for compilation
// FUNCTION DEFINITIONS 
void intro() {
    cout << "Hello, this is the intro function" << endl;
    return;
}


// FILE IO
// output instanace of person structure to a file
int file_output(person person_instance) {

    // declare an object for output file stream (acts like cout, but it will output to file instead of terminal)
    ofstream out_file;
    // open file to output to; ios::app appends to the current file (without it, the file will clear every time)
    out_file.open("practice.txt", ios::app);

    // if out_file is open (good coding practice just in case out_file did not open successfully)
    if(out_file) {
        // output person_instance fields to out_file; 
        // '#' acts as delimeters between fields in single instance, '\n' acts as delimeter for when an instance is complete
        out_file << person_instance.name << "#" << person_instance.age << "#" << person_instance.sex << "\n";
    }
    else {
        // if file did not open successfully, return 0 for failure
        return 0;
    }

    // it is important to close and clear the file after use (especially when working with multiple txt files)
    out_file.close();
    out_file.clear();

    // return 1 for success
    return 1;
}

// read from file; following shows example of print, but we can load file data into variable or objects
int file_input() {

    // VARIABLES (static arrays need to have pre-determined size)
    char name[MAX];
    char age[MAX];
    char sex[MAX];

    // declare input stream object (acts like cin, but it will read from a file instead of terminal)
    ifstream input_file;
    // open file to read from
    input_file.open("practice.txt");

    // if input_file is open (good coding practice)
    if(input_file) {
        
        // PRIME THE PUMP - make sure there is something in the file before entering while loop
        // read from input file until delimeter "#" (or MAX, whichever comes first)
        input_file.get(name,MAX,'#');
        // ignore the "#" from file input stream
        input_file.ignore(MAX,'#');

        if(input_file.eof()) {
            // return 0 for failure, if the file is empty 
            return 0;
        }

        // continue to execute while we have not reached end-of-file yet
        while(!input_file.eof()) {

            input_file.get(age,MAX,'#');
            input_file.ignore(MAX,'#');

            input_file.get(sex,MAX,'\n');
            input_file.ignore(MAX,'\n');

            // print to terminal/console extracted line from file
            cout << "NAME: " << name << "\t\tAGE: " << age << "\t\tSEX: " << sex << endl;

            input_file.get(name,MAX,'#');
            input_file.ignore(MAX,'#');
        }

    }
    else {
        // return 0 if input_file did not open to communicate failure
        return 0;
    }

    // close input_file
    input_file.close();
    input_file.clear();

    // return 1 for success
    return 1;
}

// EMPLOYEE CLASS FUNCTIONS
// constructor
employee::employee() {
    this->eid = NULL;
    this->name = NULL;
    this->age = NULL;
    this->sex = NULL;
}

// copy constructor
employee::employee(person info) {

    // allocate just the right amount of memory for appropriate data members 
    this->name = new char[strlen(info.name)];
    this->age = new char[strlen(info.age)];
    this->sex = new char[strlen(info.sex)];
    
    // assign employee id & copy over employee info
    //this->eid = randomly generated 10-digit ID, must be unique (function)
    strcpy(this->name, info.name);
    strcpy(this->age, info.age);
    strcpy(this->sex, info.sex);
}

// destructor
employee::~employee() {

    // if eid pointer is pointing somewhere (memory has been dynamically allocated), deallocate memory 
    if(this->eid) {
        delete [] this->eid;
    }
    if(this->name) {
        delete [] this->name;
    }
    if(this->age) {
        delete [] this->age;
    }
    if(this->sex) {
        delete [] this->sex;
    }
}
