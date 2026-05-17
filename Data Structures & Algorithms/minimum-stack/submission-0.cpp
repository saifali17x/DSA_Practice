class MinStack {
private:
    int* arr;
    int maxSize;
    int topIndex;

public:
    MinStack() {
        int size = 1000;
        maxSize = size;
        arr = new int[maxSize];
        topIndex = -1;
    }

    void push(int val) {
        if (topIndex == maxSize - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++topIndex] = val;
    }

    void pop() {
        if (topIndex == -1) {
            cout << "Stack underflow" << endl;
            return;
        }
        topIndex--;
    }

    int top() {
        if (topIndex == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[topIndex];
    }

    int getMin() {
        if (topIndex == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        int minVal = arr[0];
        for (int i = 1; i <= topIndex; i++) {
            if (arr[i] < minVal) {
                minVal = arr[i];
            }
        }
        return minVal;
    }

    ~MinStack() {
        delete[] arr;
    }
};