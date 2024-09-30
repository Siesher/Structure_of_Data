#include <iostream>
#include <bits/c++config.h>

template<typename T>

class Dynamic_List{
    private:

    struct Node{
        T data;
        Node* next;
        Node(T val): data(val), next(nullptr) {}
    };

    Node* head;

    public:
    Dynamic_List(): head(nullptr){}

    ~Dynamic_List(){
        while(head){
            pop_front();
        }
    }

    void push_front(T val){
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void pop_front(){
        if(head){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert_at(T val, int index){
        if(index == 0){
            push_front(val);
            return;
        }

        Node* current = head;
        for(int i = 0; i != index - 1 && current != nullptr; ++i){
            current = current->next;
        }

        if(current != nullptr){
            Node* newNode = new Node(val);
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void remove_at(int index){
        if(index == 0){
            pop_front();
            return;
        }

        Node* current = head;
        for(int i = 0; i < index - 1 && current != nullptr; ++current){
            current = current->next;
        }

        if(current != nullptr && current->next != nullptr){
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    int find(T value) const{
        Node* current = head;
        int index = 0;
        
        while(current){
            if(current->data == value){
                return index;
            }
            current = current->next;
            ++index;
        }
        return -1;
    }

    void print() const{
        Node* current = head;
        while(current){
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main(){
    Dynamic_List<int> myList;
    myList.push_front(1);
    myList.push_front(2);
    myList.push_front(3);

    std::cout << "List before insertions: ";
    myList.print();

    myList.insert_at(4, 1);
    myList.insert_at(5, 3);

    std::cout << "List after insertions: ";
    myList.print();

    myList.remove_at(1);

    std::cout << "List after removal: ";
    myList.print();

    std::cout << "Index of value 4: " << myList.find(4) << std::endl;

    myList.insert_at(9, 2);
    std::cout << "List after insertions: ";
    myList.print();

    std::cout << "Index of value 9: " << myList.find(9) << std::endl;

    return 0;
}