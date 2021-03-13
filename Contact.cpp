
#include "Contact.h"
#include <algorithm>
#include <string.h>


Email::Email(string type, string email_addr){
    // Already done
    this->type = type;
    this->email_addr = email_addr;
}


void Email::set_contact(){
    // Already done! 
    // We don't need to validate the entered email address.  
	cout << "Enter the type of email address: ";
	cin >> type;
    cout << "Enter email address: ";
    cin >> email_addr;
}


string Email::get_contact(){
    // TODO
    // return example: "(Personal) username@gmail.com" 
    string emailx;
    emailx = "(Personal) "+ email_addr;
    return (emailx);
}


void Email::print(){
    // TODO
    // Hint: use get_contact
    cout<< get_contact()<<endl;
}


Phone::Phone(string type, string num){
    // TODO
    // It is possible that the phone number is given with (292-431-9876) or without (2924319876) dashes. 
    // We are sure that all phone numbers have 10 digits. 
    this->type = type;
    this->num = num;
}


void Phone::set_contact(){
    // TODO
    
    // Use these prompts:    
	// cout <<"Enter the type of phone number: ";
    //
	// cout << "Enter the phone number: ";
    //
}


string Phone::get_contact(){
    // TODO
    // return example "(Cell) 213-876-0023" 
    string numx;
    numx = "(Cell) " + num;
    return (numx);
}


void Phone::print(){
    // TODO 
    // Hint: use get_contact
    cout<< get_contact()<<endl;
}


