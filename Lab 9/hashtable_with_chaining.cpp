#include <iostream>
#include "linkedlist.cpp"
using namespace std;

struct HashTable{
    int MAX_LENGTH = 4;
    int MAX_CHAIN_LENGTH = 2;
    LinkedList * password = new LinkedList[MAX_LENGTH];
    bool isFull(){
        bool full = true;
        int count = 0;
        for (int i = 0; i < MAX_LENGTH; i++){
            if(password[i].head == NULL){
                full = false;
            }
        }
        return full;
    }
    int hashfunc(string user_name){
        int sum = 0;
        int hash = 0;
        for(int i = 0;i< user_name.length(); i++){
            sum += int(user_name[i]);

        }
        hash = sum % MAX_LENGTH;

        return hash;
    }
    bool is_slot_empty(int hash){
        bool empty;
        if(password[hash].head==NULL){
            empty = true;
        }
        else{
            empty=false;
        }
        return empty;
    }
    void insert(string user_name,string user_password){
        int hash;
        bool empty;
        hash = hashfunc(user_name);
        empty = is_slot_empty(hash);
        if(password[hash].length<MAX_CHAIN_LENGTH){
            password[hash].insert(user_name.data(),user_password.data());
        }
        else{
            cout<<"Linked List reached MAX CAP!\n";
        }
    }
    void print_hashtable(){
        for(int i=0;i<MAX_LENGTH;i++){
            cout<<"["<<i<<"]-->";
            password[i].print_list();
        }
    }
    void hash_lookup(string user_name){
        int hash;
        bool empty;
        hash = hashfunc(user_name);
        empty = is_slot_empty(hash);
	//add your code below
        if (!empty){  //If the slot is empty giving the error message
            cout << "Slot is empty!"<<endl;
        }
        else{                                         //if the slot is not empty
            Node *current_node = password[hash].head;
            while (current_node != NULL){        //Iterating over each node in a given slot
                if (current_node->user_name==user_name){    //If the user name is found , then print the relevent password
                    cout << "User password : "<<current_node->password <<endl;
                    return;
                }
                else{
                    current_node = current_node->link;   //change the current node to the next node
                }
                cout << "User Name not found!"<<endl; //Giving the error message if the user name is not found
            }
        }
    }
};

int main(){
    HashTable * hashtbl = new HashTable;
    cout<< hashtbl->isFull()<<"\n";
    int command=0;
    string user_name;
    string password;
    while (command!=-1){
        /* code */
        cout << "Type command: ";
        cin >> command;
        switch (command){
        case 1:
            /* insert the new item*/
            cout << "Enter user name: ";
            cin >> user_name;
            cout << "Enter password to be saved: ";
            cin >> password;
            hashtbl->insert(user_name,password);
            break;
        case 2:
            /* hash lookup password*/
            cout << "Enter user name to look up password:";
            cin >> user_name;
            hashtbl->hash_lookup(user_name);
            break;
        case 3:
            hashtbl->print_hashtable();
            break;
        case -1:
            /* hash lookup password*/
            hashtbl->print_hashtable();
            cout << "Exiting...\n";
            break;
        
        }
    
    }
    return 0;
}