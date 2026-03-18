class MyCircularDeque {
public:
    vector<int> dq;
    int front, rear, size, cap;

    MyCircularDeque(int k) {
        dq.resize(k);
        cap = k;
        front = -1;
        rear = -1;
        size = 0;
    }

    bool insertFront(int value) {
        if(size == cap) return false;

        if(size == 0) {
            front = rear = 0;
        } else {
            front = (front - 1 + cap) % cap;
        }

        dq[front] = value;
        size++;
        return true;
    }

    bool insertLast(int value) {
        if(size == cap) return false;

        if(size == 0) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % cap;
        }

        dq[rear] = value;
        size++;
        return true;
    }

    bool deleteFront() {
        if(size == 0) return false;

        front = (front + 1) % cap;
        size--;
        return true;
    }

    bool deleteLast() {
        if(size == 0) return false;

        rear = (rear - 1 + cap) % cap;
        size--;
        return true;
    }

    int getFront() {
        if(size == 0) return -1;
        return dq[front];
    }

    int getRear() {
        if(size == 0) return -1;
        return dq[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == cap;
    }
};