class DynamicArray {
public:

    int* arr;
    int cap;
    int ptr;
    DynamicArray(int capacity) {
        arr = new int[capacity];
        cap = capacity;
        ptr = 0;
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if (ptr >= cap)
            resize();
        arr[ptr++] = n;
    }

    int popback() {
        return arr[--ptr];
    }

    void resize() {
        int* temp = new int[cap*2];
        for (int i = 0; i < cap; i++)
            temp[i] = arr[i];
        delete[] arr;

        arr = temp;
        cap*=2;
    }

    int getSize() {
        return ptr;
    }

    int getCapacity() {
        return cap;
    }
};
