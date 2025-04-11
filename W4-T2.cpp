#include<iostream>
using namespace std;
class Stack{
    private:
    int arr[10], top , pop;
    public:
    Stack(){
        top = -1;
    }
    void pushData(){
        cout<<"Enter 10 elements: "<<endl;
        for(int i=0;i<10;i++){
            cin>>arr[i];
        }
        top = 9;
    }
    void popData(){
        cout<<"How many elements do you want to pop?? "<<endl;
        cin>>pop;
        while(pop>(top+1)){
            cout<<"Cannot pop "<<pop<<" elements."<<endl;
            cin>>pop;
        }
        for(int i=0;i<pop;i++){
            cout<<"Popped: "<<arr[top]<<endl;
            top--;
        }
    }
    void findMiddle(){
        if(top == -1){
            cout<<"Stack is empty."<<endl;
            return;
        }
        int midIndex = (top+1)/2;
        cout<<"Middle Element: "<<arr[midIndex]<<endl;
    }
    void reverseBottom(){
        int mid = (top+1)/2;
        for (int i=0;i<mid/2;i++) {
            int temp = arr[i];
            arr[i] = arr[mid - 1 - i];
            arr[mid - 1 - i] = temp;
        }
        cout<<"Stack after reversing bottom half: ";
        for(int i=0;i<=top;i++){
            cout<<arr[i]<<" ";
        }
    }
};
int main()
{
    Stack s1;
    s1.pushData();
    s1.popData();
    s1.findMiddle();
    s1.reverseBottom();
return 0;
}