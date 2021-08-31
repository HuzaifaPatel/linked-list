// Author: Huzaifa Patel

#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	LinkedList* ll = initLinkedList();
}

LinkedList* initLinkedList(){
	LinkedList* newLinkedList = malloc(sizeof(LinkedList));

	if(newLinkedList == NULL){
		exit(1);
	}

	newLinkedList->size = 0;
	newLinkedList->node = NULL;
	return newLinkedList;
}

int push(LinkedList** linkedList, void* data){
	struct Node* newNode = malloc(sizeof(struct Node));

	if(newNode == NULL){
		return 1;
	}

	newNode->data = data;
	(*linkedList)->node = newNode;
	newNode->next = NULL;
	(*linkedList)->size++;

	return 0;
}

int addNode(LinkedList** linkedList, void* data, int index){
	if(index < 0 || index > getSize(*linkedList)){
		return 1;
	}

	struct Node* newNode = malloc(sizeof(struct Node));

	if(newNode == NULL){
		return 1;
	}

	newNode->data = data;
	
	struct Node* tempNode = (*linkedList)->node;
	
	if(!index){
		(*linkedList)->node = newNode;
		newNode->next = tempNode;
	}else{
		struct Node* holderNode;

		for(int i = 1; i < index; i++){
			tempNode = tempNode->next;
		}

		holderNode = tempNode->next;
		tempNode->next = newNode;
		newNode->next = holderNode;
	}

	(*linkedList)->size++;
}

int pop(LinkedList** linkedList){
	if(!getSize(*linkedList)){
		return 1;
	}

	struct Node* tempNode = (*linkedList)->node;

	for(int i = 0; i < getSize(*linkedList) - 1; i++){
		tempNode = tempNode->next;
	}

	free(tempNode->next);
	tempNode->next = NULL;

	(*linkedList)->size--;
}

int removeNode(LinkedList** linkedList, int index){
	if(!getSize(*linkedList) || index >= getSize(*linkedList)){
		return 1;
	}

	struct Node* tempNode = (*linkedList)->node;

	for(int i = 1; i < index; i++){
		tempNode = tempNode->next;
	}

	if(!index){
		(*linkedList)->node = (*linkedList)->node->next;
		free(tempNode);	
	}else if(getSize(*linkedList) - 1 == index){
		free(tempNode->next);
		(*linkedList)->node = tempNode;
		(*linkedList)->node->next = NULL;
	}else{
		struct Node* nodeHolder = tempNode->next->next;
		free(tempNode->next);
		tempNode->next = nodeHolder;
	}

	(*linkedList)->size--;
}

struct Node* getNode(LinkedList** linkedList, int index){
	struct Node* tempNode = (*linkedList)->node;

	if(index < 0 || getSize(*linkedList) > index + 1){
		return tempNode;
	}

	for(int i = 0; i < index; i++){
		tempNode = tempNode->next;
	}

	return tempNode;
}

struct Node* getHead(LinkedList** linkedList){
	return (*linkedList)->node;
}

struct Node* getTail(LinkedList** linkedList){
	struct Node* tempNode = (*linkedList)->node;

	for(int i = 0; i < getSize(*linkedList) - 2; i++){
		tempNode = tempNode->next;
	}

	return tempNode;
}

int getSize(LinkedList* linkedList){
	return linkedList->size;
}

// void reverse(){

// }

// void shuffle(){
	
// } // based on RNG

int clear(LinkedList** linkedList){
	struct Node* tempNodeOne = (*linkedList)->node;
	struct Node* tempNodeTwo;

	for(int i = 0; i < getSize(*linkedList); i++){
		tempNodeTwo = tempNodeOne->next;
		free(tempNodeOne);
		tempNodeOne = tempNodeTwo;
	}

	(*linkedList)->node = NULL;
}

void print(LinkedList** linkedList){

	struct Node* tempNode = (*linkedList)->node;

	while(tempNode != NULL){
		printf("%d -> ", *((int*)tempNode->data));
		tempNode = tempNode->next;
	}

	printf("NULL \n");
}