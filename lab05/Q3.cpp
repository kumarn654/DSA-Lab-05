#include<iostream>
using namespace std;
class Stack{
    public:
    // Value from reverse function
    int valueofK;
    int* brr;
    int top;

    Stack(){
        top = 0;
    }

    Stack(int valueofK){
        this->valueofK = valueofK;
        brr = new int[valueofK];
        this->top = 0;
       

    }
    bool isFull(){

        if(top == valueofK)
            return true;
        else
            return false;
    }
      bool isEmpty(){
        if(top ==0) 
            return true;
        else 
            return false;
    }
    
    void push(int x){
        if(isFull()){
            cout<<"Stack is Full!"<<endl;
            return;
        }

        brr[top] = x;
        
        cout<<brr[top]<<" Added"<<endl;
        top++;
    }
     void pop(){
        int x;
        if(isEmpty()){
            cout<<"Stack is Empty!"<<endl;
            return;
        }
        top--;
        x = brr[top];
        
        cout<<x<<" Removed"<<endl;
    }


};
class Queue{
    public:
    int arr[7];
    int size = 7;
    int front;
    int rear;
    
    Queue(){
        front = 0;
        rear = 0;

    }



    bool isEmpty(){
        if(front == 0){
            return true;
        }
        else{
            return false;
        }
    }

    bool isFull(){
        if(rear == size){
            return true;
        }
        else{
            return false;

        }
    }


    // first we will Enqueue

    void Enqueue(int x){
        if(isFull()){
            cout<<"Queue is Full!"<<endl;
            return;
        }
        arr[rear] = x;
        cout<<arr[rear]<<" ";
        rear++;
    }

    void reverseFirstK(Queue &q,int k){
        Stack s(k);
       // to reverse the  function first insert in stack
        for(int i=0;i<k;i++){
           s.push(q.arr[i]);   
           
        }

        cout<<endl;

        // after inserting pop the values and values will be in reversed order for k
        for(int i=0;i<k;i++){
            q.arr[i] = s.brr[--s.top];
        }
       
    }

    void display(){
        for(int i= front ;i<rear;i++){
            cout<<arr[i] <<" ";
        }
        cout<<endl;
    }
};

int main(){
    Queue q;
    // passes k value
    
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);
    q.Enqueue(6);
    q.Enqueue(7);
    
    cout<<endl;
    cout<<endl;
    q.reverseFirstK(q,3);
    cout<<endl;

    q.display();



    return 0;
}