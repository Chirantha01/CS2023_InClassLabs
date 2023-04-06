#include<iostream>
#include<chrono>
#include<algorithm>
using namespace std;
using namespace std::chrono;

#define max 100

//creating class for implementing stack using arrays
class array_stack {
private: 
    int stack_arr[max];
    int top = -1;

public:
    
//creating function for pushing an element to the top of the stack
void push(int data){
    if (top == max-1){
        cout << "Stack Overflow"<<endl;
        return;
    }
    top++;
    stack_arr[top] = data;
    cout << "pushed item : "<< data<<endl;
}
    
//creating a function to remove an element from the top of the stack and return the value
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
    
//creating a function to display the current stack
void display(){
    cout<<"[";
    for (int i=top;i>=0;i--){
        cout<<stack_arr[i]<<" ";
    }
    cout << "]"<<endl;
}

};

int main(){
    //getting randomly generated values in to an integer array
    int data_arr[20];
    for (int i=0;i<20;i++){
        data_arr[i] = rand() %100;
    }
    
    //stack implementation using arrays
    array_stack as;

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
}
