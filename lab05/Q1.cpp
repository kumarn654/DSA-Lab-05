#include<iostream>
using namespace std;
class Stack{
    public:
    int arr[8];          // size  = 6
    int size = 8;
    int top;

    Stack(){
        top = 0;

    }
    
    bool isEmpty(){
        if(top ==0) 
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

    int peek(){
        if(isEmpty()){
            cout<<"Stack is Empty!"<<endl;
            return -1;
        }
        return arr[top-1];
    }

    void push(int x){
        if(isFull()){
            cout<<"Stack is Full!"<<endl;
            return;
        }

        arr[top] = x;
        
        cout<<arr[top]<<" Added"<<endl;
        top++;
        cout<<"Current Top operations is:"<<peek()<<endl;
    }

    void pop(){
        int x;
        if(isEmpty()){
            cout<<"Stack is Empty!"<<endl;
            return;
        }

        top--;
        x = arr[top];
        
        cout<<x<<" Removed"<<endl;
        
    }

    


    void display(){

        for(int i=top-1;i>=0;i--){
            cout<<arr[i]<<endl;
        }
    }
 
};


int main(){
    Stack s;

    s.push(12);
    s.push(25);
    s.push(17);
    s.push(31);
    s.push(44);
    s.push(19);
    
 
    cout<<endl;
    s.pop();
    s.pop();
    s.pop();
    cout<<endl;
    
    cout<<endl;
    s.push(52);
    cout<<endl;
    

    

    s.pop();
    s.pop();
    cout<<endl;
   
    
    cout<<"Displaying the  Stack"<<endl;
    cout<<endl;
    s.display();
    
    return 0;
}