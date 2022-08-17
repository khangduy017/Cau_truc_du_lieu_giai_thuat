#include"function.h"

int main() {
	DoublyLinkedList myList;
	myList.push(4);
	myList.push(2);
	myList.push(5);
	myList.push(1);
	myList.push(3);
	cout << "Doubly LinkedList: ";
	myList.display();
	myList.insertionSort();
	cout << "\nDoubly LinkedList after arange: ";
	myList.display();
}