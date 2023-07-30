#include <iostream>
using namespace std;
struct Node {
    char data;
    Node* next;

    Node(char val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    int length;
    Node* middle;
    int mid;

    LinkedList() : head(nullptr) {
        length=0;
    } 

    void insertAtMiddle(char val) {
        Node* newNode = new Node(val);

        if (head == nullptr||head->next==NULL) {
            Node* temp=head;
            head = newNode;
            head->next=temp;
            length++;
            middle=head;
            mid=0;


        } else {
            if((length/2)-1<=mid){
                Node* temp=middle->next;
                middle->next=newNode;
                newNode->next=temp;
            }
            else{
                middle=middle->next;
                mid++;
                Node* temp=middle->next;
                middle->next=newNode;
                newNode->next=temp;
                
            }
            length++;
            
            
        }
    }

    void printList() {
        Node* current = head;
        while (current) {
            cout << current->data ;
            current = current->next;
        }
    }
};

int main() {
    LinkedList list;
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=n-1;i>=0;i--){
        list.insertAtMiddle(s[i]);
    }


    list.printList();  // Output: A C B D

    return 0;
}
