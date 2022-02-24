#include <iostream> 

#include "List.h"

List::List() { 
    head = nullptr;
}

List::~List() { 
    delete this->head;
    head = nullptr;
}

void List::insert(std::string data) { 
    // create a new node 
    Node *new_node = new Node(data); 

    // insert new node 
    new_node->setNext(head);
    head = new_node;
}

std::string List::toString() { 
    // if(head == nullptr) { 
    //     return "";
    // }

    Node *walker = head; 
    std::string s = "";
    while(walker != nullptr) { 
        s = s + walker->getData() + "-->";
        walker = walker->getNext();
    }

    s = s + "nullptr";

    return s; 
}

int List::locate(std::string data) { 
    int location = 0; 
    Node *walker = head; 

    while(walker != nullptr) { 
        if(walker->getData() == data) { 
            return location; 
        }

        location++; 
        walker = walker->getNext();
    }

    return -1;
}

void List::remove(int location) { 
    if(location < 0) { 
        return;
    }

    // Node *temp = nullptr; 
    // Node *walker = head; 
    // int counter = 0;
    // Node *temp_node = nullptr;

    // Node *new_node = new Node(data); 
    // insert new node 

    // new_node->setNext(head);
    // head = new_node;

    for(int i = 0; i < 2; i++) { 
        Node *walker = head; 
        int counter = 0;
        Node *temp_node = nullptr;

        while(walker != nullptr) { 
        if(counter != location) { 
             // new_node->setNext(head);
            // head = new_node;
            Node *new_node = new Node(walker->getData());

            // temp_node = new Node(walker->getData());
            // temp_node->setNext(walker->getNext());

            new_node->setNext(temp_node);
            temp_node = new_node;
        }

        counter++;
        walker = walker->getNext();
    }

    head = temp_node;
    }

    
}

