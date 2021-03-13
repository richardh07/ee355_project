
#ifndef PERSON_H
#define PERSON_H

#include "Date.h"
#include "fstream"

class Person{
    friend class Network;

private:
	string f_name;  // can have space 
	string l_name;  // can have space
	Date *birthdate;
    // other attributes will be added later
    Person *prev;
    Person *next;

public: 
    Person();
    Person(string f_name, string l_name, string bdate);
    ~Person();
	void print_person();
	void set_person();
    bool operator==(const Person& rhs);
    bool operator!=(const Person& rhs);

};


#endif
