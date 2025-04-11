#include<iostream>
using namespace std;
class Queue{
    private:
    int *arr;
    int front, rear, size, capacity;
    public:
    Queue(int cap){
        capacity = cap;
        arr = new int[capacity]; 
        front = -1;
        rear = -1;
        size = 0;
    }
    ~Queue(){
        delete[] arr;  
    }
    void getDataQueue(){
        int numElements;
        cout << "Enter the number of elements to enqueue: ";
        cin >> numElements;
        cout << "Enter the elements to enqueue:" << endl;
        for (int i = 0; i < numElements; i++) {
            int value;
            cin >> value;
            enqueue(value);
        }
    }
    void enqueue(int value){
        if(size == capacity){
            cout<<"Queue Overflow."<<endl;
            return;
        }
        if(front == -1){
            front = 0;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }
    void displayEnqueue(){
        cout<<"Stack after enqueuing all elements: ";
        for(int i=0;i<size;i++){
            cout<<arr[(front+i)%capacity]<<" ";
        }
        cout<<endl;
    }
    void getDequeue(){
        int d;
        cout<<"How many items do you want to dequeue: "<<endl;
        cin>>d;
        for(int i=0;i<(d-1);i++){
            dequeue();
        }
    }
    void dequeue() {
        if (size == 0) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        front = (front + 1) % capacity;  
        size--;
        if (size == 0) {
            front = -1;
            rear = -1;
        }
        cout<<"Stack after dequeue: ";
        for(int i=0;i<size;i++){
            cout<<arr[(front+i)%capacity]<<" ";
        }
        cout<<endl;
    }
    void getReverseK(){
        int k;
        cout<<endl;
        cout<<"Enter the first k elements that you want to reverse: "<<endl;
        cin>>k;
        reverseFirstK(k);
    }
    void reverseFirstK(int a){
        if (a > size) {
            cout << "K is greater than the number of elements!" << endl;
            return;
        }
        for(int i=0;i<(a/2);i++){
            int temp = arr[(front+i)%capacity];
            arr[(front+i)%capacity] = arr[(front+a-1-i)%capacity];
            arr[(front+a-1-i)%capacity] = temp;
        }
        cout<<"Stack after reversing till "<<a<<" element ";
        for(int i=0;i<size;i++){
            cout<<arr[(front+i)%capacity]<<" ";
        }
        cout<<endl;
    }
    void interleave() {
        if (size % 2 != 0) {
            cout << "Queue size is odd, cannot interleave!" << endl;
            return;
        }
        int mid = size / 2;
        int firstHalf[capacity], secondHalf[capacity];
        for (int i = 0; i < mid; i++) {
            firstHalf[i] = arr[(front + i) % capacity];
        }
        for (int i = 0; i < mid; i++) {
            secondHalf[i] = arr[(front + mid + i) % capacity];
        }
        size = 0;
        front = -1;
        rear = -1;
        for (int i = 0; i < mid; i++) {
            enqueue(firstHalf[i]);
            enqueue(secondHalf[i]);
        }
        cout<<"Stack after interleaving: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] <<" ";
        }
    }
};
int main()
{
    int c;
    cout<<"Enter the capacity: "<<endl;
    cin>>c;
    Queue q1(c);
    q1.getDataQueue();
    q1.displayEnqueue();
    q1.getDequeue();
    q1.dequeue();
    q1.getReverseK();
    q1.interleave();
return 0;
}