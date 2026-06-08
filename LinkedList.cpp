#include <iostream>
using namespace std;

class Node
{
public :
	int data;
	Node* next;
};

class LinkedList
{
private:
	Node* head;
public:
	Node* createNode(int value)
	{
		Node* newNode = new Node();
		newNode->data = value;
		newNode->next = NULL;
		return newNode;
	}

	void InsertAtEnd(int value)
	{
		Node* newNode = createNode(value);

		// If the linked list is empty
		if (head == NULL)
		{
			head = newNode;
			return;
		}

		// Traverse to the end of the list
		Node* temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		// Insert the new node at the end
		temp->next = newNode;
	}

	void display()
	{
		// Traverse the linked list and print each node's data
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " -> ";
			temp = temp->next;
		}
		cout << "NULL" << endl;
	}

	LinkedList()
	{
		head = NULL;
	}

	~LinkedList()
	{
		// Destructor to free memory
		Node* current = head;
		Node* nextNode;
		while (current != NULL)
		{
			nextNode = current->next;
			delete current;
			current = nextNode;
		}
	}

	Node* getHead()
	{
		return head;
	}

	Node* getTail()
	{
		Node* temp = head;

		//
		if (temp == NULL)
			return NULL;

		//
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		// Return the tail node
		return temp;
	}

	Node * getMiddle()
	{
		Node* slow = head;
		Node* fast = head;
		// Traverse the list with two pointers
		while (fast != NULL && fast->next != NULL)
		{
			slow = slow->next;          // Move slow pointer by one
			fast = fast->next->next;    // Move fast pointer by two
		}
		// When fast pointer reaches the end, slow pointer will be at the middle
		return slow;
	}

	Node * search(int value)
	{
		Node* temp = head;
		// Traverse the list to find the value
		while (temp != NULL)
		{
			if (temp->data == value)
			{
				return temp; // Value found
			}
			temp = temp->next;
		}
		return NULL; // Value not found
	}

	Node* reverse()
	{
		Node* prev = NULL;
		Node* current = head;
		Node* next = NULL;
		while (current != NULL)
		{
			next = current->next; // Store next node
			current->next = prev; // Reverse current node's pointer
			prev = current;       // Move pointers one position ahead
			current = next;
		}
		head = prev; // Update head to new first node
		return head;
	}

	Node* getHeadPointer()
	{
		return head;
	}

	int length()
	{
		int count = 0;
		Node* temp = head;
		while (temp != NULL)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}

	int sum()
	{
		int total = 0;
		Node* temp = head;
		while (temp != NULL)
		{
			total += temp->data;
			temp = temp->next;
		}
		return total;
	}

	int max()
	{
		if (head == NULL)
			throw runtime_error("List is empty");
		int maxValue = head->data;
		Node* temp = head->next;
		while (temp != NULL)
		{
			if (temp->data > maxValue)
			{
				maxValue = temp->data;
			}
			temp = temp->next;
		}
		return maxValue;
	}

	void clear()
	{
		Node* current = head;
		Node* nextNode;
		while (current != NULL)
		{
			nextNode = current->next;
			delete current;
			current = nextNode;
		}
		head = NULL;
	}

	void initializeFromArray(int arr[], int size)
	{
		clear(); // Clear existing list
		for (int i = 0; i < size; i++)
		{
			InsertAtEnd(arr[i]);
		}
	}

	void initializeFromLinkedList(LinkedList& other)
	{
		clear(); // Clear existing list
		Node* temp = other.getHead();
		while (temp != NULL)
		{
			InsertAtEnd(temp->data);
			temp = temp->next;
		}
	}

	void concatenate(LinkedList& other)
	{
		if (head == NULL)
		{
			head = other.getHead();
			return;
		}
		Node* tail = getTail();
		tail->next = other.getHead();
	}

	void mergeSorted(LinkedList& other)
	{
		Node* dummy = new Node();
		Node* tail = dummy;
		Node* a = head;
		Node* b = other.getHead();
		while (a != NULL && b != NULL)
		{
			if (a->data <= b->data)
			{
				tail->next = a;
				a = a->next;
			}
			else
			{
				tail->next = b;
				b = b->next;
			}
			tail = tail->next;
		}
		if (a != NULL)
			tail->next = a;
		else
			tail->next = b;
		head = dummy->next;
		delete dummy;
	}

	void removeDuplicates()
	{
		Node* current = head;
		while (current != NULL && current->next != NULL)
		{
			if (current->data == current->next->data)
			{
				Node* duplicate = current->next;
				current->next = current->next->next;
				delete duplicate;
			}
			else
			{
				current = current->next;
			}
		}
	}

	void reverseRecursiveUtil(Node* current, Node* prev)
	{
		if (current == NULL)
		{
			head = prev;
			return;
		}
		Node* next = current->next;
		current->next = prev;
		reverseRecursiveUtil(next, current);
	}

	void reverseRecursive()
	{
		reverseRecursiveUtil(head, NULL);
	}

	void detectAndRemoveLoop()
	{
		Node* slow = head;
		Node* fast = head;
		// Detect loop using Floyd's Cycle-Finding Algorithm
		while (fast != NULL && fast->next != NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
				break;
		}
		// If loop exists
		if (slow == fast)
		{
			slow = head;
			Node* prev = NULL; // To keep track of the node before fast
			while (slow != fast)
			{
				prev = fast;
				slow = slow->next;
				fast = fast->next;
			}
			// Remove loop
			prev->next = NULL;
		}
	}

	void sort()
	{
		if (head == NULL || head->next == NULL)
			return;
		bool swapped;
		do
		{
			swapped = false;
			Node* current = head;
			while (current->next != NULL)
			{
				if (current->data > current->next->data)
				{
					swap(current->data, current->next->data);
					swapped = true;
				}
				current = current->next;
			}
		} while (swapped);
	}

	void reverseInGroups(int k)
	{
		head = reverseInGroupsUtil(head, k);
	}

	void reverseInGroupsUtil(Node* head, int k)
	{
		Node* current = head;
		Node* prev = NULL;
		Node* next = NULL;
		int count = 0;
		// Reverse first k nodes of the linked list
		while (current != NULL && count < k)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
			count++;
		}
		// next is now a pointer to (k+1)th node
		if (next != NULL)
			head->next = reverseInGroupsUtil(next, k);
		// prev is new head of the reversed group
		return prev;
	}

	void removeNthFromEnd(int n)
	{
		Node* dummy = new Node();
		dummy->next = head;
		Node* first = dummy;
		Node* second = dummy;
		// Move first n+1 steps ahead
		for (int i = 0; i <= n; i++)
		{
			first = first->next;
		}
		// Move both pointers until first reaches the end
		while (first != NULL)
		{
			first = first->next;
			second = second->next;
		}
		// Remove the nth node from end
		Node* toDelete = second->next;
		second->next = second->next->next;
		delete toDelete;
		head = dummy->next;
		delete dummy;
	}

	void rotate(int k)
	{
		if (head == NULL || k == 0)
			return;
		// Compute the length of the list
		Node* tail = head;
		int length = 1;
		while (tail->next != NULL)
		{
			tail = tail->next;
			length++;
		}
		// Make the list circular
		tail->next = head;
		// Find the new tail: (length - k % length - 1)th node
		int newTailPos = length - (k % length) - 1;
		Node* newTail = head;
		for (int i = 0; i < newTailPos; i++)
		{
			newTail = newTail->next;
		}
		// Set the new head
		head = newTail->next;
		// Break the circle
		newTail->next = NULL;
	}

	void removeValue(int value)
	{
		while (head != NULL && head->data == value)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		Node* current = head;
		while (current != NULL && current->next != NULL)
		{
			if (current->next->data == value)
			{
				Node* temp = current->next;
				current->next = current->next->next;
				delete temp;
			}
			else
			{
				current = current->next;
			}
		}
	}

	void printReverseUtil(Node* node)
	{
		if (node == NULL)
			return;
		printReverseUtil(node->next);
		cout << node->data << " ";
	}

	void printReverse()
	{
		printReverseUtil(head);
		cout << endl;
	}

	void removeCycle()
	{
		detectAndRemoveLoop();
	}

	void splitAlternate(LinkedList& list1, LinkedList& list2)
	{
		Node* current = head;
		int count = 0;
		while (current != NULL)
		{
			if (count % 2 == 0)
			{
				list1.InsertAtEnd(current->data);
			}
			else
			{
				list2.InsertAtEnd(current->data);
			}
			current = current->next;
			count++;
		}
	}

	void swapNodes(int x, int y)
	{
		if (x == y)
			return;
		Node* prevX = NULL, * currX = head;
		while (currX != NULL && currX->data != x)
		{
			prevX = currX;
			currX = currX->next;
		}
		Node* prevY = NULL, * currY = head;
		while (currY != NULL && currY->data != y)
		{
			prevY = currY;
			currY = currY->next;
		}
		if (currX == NULL || currY == NULL)
			return;
		if (prevX != NULL)
			prevX->next = currY;
		else
			head = currY;
		if (prevY != NULL)
			prevY->next = currX;
		else
			head = currX;
		Node* temp = currX->next;
		currX->next = currY->next;
		currY->next = temp;
	}

	void removeEvenPositionedNodes()
	{
		if (head == NULL)
			return;
		Node* current = head;
		while (current != NULL && current->next != NULL)
		{
			Node* temp = current->next;
			current->next = current->next->next;
			delete temp;
			current = current->next;
		}

	}

	void appendLastNToFront(int n)
	{
		if (head == NULL || n <= 0)
			return;
		// Compute the length of the list
		Node* tail = head;
		int length = 1;
		while (tail->next != NULL)
		{
			tail = tail->next;
			length++;
		}
		// If n is greater than or equal to length, do nothing
		if (n >= length)
			return;
		// Find the new tail: (length - n - 1)th node
		int newTailPos = length - n - 1;
		Node* newTail = head;
		for (int i = 0; i < newTailPos; i++)
		{
			newTail = newTail->next;
		}
		// Set the new head
		Node* newHead = newTail->next;
		newTail->next = NULL;
		tail->next = head;
		head = newHead;
	}

	void removeDuplicatesUnsorted()
	{
		if (head == NULL)
			return;
		unordered_set<int> seen;
		Node* current = head;
		Node* prev = NULL;
		while (current != NULL)
		{
			if (seen.find(current->data) != seen.end())
			{
				prev->next = current->next;
				delete current;
				current = prev->next;
			}
			else
			{
				seen.insert(current->data);
				prev = current;
				current = current->next;
			}
		}
	}

	void pairwiseSwap()
	{
		Node* temp = head;
		while (temp != NULL && temp->next != NULL)
		{
			swap(temp->data, temp->next->data);
			temp = temp->next->next;
		}
	}

	void moveToFront(int value)
	{
		if (head == NULL || head->data == value)
			return;
		Node* prev = NULL;
		Node* current = head;
		while (current != NULL && current->data != value)
		{
			prev = current;
			current = current->next;
		}
		if (current == NULL)
			return; // Value not found
		prev->next = current->next;
		current->next = head;
		head = current;
	}

	void segregateEvenOdd()
	{
		if (head == NULL)
			return;
		Node* evenStart = NULL;
		Node* evenEnd = NULL;
		Node* oddStart = NULL;
		Node* oddEnd = NULL;
		Node* current = head;
		while (current != NULL)
		{
			int val = current->data;
			if (val % 2 == 0)
			{
				if (evenStart == NULL)
				{
					evenStart = current;
					evenEnd = evenStart;
				}
				else
				{
					evenEnd->next = current;
					evenEnd = evenEnd->next;
				}
			}
			else
			{
				if (oddStart == NULL)
				{
					oddStart = current;
					oddEnd = oddStart;
				}
				else
				{
					oddEnd->next = current;
					oddEnd = oddEnd->next;
				}
			}
			current = current->next;
		}
		if (evenStart == NULL || oddStart == NULL)
			return;
		evenEnd->next = oddStart;
		oddEnd->next = NULL;
		head = evenStart;
	}

	void reverseDataIterative()
	{
		int len = length();
		if (len <= 1)
			return;
		int* arr = new int[len];
		Node* temp = head;
		for (int i = 0; i < len; i++)
		{
			arr[i] = temp->data;
			temp = temp->next;
		}
		temp = head;
		for (int i = len - 1; i >= 0; i--)
		{
			temp->data = arr[i];
			temp = temp->next;
		}
		delete[] arr;
	}

	void reverseDataRecursiveUtil(Node* node, int& index, int len)
	{
		if (node == NULL)
			return;
		reverseDataRecursiveUtil(node->next, index, len);
		if (index < len / 2)
		{
			swap(node->data, getNodeAt(len - index - 1)->data);
			index++;
		}
	}

	void reverseDataRecursive()
	{
		int len = length();
		int index = 0;
		reverseDataRecursiveUtil(head, index, len);
	}

	void reverseInGroupsData(int k)
	{
		int len = length();
		if (len == 0 || k <= 1)
			return;
		Node* current = head;
		while (current != NULL)
		{
			int count = 0;
			Node* temp = current;
			int* arr = new int[k];
			while (temp != NULL && count < k)
			{
				arr[count] = temp->data;
				temp = temp->next;
				count++;
			}
			for (int i = count - 1; i >= 0; i--)
			{
				current->data = arr[i];
				current = current->next;
			}
			delete[] arr;
		}
	}

	void rotateData(int k)
	{
		int len = length();
		if (len == 0 || k <= 0 || k % len == 0)
			return;
		k = k % len;
		int* arr = new int[len];
		Node* temp = head;
		for (int i = 0; i < len; i++)
		{
			arr[i] = temp->data;
			temp = temp->next;
		}
		temp = head;
		for (int i = len - k; i < len; i++)
		{
			temp->data = arr[i];
			temp = temp->next;
		}
		for (int i = 0; i < len - k; i++)
		{
			temp->data = arr[i];
			temp = temp->next;
		}
		delete[] arr;
	}

	void bubbleSortData()
	{
		int len = length();
		if (len <= 1)
			return;
		for (int i = 0; i < len - 1; i++)
		{
			Node* current = head;
			for (int j = 0; j < len - i - 1; j++)
			{
				if (current->data > current->next->data)
				{
					swap(current->data, current->next->data);
				}
				current = current->next;
			}
		}
	}

	void selectionSortData()
	{
		int len = length();
		if (len <= 1)
			return;
		Node* current = head;
		while (current != NULL)
		{
			Node* minNode = current;
			Node* temp = current->next;
			while (temp != NULL)
			{
				if (temp->data < minNode->data)
				{
					minNode = temp;
				}
				temp = temp->next;
			}
			if (minNode != current)
			{
				swap(current->data, minNode->data);
			}
			current = current->next;
		}
	}

	void insertionSortData()
	{
		if (head == NULL || head->next == NULL)
			return;
		Node* sorted = NULL;
		Node* current = head;
		while (current != NULL)
		{
			Node* next = current->next;
			if (sorted == NULL || sorted->data >= current->data)
			{
				current->next = sorted;
				sorted = current;
			}
			else
			{
				Node* temp = sorted;
				while (temp->next != NULL && temp->next->data < current->data)
				{
					temp = temp->next;
				}
				current->next = temp->next;
				temp->next = current;
			}
			current = next;
		}
		head = sorted;
	}

	void clearList()
	{
		clear();
	}

	void initializeFromList(LinkedList& other)
	{
		initializeFromLinkedList(other);
	}

	void concatenateList(LinkedList& other)
	{
		concatenate(other);
	}

	Node * getNodeAt(int index)
	{
		Node* temp = head;
		int count = 0;
		while (temp != NULL)
		{
			if (count == index)
				return temp;
			count++;
			temp = temp->next;
		}
		return NULL; // Index out of bounds
	}

	
};