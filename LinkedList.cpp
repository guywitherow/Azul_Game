
#include "LinkedList.h"

#include <exception>
#include <iostream>
#include <fstream>
#include <limits>

Node::Node(int value, Node* next) :
   value(value),
   next(next)
{}

LinkedList::LinkedList() 
{
   head = nullptr;
}

LinkedList::LinkedList(const LinkedList& other) 
{
   // TODO
}

LinkedList::~LinkedList() {
   // TODO
}

unsigned int LinkedList::size() const {
   unsigned int count = 0;
   Node* current = head;
   while(current != nullptr) {
      ++count;
      current = current->next;
   }

   return count;
}

int LinkedList::get(const unsigned int index) const {
   int count = 0;
   Node* current = head;
   int returnValue = 0;
   // int returnValue = std::numeric_limits<int>::min();
   if (index < size()) {
      while(count < index) {
         ++count;
         current = current->next;
      }
      returnValue = current->value;
   } else {
      throw std::out_of_range("Linked List get - index out of range");
   }
   
   return returnValue;
}

// Version of get that returns error "code"
bool LinkedList::get(const int index, int& returnValue) const {
   bool error = true;
   int count = 0;
   Node* current = head;
   if (index >= 0 && index < size()) {
      while(count < index) {
         ++count;
         current = current->next;
      }
      returnValue = current->value;
      error = false;
   }
   
   return error;
}

void LinkedList::addFront(int value) {
   Node* toAdd = new Node(value, nullptr);

   if (head == nullptr) {
      head = toAdd;
   } else {
      Node* moveBack = head;
      toAdd->next = moveBack;
      head = toAdd;
   }
}

void LinkedList::addBack(int value) {
   Node* toAdd = new Node(value, nullptr);

   if (head == nullptr) {
      head = toAdd;
   } else {
      Node* current = head;
      while(current->next != nullptr) {
         current = current->next;
      }

      current->next = toAdd;
   }
}

void LinkedList::removeBack() {

   if (head == nullptr) {
      //do nothing
   } else {
      Node* current = head;
      while(current->next->next != nullptr) {
         current = current->next;
      }
      delete current->next;
      current->next = nullptr;
   }
}

void LinkedList::removeFront() {
   // TODO
}

void LinkedList::clear() {
   // TODO
}

