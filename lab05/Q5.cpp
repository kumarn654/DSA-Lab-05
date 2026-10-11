#include<iostream>
using namespace std;
class CircularQueue{
    public:
    int id[6];
    int front;
    int rear;
    int count;
    int size = 6;
    CircularQueue(){
        front =0;
        rear = 0;
        count =0;
    }

    bool isEmpty(){
        if(count ==0){
            return true;
        }
        else{
            return false;
        }
    }

    bool isFull(){
        return count == size;
    }

    void Enqueue(int x){
        if(isFull()){
            cout<<"Circular Queue is Full!"<<endl;
            return;
        }
        id[rear] = x;
        cout<<x<<"  Passenger Coming"<<endl;
        rear = (rear + 1) % size;
        
        count++;
    }

    void dequeue(){
        int x;
        if(isEmpty()){
            cout<<"Circular Queue is Empty!"<<endl;
            
            return;
        }
        x = id[front];
        
        cout<<x<<" Passenger Broaded"<<endl;
        front = (front + 1) % size;
        count--;

    }

    int peek(){
        return id[front];
    }

    void display(){
        int i= front;
        int c = count;
        while(c > 0){
            cout<<id[i]<<" ";
            i = (i + 1) % size;
            c--;
        }
    }
};

int main() {
    CircularQueue q;

    q.Enqueue(101);
    q.Enqueue(102);
    q.Enqueue(103);
    q.Enqueue(104);
    q.Enqueue(105);
    q.Enqueue(106);

    cout << endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();

    cout << endl;

    q.Enqueue(107);
    q.Enqueue(108);
    q.Enqueue(109);

    cout << endl;

    q.dequeue();
    q.dequeue();
    cout << endl;
    q.Enqueue(110);
    cout << endl;
    q.dequeue();

    cout << endl;

    q.Enqueue(111);
    q.Enqueue(112);

    cout << endl;

    cout << "Final Passenger Boarding"<<endl;
    q.display();

    cout << endl;
    cout << "The Final Front is: " << q.front << endl;
    cout << "The Final Rear is: " << q.rear << endl;

    return 0;
}
