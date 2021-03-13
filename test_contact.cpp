
#include <iostream>
#include "Contact.h"
using namespace std;

int main(){

    cout << "###### Testing Email class: " << endl;
	Email my_email("USC", "tommytrojan@usc.edu");
	my_email.print();

	cout << "###### Testing Phone class: " << endl;
	Phone my_phone("Home", "3101922847");
	my_phone.print();
    Phone another_phone("Home", "213-192-2847");
	another_phone.print();

    return 0;
}

