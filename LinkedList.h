#ifndef LINKED_LIST
#define LINKED_LIST

using namespace std;

#include "ListInterface.h"
#include "node.h"

template<class ItemType>
class LinkedList: public ListInterface<ItemType> { 
private:
    Node<ItemType>* headPtr;
    int itemCount;

public:
    LinkedList();
    bool isEmpty() const;
    int getLength() const;
    bool insert(int newPosition, const ItemType& newEntry);
    bool remove(int position);
    void clear();
    ItemType getEntry(int position) const;
    ItemType replace(int position, const ItemType& newEntry);    
    ~LinkedList();
};
#include "LinkedList.cpp"
#endif
