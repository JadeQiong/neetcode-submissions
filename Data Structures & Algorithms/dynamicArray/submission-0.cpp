class DynamicArray {
public:
    int capacity;
    int* arr;
    int length;

    DynamicArray(int c) {
        capacity = c;
        length = 0;
        arr = new int[capacity];
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i]=n;
    }

    void pushback(int n) {
        if(length == capacity){
            resize();
        }
        arr[length] = n;
        length++;
    }

    int popback() {
        return arr[--length];
    }

    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];
        for(int i=0;i<length;i++){
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

    int getSize() {
        return length;
    }

    int getCapacity() {
        return capacity;
    }
};
