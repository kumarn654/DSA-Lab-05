
#include<iostream>
using namespace std;

class Stack {
public:
    string type[5];
    string redoData[5];
    int top;
    int redoTop;
    int size = 5;

    Stack() {
        top = 0;
        redoTop = 0;
    }

    bool isFull() {
        if(top == size) {
            return true;
        } else {
            return false;
        }
    }

    bool isRedoFull() {
        if(redoTop == size) {
            return true;
        } else {
            return false;
        }
    }

    bool isRedoEmpty() {
        if(redoTop == 0) {
            return true;
        } else {
            return false;
        }
    }

    bool isEmpty() {
        if(top == 0) {
            return true;
        } else {
            return false;
        }
    }

    void typeMsg(string msg) {
        if(isFull()) {
            cout << "The Stack is Full!" << endl;
            return;
        }

        type[top] = msg;
        top++;

        // clear redo history
        redoTop = 0;
    }

    void undo() {
        string retrieve;

        if(isEmpty()) {
            cout <<"Stack is Empty!"<<endl;
            return;
        }

        top--;
        retrieve = type[top];

        cout <<"The Undo Data is: "<<retrieve<<endl;

        if(!isRedoFull()) {
            redoData[redoTop] = retrieve;
            redoTop++;
        }
    }

    void Redo() {
        if(isRedoEmpty()) {
            cout << "Redo Stack is Empty!" << endl;
            return;
        }

        if(isFull()) {
            cout << "The Stack is Full!" << endl;
            return;
        }

        redoTop--;
        type[top] = redoData[redoTop];
        top++;
    }

    void print() {
        for(int i=0;i<top;i++) {
            cout<<type[i]<<" ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    s.typeMsg("Hello");
    s.print();

    s.typeMsg("World");
    s.print();

    s.undo();
    s.print();

    s.Redo();
    s.print();

    s.undo();
    s.print();

    s.typeMsg("There");
    s.print();

    s.Redo();
    s.print();

    return 0;
}