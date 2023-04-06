#include<iostream>
#include<chrono>
#include<algorithm>
using namespace std;
using namespace std::chrono;

#define max 100

class array_stack {
private: 
    int stack_arr[max];
    int top = -1;

public:

void push(int data){
    if (top == max-1){
        cout << "Stack Overflow"<<endl;
        return;
    }
    top++;
    stack_arr[top] = data;
    cout << "pushed item : "<< data<<endl;
}

int pop(){
    if (top==-1){
        cout << "Stack Underflow"<<endl;
        exit(1);
    }
    int value=stack_arr[top];
    top--;
    cout << "popped item : "<< value<<endl;
    return value;
}

void display(){
    cout<<"[";
    for (int i=top;i>=0;i--){
        cout<<stack_arr[i]<<" ";
    }
    cout << "]"<<endl;
}

};

struct node{
    int data;
    struct node * link;
};
class stack_linked{
private:
    struct node *head;

public:
    stack_linked(){
        head = NULL;
    }

    void push(int element){
        node *newnode = new node;
        newnode -> data = element;
        newnode -> link = head;
        head = newnode;
        cout<<"pushed item : "<< element<<endl;
    }

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

    void display(){
        node *temp;
        temp = head;

        if (temp == NULL){
            cout<<"[ ]";
        }
        else{
            cout<< "[";
            while (temp != NULL){
                cout<<temp -> data <<" ";
                temp=temp -> link;
            }
            cout<<"]"<<endl;
        }
    }
};

int main(){
    int data_arr[20];
    for (int i=0;i<20;i++){
        data_arr[i] = rand() %100;
    }

    array_stack as;
    auto start1 = high_resolution_clock::now();

    for (int j=0;j<10;j++){
        as.push(data_arr[j]);
    }

    as.display();

    for (int k=0;k<5;k++){
        as.pop();
    }

    as.display();

    for (int i=10;i<14;i++){
        as.push(data_arr[i]);
    }

    as.display();

    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast < microseconds > (end1 - start1);
    cout << "Time taken for implementation of stack using array : " << duration1.count()<<" microseconds."<<endl;

    stack_linked sl;
    auto start2 = high_resolution_clock::now();
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

    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast < microseconds > (end2 - start2);
    cout << "Time taken for implementation of stack using Linked Lists : " << duration2.count()<<" microseconds."<<endl;



}