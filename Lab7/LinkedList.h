#pragma once

template <class T> class LinkedList {
protected:
	class Node {
	public:
		T value;
		Node* next;
		
		Node(T* val, Node* nextNode = nullptr) {
			value = *val;
			next = nextNode;
		}

		// comparison operators
		bool operator==(Node *other) { value == other->value; }
		bool operator<(Node *other) { value < other->value; }
		bool operator<=(Node *other) { value <= other->value; }
		bool operator>(Node *other) { value > other->value; }
		bool operator>=(Node *other) { value >= other->value; }
	};

	int length;
	Node* head;

	int iterIndex;
	Node* iterCurrent;
	
public:
	LinkedList() {
		head = nullptr;
		length = 0;
		iterIndex = 0;
		iterCurrent = head;
	}

	void AddItem(T* item) {
		if (length == 0) {
			head = new Node(item);
		}
		else {
			int index = 0;
			Node* current = head;
			Node* last = nullptr;			

			// find the index to insert the item at
			while (index < length && (current->value) < *item) {
				last = current;
				current = current->next;
				index++;
			}
			if (last == nullptr) {
				last = current;
			}

			last->next = new Node(item, last->next);
		}

		length++;
	}

	// T must have a == operator overload for C
	// Will throw InvalidInputException if this is not the case
	template <class C> T* GetItem(C primaryKey) {
		try {
			return nullptr;
		}
		catch (err) {
			throw InvalidInputException();
		}
	}

	template <class C> bool IsInList(C primaryKey) {
		try {
			return false;
		}
		catch (err) {
			throw InvalidInputException();
		}
	}

	bool IsEmpty() {
		return false;
	}

	int Length() {
		return 0;
	}

	T* SeeNext() {
		if (length == 0) {
			throw EmptyListException();
		}
		if (iterIndex == length) {
			return nullptr;
		}
		if (iterIndex > length) { // being extra careful about infinite loops
			throw IndexOutOfBoundsException();
		}

		T* next = &iterCurrent->value;
		if (iterCurrent != nullptr) {
			iterCurrent = iterCurrent->next;
		}
		iterIndex++;
		return next;
	}

	T* SeeAt(int index) {

	}

	void ResetEnum() {

	}

	~LinkedList() {

	}
	

};

class InvalidInputException {};
class EmptyListException {};
class IndexOutOfBoundsException {};
