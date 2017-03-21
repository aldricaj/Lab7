#include "LinkedList.h"
#include <iostream>

using namespace std;

int main() {
	LinkedList<int> link = LinkedList<int>();
	link.AddItem(new int(1));
	link.AddItem(new int(3));
	link.AddItem(new int(2));
	int* n = new int(1);
	while (n != nullptr) {
		n = link.SeeNext();
		cout << *n << endl;
	}

	return 0;
}