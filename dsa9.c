#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


struct Node
{
	int data;
	struct Node* next;
};

void MoveNode(struct Node** destRef, struct Node** sourceRef);

struct Node* SortedMerge(struct Node* c, struct Node* d)
{
	struct Node dummy;
	struct Node* tail = &dummy;
	dummy.next = NULL;
	while (1)
	{
		if (c == NULL)
		{
			tail->next = d;
			break;
		}
		else if (d == NULL)
		{
			tail->next = c;
			break;
		}
		if (c->data <= d->data)
			MoveNode(&(tail->next), &c);
		else
			MoveNode(&(tail->next), &d);

		tail = tail->next;
	}
	return(dummy.next);
}

void MoveNode(struct Node** destRef, struct Node** sourceRef)
{
	struct Node* newNode = *sourceRef;
	assert(newNode != NULL);
	*sourceRef = newNode->next;
	newNode->next = *destRef;
	*destRef = newNode;
}

void append(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	struct Node *last = *head_ref;
	new_node->data = new_data;
	new_node->next = NULL;
	if (*head_ref == NULL)
	{
	*head_ref = new_node;
	return;
	}
	
	while (last->next != NULL)
		last = last->next;

	last->next = new_node;
	return;	
}
void printList(struct Node *node)
{
	while (node!=NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}

int main()
{
	int i,val,n,m;
	struct Node* res = NULL;
	struct Node* c = NULL;
	struct Node* d = NULL;
    
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&val);
        append(&c,val);
    }
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d",&val);
        append(&d,val);
    }
	res = SortedMerge(c, d);
	printList(res);

	return 0;
}
