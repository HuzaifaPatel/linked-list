// Author: Huzaifa Patel

struct Node{
	void* data;
	struct Node* next;
} Node;

typedef struct LinkedList{
	struct Node* node;
	int size;
} LinkedList;

// struct Node* initNode();
LinkedList* initLinkedList();
int push(LinkedList** linkedList, void* data);
int addNode(LinkedList** linkedList, void* data, int index);
int pop(LinkedList** linkedList);
int removeNode(LinkedList** linkedList, int index);
struct Node* getNode(LinkedList** linkedList, int index);
struct Node* getHead(LinkedList** linkedList);
struct Node* getTail(LinkedList** linkedList);
int getSize(LinkedList* linkedList);
void reverse();
void shuffle();
int clear(LinkedList** linkedList);
void print(LinkedList** linkedList);