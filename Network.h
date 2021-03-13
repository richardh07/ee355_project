
#ifndef NETWORK_H
#define NETWORK_H

#include "Person.h"
#include "Date.h"
#include <stdlib.h>
class Network{

    private:
        Person* head;
        Person* tail;
        int count; 
        Person* search(Person* searchEntry); 
        Person* search(string fname, string lname, string bd);

    public:
        Network();
        Network(string fileName);
        ~Network();
        void push_front(Person* newEntry);
        void push_back(Person* newEntry);
        bool remove(string fname, string lname, string bd);
        void saveDB(string filename);
        void loadDB(string filename);
        void printDB();
        void showMenu();
};

#endif
