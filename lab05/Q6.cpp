
#include<iostream>
using namespace std;

class Stack{
    public:
    string arr[5];
    int top;
    int size = 5;

    Stack(){
        top = 0;
    }

    bool isEmpty(){
        if(top == 0)
            return true;
        else
            return false;
    }

    bool isFull(){
        if(top == size){
            return true;
        }
        else{
            return false;
        }
    }

    void push(string x){
        if(isFull()){
            cout<<"Stack is Full!"<<endl;
            return;
        }

        arr[top] = x;
        top++;
    }

    string pop(){
        string x;

        if(isEmpty()){
            cout<<"Stack is Empty!"<<endl;
            return "";
        }

        top--;
        x = arr[top];

        return x;
    }

    void display(){
        for(int i=top-1; i>=0; i--){
            cout<<arr[i]<<endl;
        }
    }
};

class MyQueue{
    public:
    Stack incoming;
    Stack outgoing;

    MyQueue(){
    }

    void enqueue(string msg){
        if(incoming.isFull()){
            cout<<"Queue is Full!"<<endl;
            return;
        }

        incoming.push(msg);
    }

    void dequeue(){
        string x;

        if(outgoing.isEmpty()){
            while(!incoming.isEmpty()){
                x = incoming.pop();
                outgoing.push(x);
            }
        }

        if(outgoing.isEmpty()){
            cout<<"Queue is Empty!"<<endl;
            return;
        }

        x = outgoing.pop();
        cout<<x<<" Removed"<<endl;
    }

    void display(){
        outgoing.display();
        incoming.display();
    }
};

int main(){
    MyQueue q;

    q.enqueue("A");
    q.enqueue("B");

    q.dequeue();

    q.enqueue("C");

    q.dequeue();
    q.dequeue();

    return 0;
}