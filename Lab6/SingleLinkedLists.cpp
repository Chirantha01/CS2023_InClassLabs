#include<iostream>
#include<chrono>
#include<algorithm>
using namespace std;
using namespace std::chrono;

//creating a structure for a node in the linked list
struct node{
    int data;
    struct node * link;
};

//creating a class for implementing stacks using Linked Lists
class stack_linked{
private:
    struct node *head;      //head pointer to keep track of the top of the stack

public:
    stack_linked(){
        head = NULL;
    }
    
    //Creating a function to insert an element at the top of the stack
    void push(int element){
        node *newnode = new node;
        newnode -> data = element;
        newnode -> link = head;
        head = newnode;
        cout<<"pushed item : "<< element<<endl;
    }

    //creating a function to remove the topmost element of the stack
    int pop(){
        if (head == NULL){
            cout << "Stack Underflow" <<endl;
            exit(1);
        }
        int value = head -> data;
        node *temp = head;
        head = head -> link;
        delete temp;
        cout << "popped item : "<<value<<endl;
        return value;

    } 

    //creating a function to display the current stack
    void display(){
        node *temp;
        temp = head;

        if (temp == NULL){
            cout<<"[ ]";
        }
        else{
            cout<< "[";
            while (temp != NULL){
                cout<<temp -> data <<", ";
                temp=temp -> link;
            }
            cout<<"]"<<endl;
        }
    }
};

int main(){
    //getting randomly generated values in to an integer array
    int data_arr[20];
    for (int i=0;i<20;i++){
        data_arr[i] = rand() %100;
    }
    
    //stack implementation using linked lists
    stack_linked sl;
    for (int j=0;j<10;j++){
        sl.push(data_arr[j]);
    }

    sl.display();

    for (int k=0;k<5;k++){
        sl.pop();
    }

    sl.display();

    for (int i=10;i<14;i++){
        sl.push(data_arr[i]);
    }

    sl.display();
}
