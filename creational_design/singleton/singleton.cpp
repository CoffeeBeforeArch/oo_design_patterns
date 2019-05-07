// This program shows off the singleton creational design pattern in
// in C++
// By: Nick from CoffeeBeforeArch

#include <iostream>

using namespace std;

// Basic singleton class to show of the design pattern
class Singleton {
private:
    // Make the singleton instance static (only one ever)
    static Singleton *instance;

    // Private constructor to ensure only a single instantiation
    Singleton(){};

public:
    // Static access method to get our single instance
    static Singleton *getInstance();
};

// Initialize static class member to be a nullptr
Singleton* Singleton::instance = nullptr;

// Returns the single Singleton instance. Creates creates it if it does
// not already exist
Singleton *Singleton::getInstance(){
    // Check if the static instance variable is null still
    // Referred to as "lazy instantiation" (don't create until needed)
    if(!instance){
        // If not, create the first singleton instance ...
        instance = new Singleton();
    }

    // ... and return it
    return instance;
}

int main(){
    // ILLEGAL! constructor is private!
    // Singleton *test = new Singleton();

    // Creates a new singleton, and returns a pointer to it
    Singleton *simple_singleton_1 = Singleton::getInstance();

    // Only returns a pointer to the single Singleton instance
    Singleton *simple_singleton_2 = Singleton::getInstance();

    // Print out pointers (should be the same)
    cout << "Singleton 1: " << simple_singleton_1 << " Singleton 2: "
        << simple_singleton_2 << endl;

    return 0;
}
