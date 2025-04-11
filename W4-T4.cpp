#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
class List {
    Node* head;
    Node* tail;
public:
    List(){
        head = NULL;
        tail = NULL;
    }
    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }
    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    void push_middle(int val, int pos){
        if(pos < 0){
            cout << "Invalid position." << endl;
        }
        if(pos == 0){
            push_front(val);
        }
        Node* temp = head;
        for(int i = 0; i < pos - 1; i++){
            temp = temp->next;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void printLL(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    bool hasCycle(Node* head){
        Node* slow = head;
        Node* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                cout << "Loop detected." << endl;
                return true;
            }
        }
        return false;
    }
    void removeLoop(){
        Node* slow = head;
        Node* fast = head;
        bool loopExists = false;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                loopExists = true;
                break;
            }
        }
        if(!loopExists){
            cout << "No loop to remove." << endl;
            return;
        }
        slow = head;
        if(slow == fast){
            while(fast->next != slow){
                fast = fast->next;
            }
        }
        else{
            while(slow->next != fast->next){
                slow = slow->next;
                fast = fast->next;
            }
        }
        fast->next = NULL;
        cout << "Loop removed successfully." << endl;
    }
    void findNthFromEnd(int n){
        Node* first = head;
        Node* second = head;
        for(int i = 0; i < n; i++){
            if(second == NULL){
                cout << "List is too short.\n";
                return;
            }
            second = second->next;
        }
        while(second != NULL){
            first = first->next;
            second = second->next;
        }
        cout << first->data << endl;
    }
    Node* reverseK(Node* start, int k){
        Node* prev = NULL;
        Node* curr = start;
        Node* next = NULL;
        int count = 0;
        while(curr != NULL && count < k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if(next != NULL){
            start->next = reverseK(next, k);
        }
        return prev;
    }
    void reverseInGroups(int k){
        head = reverseK(head, k);
    }
    void createLoop(){
        if(head == NULL) {
            return;
        }
        Node* temp = head;
        while(temp != NULL && temp->next != NULL){
            temp = temp->next;
        }
        if(temp != NULL){
            temp->next = head->next;  
        }
    }
};
int main() {
    List ll;
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(6);
    ll.push_middle(5, 4);
    cout << "Original Linked List: ";
    ll.printLL();
    cout << endl;
    cout << "Creating a loop in the list for testing: ";
    ll.createLoop(); 
    ll.removeLoop(); 
    cout << "List after removing the loop: ";
    ll.printLL();
    cout << endl;
    cout << "Finding 2nd node from the end: ";
    ll.findNthFromEnd(2); 
    cout << "Reversing in groups of 2: ";
    ll.reverseInGroups(2);
    ll.printLL();
    cout << endl;
    return 0;
}
