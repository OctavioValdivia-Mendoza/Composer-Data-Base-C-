#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>
using namespace std;

template <class T>
class LinkedList {
private:
	Node<T>* tail;
	Node<T>* head;
public:

	// Receives: Nothing
	// Returns: Nothing
	// Does: Initializes the head and tail pointers to null
	LinkedList();

	// Receives: Nothing
	// Returns: Nothing
	// Does: Frees the memory used by the nodes in the linked list
	~LinkedList();

	// Receives: Nothing
	// Returns: Nothing	
	// Does: Prints the contents of the linked list
	void printList() const;

	// Receives: A value to be added to the end of the linked list
	// Returns: Nothing
	// Does: Adds a new node with the given value to the end of the linked list
	void append(const T data);

	// Receives: A value to be added to the beginning of the linked list
	// Returns: Nothing
	// Does: Adds a new node with the given value to the beginning of the linked list
	void prepend(const T data);

	// Receives: Nothing
	// Returns: True if a node was removed from the front of the linked list, false otherwise
	// Does: Removes the node at the front of the linked list, if one exists
	bool removeFront();

	// Receives: A value to be added to the linked list in sorted order
	// Returns: Nothing
	// Does: Adds a new node with the given value to the linked list in sorted order
	void insert(const T data);
	// Receives: A value to be added to the linked list in sorted order
	//returns true if the data was found and removed, false otherwise.
	bool remove(const T data);

	//Receives: A value to be added to the linked list in sorted order
	//Returns: true if the specified data is in the list, false otherwise.
	bool find(const T data);

	//Recieves: nothing
	//Returns: true if the list is empty;
	bool isEmpty() const;

	//Recieves: A value to be added to the linked list in sorted order
	//Returns first node
	bool operator!=(const T& other) const;
	T getFirst() const;

	//Recieves: nothing
	//Returns: last node
	T getLast() const;
};
//constructor
template <class T>
LinkedList<T>::LinkedList() {
	head = nullptr;
	tail = nullptr;
}

//destructor
template <class T>
LinkedList<T>::~LinkedList() {
	Node<T>* curr = head, * temp;
	while (curr) {
		temp = curr;
		curr = curr->next;
		delete temp;
	}
}

template <class T>
void LinkedList<T>::printList() const {
	Node<T>* iter = head;
	cout << "\n\n";
	while (iter != nullptr) {
		cout << iter->data << " ";
		iter = iter->next;
		cout << "\n";
	}
	cout << "\n";
}

template <class T>
void LinkedList<T>::append(const T data) {
	Node<T>* temp;
	Node<T>* iter;
	temp = new Node<T>;
	iter = head;
	temp->data = data;
	temp->next = nullptr;

	if (head == nullptr) {
		head = temp;
		return;
	}
	while (iter->next != nullptr) {
		iter = iter->next;
	}
	iter->next = temp;
}

template <class T>
void LinkedList<T>::prepend(const T data) {
	Node<T>* node = new Node<T>(data);
	node->next = head;
	head = node;
	if (!tail) {
		tail = node;
	}
}

template <class T>
bool LinkedList<T>::removeFront() {
	if (head == nullptr)
		return false;
	Node<T>* temp = head;
	head = head->next;
	delete temp;
	return true;

}

template <class T>
void LinkedList<T>::insert(const T data) {
	Node<T>* temp, * prev;
	Node<T>* newNode = new Node<T>(data);
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
		return;
	}
	temp = head;
	prev = nullptr;

	while (temp != nullptr) {
		if (newNode->data > temp->data) {
			prev = temp;
			temp = temp->next;
		}
		else {
			break;
		}
	}
	if (prev == nullptr) {
		newNode->next = head;
		head = newNode;
	}
	else {
		if (temp == nullptr) {
			tail->next = newNode;
			tail = newNode;
		}
		else {
			newNode->next = prev->next;
			prev->next = newNode;
		}
	}
}

template <class T>
bool LinkedList<T>::remove(const T data) {
	if (head == nullptr) {
		return false;
	}
	if (head->data == data) {
		return removeFront();
	}
	Node<T>* curr = head;
	while (curr->next != nullptr && curr->next->data != data) {
		curr = curr->next;
	}
	if (curr->next == nullptr) {
		return false;
	}
	Node<T>* removeNode = curr->next;
	curr->next = removeNode->next;
	if (removeNode == tail) {
		tail = curr;
	}
	delete removeNode;
	return true;
}

template <class T>
bool LinkedList<T>::find(const T data) {
	Node<T>* temp = head;
	while (temp != nullptr) {

		if (temp->data == data)
			break;
		temp = temp->next;
	}

	if (temp == nullptr)
		return false;

	return true;
}

template <class T>
bool operator != (const T& a, const T& b) {
	return !(a == b);
}

template <class T>
bool LinkedList<T>::isEmpty() const {
	return !head;
}

template <class T>
T LinkedList<T>::getFirst() const {
	return head->data;
}

template <class T>
T LinkedList<T>::getLast() const {
	return tail->data;
}

#endif