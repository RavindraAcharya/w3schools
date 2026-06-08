#include <iostream>
using namespace std;

class Node
{
public :
	int data;
	Node* next;

	Node(int value)
	{
		data = value;
		next = NULL;
	}
};


class List
{
private:
	Node* head;
	Node* tail;
public:

	List()
	{
		head = NULL;
		tail = NULL;
	}

	~List()
	{
		// Destructor to free memory
		Node* current = head;
		Node* nextNode;
		// Traverse the list and delete each node
		while (current != NULL)
		{
			nextNode = current->next;
			delete current;
			current = nextNode;
		}
	}

	void push_front(int value)
	{
		Node* newNode = new Node(value);	//dynamically allocate memory for new node
		//Node NewNode(value);			//create new node on stack

		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
			return;
		}
		else
		{
			// Insert at the beginning
			newNode->next = head;

			// Update head to point to the new node
			head = newNode;
		}
	}

	void push_back(int value)
	{
		Node* newNode = new Node(value);

		// If the linked list is empty
		if (head == NULL)
		{
			head = tail = newNode;
			return;
		}
		else
		{
			// Insert at the end
			tail->next = newNode;

			// Update tail to point to the new node
			tail = newNode;
		}
	}

	void display()
	{
		Node* temp = head;

		while (temp)
		{
			cout << temp->data << " -> ";
			temp = temp->next;
		}

	}

	//Node * pop_front()
	//{
	//	Node* temp = head;
	//	if (head == NULL)
	//		return NULL;
	//	// Move head to the next node
	//	head = head->next;

	//	// Return the removed node
	//	return temp;
	//}

	Node * pop_front()
	{
		if (head == NULL)
			return NULL;
		Node* temp = head; // Store the current head
		// Move head to the next node
		head = head->next;
		// If the list becomes empty, update tail to NULL
		if (head == NULL)
			tail = NULL;
		// Return the removed node
		return temp;
	}
};


int main()
{
	List myList;
	myList.push_back(10);
	myList.push_back(20);
	myList.push_front(5);
	myList.push_back(30);
	Node* temp = myList.pop_front();
	cout << "Deleted Data : " << temp->data << endl;
	myList.display();
	return 0;
}