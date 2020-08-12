#include <iostream>
using namespace std;

class LinkedList {
   private:
	class Node {
	   private:
		int mData;
		Node* mNext = nullptr;

	   public:
		Node(const int data) : mData(data) {}
		~Node() = default;
		void setData(const int newData) { mData = newData; }
		void setNext(Node* next) { mNext = next; }
		Node* next() { return mNext; }
		int data() { return mData; }
	};

	Node *head = nullptr, *tail = nullptr;

   public:
	void pushback(const int num);
	void insert(const int after, const int num);
	bool erase(const int num);
	bool exist(const int num);
};

void LinkedList::pushback(int num) {
	if (head == tail and tail == nullptr) {
		head = new Node(num);
		tail = head;
	}
	tail->setNext(new Node(num));
	tail = tail->next();
}

bool LinkedList::exist(const int num) {
	auto node = head;
	while (node != nullptr) {
		if (node->data() == num) {
			return true;
		}
	}
	return false;
}

void LinkedList::insert(const int after, const int num) {
	auto node = head;
	while (node->data() == after) {
		/* code */
	}
}

int main(int argc, char const* argv[]) { return 0; }
