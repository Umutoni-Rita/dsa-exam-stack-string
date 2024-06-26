#include <iostream>
#include <cstring>
using namespace std;

//Created a class for Stack
class Stack {
    char *arr;
    int nextIndex;
    int capacity;

public:
    Stack(int cap) {
        capacity = cap;
        arr = new char[capacity];
        nextIndex = 0;
    }

    // Returns the number of elements present in stack
    int size() {
        return nextIndex;
        }

    bool isEmpty() {
        return nextIndex == 0;
    }

    void push(char ele) {
        if (nextIndex == capacity) {
            cout << "Stack full" << endl;
            return;
        }
        arr[nextIndex] = ele;
        nextIndex++;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack empty" << endl;
            return;
        }
        nextIndex--;
    }

    char top() {
        if (isEmpty()) {
            cout << "Stack empty" << endl;
            return 0;
        }
        return arr[nextIndex - 1];
    }
};

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    // Created a stack with capacity equal to the length of the string
    Stack stack(str.length());

    cout << "Original string: " << str << endl;

    // Pushing all characters of the string into the stack one-by-one
    for (char c : str) {
        stack.push(c);
    }

    // Pop all characters from the stack one-by-one and store them back in the string
    for (int i = 0; i < str.length(); i++) {

        str[i] = stack.top(); //storing the popped characters in the same string
        stack.pop();
    }

    cout << "String after popping: " << str << endl;

    return 0;
}

/**
 Output:
    Enter a string: Hello World
    Original string: Hello World
    String after popping: dlroW olleH

    Process returned 0 (0x0)   execution time : 4.915 s
    Press any key to continue.
_____________________________________________________________

Observation:
    When the characters are pushed onto the stack and then popped back, the string is reversed.
    This is because of the LIFO (Last In, First Out) nature of the stack.

*/
