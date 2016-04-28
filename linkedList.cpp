#include <stdio.h>
#include <stdlib.h>

#define ARRIVAL 0
#define DEPARTURE 1

struct node{
	int type;
	double clockTime;
	struct node* next;
};

typedef struct node Node; // new type name for struct node   
Node* createNode(int type, double clock);
Node* insertNode(Node* head, Node* newNodePtr);
Node* removeNode(Node* head, Node** nextRef);
void printLinkedList(Node* head);



int main(){
	
	Node* head = NULL;
	int instruction = 0;
	
	printf("開始進行Linked list的測試，請輸入指令代碼(1為插入事件  2為取出事件 3為結束程式):  ");
	
	scanf("%d", &instruction);
	
	while(instruction != 3){
		switch(instruction) {
			case 1:{
				
				printf("\n插入Node: 請輸入事件型別以及事件發生時間\n");
				int inputType;
				double inputTime;
				
				scanf("%d", &inputType);
				scanf("%lf", &inputTime);
				
				Node* newNodePtr = createNode(inputType, inputTime);
				head = insertNode(head, newNodePtr);

				break;
			}
				
			
			case 2:{
				printf("\n刪除Node: 刪除最近發生事件的Node\n");
				
				Node* nextNodePtr = NULL;
				head = removeNode(head, &nextNodePtr);

				
				break;
			}
				
			default:
				
				instruction = 3;
			break;
			
		}
		if(instruction != 3){
			printLinkedList(head);
			
			printf("繼續Linked list的測試，請輸入指令代碼(1為插入事件  2為取出事件 3為結束程式):  ");
			scanf("%d", &instruction);
		}
			
	}
	

	return 0;
}


Node* createNode(int type, double clock){
	
	Node* tmpNode = (Node*)malloc(sizeof(Node));

	tmpNode->type = type;
	tmpNode->clockTime = clock;
	tmpNode->next = NULL;
	
	return tmpNode;
}

Node* insertNode(Node* head, Node* newNodePtr){
	
	if(head == NULL){
		
		return newNodePtr;
		
	}else if(head->clockTime > newNodePtr->clockTime){
		
		newNodePtr->next = head;
		return newNodePtr;
		
	}else{
		
		Node* prev = NULL;
		Node* curr = head;
		
		while((curr != NULL) && (curr->clockTime <= newNodePtr->clockTime)){
			prev = curr;
			curr=curr->next;
		
		}
		
		prev->next = newNodePtr;
		newNodePtr->next = curr;
		
		return head;
	}
}

Node* removeNode(Node* head, Node** nextRef){
	
	*nextRef = head;
	
	if(head != NULL){
		head = head->next;
		(*nextRef)->next = NULL;
	}else{
		
	}
	
	printf("\n--------------------------------------------------\n");
	return head;
	
}

void printLinkedList(Node* head){
	
	if(head == NULL){
		
		printf("Linked list 為空\n");
		
	}else{
		printf("Linked list內容:\n");
		Node* curr = head;
		printf("%d , %.2f->", curr->type, curr->clockTime);
		curr = curr->next;
		while(curr != NULL){
			printf("%d , %.2f->", curr->type, curr->clockTime);
			curr = curr->next;
			
		}
		printf("\n--------------------------------------------------\n");
		
	}
	
}



