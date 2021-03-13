
#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;


class ContactInfo {
    protected: //TODO: should type be private or protected?	Think about it.
	string type;
public:
	virtual void print() = 0;
    virtual string get_contact() = 0;
	virtual void set_contact() = 0;
};


// Complete the Email declaraction from scratch here 

class Email: public ContactInfo{
	private:
		string email_addr;
		string type;
	public:
		Email(string type, string email_addr);
		void set_contact();
		string get_contact();
		void print();
};
// Complete the phone declaration from scratch

class Phone: public ContactInfo {
	private:
		string num;
		string type;
	public:
		Phone(string type, string num);
		void set_contact();
		string get_contact();
		void print();

};
#endif
