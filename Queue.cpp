#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int frontIndex;
    int rearIndex;
    int capacity;
    int count;

public:
    Queue(int size) {
        arr = new int[size];
        capacity = size;
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = value;
        count++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        frontIndex = (frontIndex + 1) % capacity;
        count--;
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[frontIndex];
    }

    int rear() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[rearIndex];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }

    int size() {
        return count;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        for (int i = 0; i < count; i++) {
            int index = (frontIndex + i) % capacity;
            cout << arr[index] << " ";
        }
        cout << endl;
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    cout << "Front: " << q.front() << endl;
    cout << "Rear: " << q.rear() << endl;
    cout << "Size: " << q.size() << endl;
    cout << (q.isEmpty() ? "Empty" : "Not Empty") << endl;
    return 0;
}
