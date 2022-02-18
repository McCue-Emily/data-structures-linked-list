#include <string>
#include "LinkedList.h"
#include "node.h"

template<class ItemType> 
LinkedList<ItemType>::LinkedList(){
    itemCount = 0;
    headPtr = nullptr;
}

template<class ItemType> 
bool LinkedList<ItemType>::isEmpty() const{
    return itemCount == 0;
}

template<class ItemType> 
int LinkedList<ItemType>::getLength() const{
    return itemCount;
}

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry){

    Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
    Node<ItemType>* curPtr = headPtr;
    Node<ItemType>* nextPtr;


    if (newPosition == 0) {
        headPtr = newNodePtr;
        headPtr->setNext(curPtr);
        itemCount++;
        return headPtr;

    }

    bool ableToSet = (newPosition >= 1) && (newPosition <= itemCount);

    if (ableToSet) {

        for (int i = 0; i < itemCount && curPtr != nullptr; i++) {

            if(i == newPosition - 1) {
                nextPtr = curPtr->getNext();
                curPtr->setNext(newNodePtr);
                newNodePtr->setNext(nextPtr);
                itemCount++;
                return newNodePtr;
            }
            curPtr = curPtr->getNext();
        }

    }
    
    return true;
}

template<class ItemType>
bool LinkedList<ItemType>::remove(int position){

    Node<ItemType>* curPtr = headPtr;
    Node<ItemType>* nextPtr;


    if (position == 0) {
        headPtr = headPtr->getNext();
        delete curPtr;
        itemCount--;
        return headPtr;

    }

    bool ableToSet = (position >= 1) && (position <= itemCount);

    if (ableToSet) {

        for (int i = 0; i < itemCount && curPtr != nullptr; i++) {

            if(i == position - 1) {
                nextPtr = curPtr->getNext();
                curPtr->setNext(nextPtr->getNext());
                delete nextPtr;
                itemCount--;
                return true;
            }
            curPtr = curPtr->getNext();
        }

    }
    
    return false;

}

template<class ItemType>
void LinkedList<ItemType>::clear(){
    Node<ItemType>* nodeToDeletePtr = headPtr;
    while(headPtr != nullptr){
        headPtr = headPtr->getNext();
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = headPtr;
        itemCount--;
    }
}

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const{
    Node<ItemType>* curPtr = headPtr;

    for (int i = 0; i < itemCount && curPtr != nullptr; i++){
        if(i == position){
            return curPtr->getItem();
        }
        curPtr = curPtr->getNext();
    }
    return "No entry found";
}

template<class ItemType>
ItemType LinkedList<ItemType>::replace(int position, const ItemType& newEntry) {

    Node<ItemType>* curPtr = headPtr;

    bool ableToSet = (position >= 1) && (position <= itemCount);

    if (ableToSet) {

        for (int i = 0; i < itemCount && curPtr != nullptr; i++) {

            if(i == position) {
                curPtr->setItem(newEntry);
                return curPtr->getItem();
            }

            curPtr = curPtr->getNext();
        }

    }
    return "No replacement found";
}

template<class ItemType> 
LinkedList<ItemType>::~LinkedList(){
    clear();
}
