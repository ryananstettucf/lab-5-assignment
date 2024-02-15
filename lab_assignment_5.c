#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int size = 0;
	node * current = head;
	while (current != NULL ) {
		size++;
		current = current -> next;
	}
	return size;

}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{ 
	int size = length(head);
	char* str = (char*) malloc(sizeof(char) * (size +1));
	if(!str) {
		printf("Memory allocation failed.\n");
		exit(1);
	}
	node* current = head;
	int i = 0;
	while (current != NULL ) {
		str[i] = current -> letter;
		current = current -> next;
		i++;
	}
	str[i] = '\0';
	return str;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node* newNode = (node *) malloc(sizeof(node));

	if(!newNode) {
		printf("Memory allocation failed.\n");
		exit(1);
	}
	newNode -> letter = c;
	newNode -> next =NULL;
	if (*pHead == NULL) {
		*pHead = newNode;
	}
	else {
		node* current = *pHead;
		while (current -> next != NULL) {
			current =current -> next;
		}
		current -> next = newNode;
	}
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node* current = *pHead;
	node* next;
	while (current != NULL) {
		next = current -> next;
		free (current);
		current = next;
	}
	*pHead = NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("./input.txt","r");
	if(inFile == NULL){
		printf("Failed to open file.\n");
		return 1;
	}

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}