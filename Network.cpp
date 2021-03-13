
#include "Network.h"
#include "misc.h"
#include "Person.h"
#include <fstream>
#include <dirent.h>
#include <limits>

Network::Network(){
    // TODO
    // What should be the initial values for head, tail, and count?  
    this->head = NULL;
    this->tail = NULL;
    this->count = 0;
    cout << "network obj created!"<<endl;  
}


void Network::push_front(Person* newEntry){
    // TODO
    // Adds a new entry to the front of the LL (where head is pointing)
    if (count == 0){
        head = newEntry;
        count++;
    }
    else {
        newEntry->next = head;
        head->prev = newEntry;
        head = newEntry;
        count ++;
    }
    cout <<"pushed front"<<endl;
}


void Network::push_back(Person* newEntry){
    // TODO
    // Adds a new entry to the back of the LL (where tail is pointing)
    if (count == 0){
        tail = newEntry;
        count++;
    }
    else {
        newEntry->prev = tail;
        tail->next = newEntry;
        tail = newEntry;
        count++;
    }
    cout <<"pushed back"<<endl;
}


void Network::printDB(){
    // Already done! 
    cout << "Number of items: " << count << endl;
    cout << "------------------------------" << endl;
    Person* ptr = head;
    while(ptr != NULL){
        ptr->print_person();
        cout << "------------------------------" << endl;
        ptr = ptr->next;
    }
}

Network::~Network(){
    // TODO 
    // Delete all the dynamically allocated items
    // delete all linked lists
    Person* curr = head;
    Person* nxt = NULL;
    while (curr!= NULL){
        nxt = curr->next;
        delete (curr);
        curr = nxt;
    }
    head = NULL;
    tail = NULL;
}


Person* Network::search(Person* searchEntry){
    // TODO
    // Searches the Network to find an entry which has similar attributes as searchEntry
    // if found, returns a pointer to it, else returns NULL
    // Hint: We already implemented the == operator for two Person objects
    // Note: searchEntry is not a Person, but a Person* 
    Person* temp = NULL;
    Person* rslt = NULL;
    temp = head;
    for (int i = 0; i < count; i++){
        if (*searchEntry == *temp){
            rslt = temp;
            return (rslt);
        }
        temp = temp->next;
    }
    return (rslt);

}


Person* Network::search(string fname, string lname, string bd){
    // TODO
    // Search based on fname, lname, and birthdate
    // if found, returns a pointer to it, else returns NULL
    // Note: two ways to implement this:
    // 1st) making a new Person with fname, lname, bdate and and using search(Person*)
    // 2nd) using fname, lname, and bd directly 
    // Person *new_person = new person (fnmae, lname,bd);
    Person *temp_person = new Person(fname, lname, bd);
    Person *rslt = NULL;
    rslt = search(temp_person);
    delete temp_person;
    return rslt;

}



void Network::saveDB(string filename){
    // TODO
    // Saves the netwrok in file <filename>
    // Look at studentDB.db as a template of the format of our database files
    ofstream tgt_file (filename.c_str());
    Person* ptr = head;
    while (ptr != NULL){
    tgt_file << ptr->l_name <<", " << ptr->f_name << endl;
	tgt_file << ptr->birthdate->month << "/" << ptr->birthdate->month << "/" << ptr->birthdate->year <<endl;
    tgt_file << "------------------------"<<endl;
    ptr = ptr->next;
    }
    tgt_file.close();
}


void Network::loadDB(string filename){
    // TODO
    // Loads the netwrok from file <filename>
    // The format of the input file is similar to saveDB
    // Look at network studentDB.db as a template
    // When a new database is being loaded, you need to delete the previous dataset
    Person* curr = head;
    Person* nxt = NULL;
    while (curr!= NULL){
        nxt = curr->next;
        delete (curr);
        curr = nxt;
    }
    head = NULL;
    tail = NULL;
    count = 0;
    ifstream tgt_file(filename.c_str());
    string temp_str,lstname,fstname,bdate;
    int ct = 1;
    while (getline(tgt_file, temp_str)){
        if (ct%3 == 1){
            lstname = temp_str.substr(0,temp_str.find(", "));
            fstname = temp_str.erase(0,temp_str.find(", ")+ 2);
        }
        if (ct% 3 == 2){
            bdate = temp_str;
        }
        if (ct% 3 == 0){
            Person *new_person = new Person(fstname, lstname, bdate);
            push_front(new_person);
        }
        ct++;
    }
        tgt_file.close();

}


Network::Network(string fileName){
    // TODO
    // Hint: just call loadDB 
    loadDB(fileName);

}


bool Network::remove(string fname, string lname, string bd){
    // TODO
    // remove the entry with matching fname, lname, bd
    // If it exists, returns true, otherwise, returns false
    Person *tgt_person = NULL;
    tgt_person = search(fname,lname,bd);
    if (tgt_person != NULL){
        if (tgt_person->next != NULL){
            tgt_person->next->prev = tgt_person->prev;
        }
        else {
            tail = tgt_person->prev;
        }
        if (tgt_person->prev != NULL){
            tgt_person->prev->next = tgt_person->next;
        }
        else {
            head = tgt_person->next;
        }
        delete tgt_person;
        return true;
    }
    else {
        return false;
    }
}



void Network::showMenu(){
    int opt;
    while(1){
        cout << "\033[2J\033[1;1H";
        printMe("banner");
        cout << "Select from below: \n";
        cout << "1. Save network database \n";
        cout << "2. Load network database \n";
        cout << "3. Add a new person \n";
        cout << "4. Remove a person \n";
        cout << "5. Search \n";
        cout << "6. Print database \n";
        cout << "0. Quit \n";
        cout << "\nSelect an option ... ";
        
        if (cin >> opt) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Wrong option! Quitting ... " << endl;
            return;
        }

        string fname, lname, fileName, bdate;
        cout << "\033[2J\033[1;1H";

        if (opt==1){ 
            // Already done! 
            cout << "Saving network database \n";
            cout << "Enter the name of the save file: ";
            cin >> fileName;
            this->saveDB(fileName);
            cout << "Network saved in " << fileName << endl;
        }
        else if (opt==2){ 
            // Already done! 
            cout << "Loading network database \n";
            // Note: we added a nice feature to show the files in current directory
            DIR *dir;
            struct dirent *ent;
            if ((dir = opendir ("./")) != NULL) {
                string str;
                while ((ent = readdir (dir)) != NULL) {
                    str = ent->d_name;
                    if (str.size() > 3){
                        if (str.substr(str.size()-3) == ".db")
                            cout << str << endl; 
                    }
                }
                closedir (dir);
            }
            cout << "Enter the name of the load file: ";
            cin >> fileName;
            ifstream check(fileName.c_str());
            if (! bool(check))
                cout << "Warning! File does not exist! \n";
            else {
                loadDB(fileName);
                cout << "Network loaded from " << fileName << " with " << count << " items \n";
            }
        }
        else if (opt == 3){
            // TODO
            // Prompt and get the information of a new Person
            // You need to make sure this item does not already exists!
            // If it does not exist, push it to the front of the LL
            cout << "Adding a new item (push front)\n";
            Person *new_person = new Person;
            if (search(new_person)!=NULL){
                cout << "repeated item!"<<endl;
                delete new_person;
            }
            else {
                push_front(new_person);
            }

        }
        else if (opt == 4){
            // TODO 
            cout << "Removing an item \n";
            string *fstname = new string;
            string *lstname = new string;
            string *bdate = new string;
            cout << "First Name: ";
            getline(cin, *fstname);
            cout << "Last Name: ";
            getline(cin, *lstname);
            cout << "Birthdate: ";
            getline(cin, *bdate);
            // If found and removed successfully: cout << "Remove Successful! \n";
            // else: cout << "Person not found! \n";
            if (remove(*fstname,*lstname,*bdate)){
                cout << "Remove Successful\n";
                count --;
            }
            else {
                cout << "Person not found!\n";
            }
            delete fstname;
            delete lstname;
            delete bdate;
        }
        else if (opt==5){
            // TODO
            string *fstname = new string;
            string *lstname = new string;
            string *bdate = new string;
            cout << "Searching: \n";
            cout << "First Name: ";
            getline(cin, *fstname);
            cout << "Last Name: ";
            getline(cin, *lstname);
            cout << "Birthdate: ";
            getline(cin, *bdate);
            // If not found: cout << "Not found! \n";
            if (search (*fstname, *lstname, *bdate) != NULL){
                search (*fstname, *lstname, *bdate)->print_person();
            }
            else {
                cout << "Not found!" <<endl;
            }
            delete fstname;
            delete lstname;
            delete bdate;

        }

        else if (opt==6){
            // TODO 
            cout << "Network Database: \n";
            // this should be simple ... 
            printDB();
        }

        else if (opt==0)
            // QUIT! 
            return;
        else
            cout << "Nothing matched!\n";
       
        // Don't touch the lines below! :)  
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin.clear();
        cout << "\n\nPress Enter key to go back to main menu ... ";
        string temp;
        std::getline (std::cin, temp);
        cout << "\033[2J\033[1;1H";
    }
}



