class MyCircularQueue {
    vector<int> data;

    int front;
    int rear;
    int count;
    int cap;

    /// modul index (rear or front + 1) % cap 
public:
    MyCircularQueue(int k) {
        front = 0;
        rear = 0;
        count = 0;
        data.resize(k);
        cap = k;
    }
    
    bool enQueue(int value) {
        // build from rear to front, since rear is new, and front is old
        if (count < cap ) {
        data[rear] = value;
        rear = (rear + 1)%cap;
        count++;
        return true;
        }
        return false;
    }
    
    bool deQueue() {
         if (count == 0) {
            return false;
        }

        front = (front + 1) % cap;

        count--;

        return true;
        
    }
    
    int Front() {
        if (count <= 0) {
            return -1;
        }
        return data[front];
    }
    
    int Rear() {
        if (count == 0) {
            return -1;
        }

        int lastIndex = (rear - 1 + cap) % cap;

        return data[lastIndex];
    }
    
    bool isEmpty() {
        if (count == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    
    bool isFull() {
        if (count >= cap) {
            return true;
        }
        else {
            return false;
        }
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */