#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED 4
#define YLL 3
#define GRN 2
#define BLK 1

struct data{
	char name[100];
	int color;
	struct data *next, *prev;
}*head, *tail, *curr;

data *newdata(char name[], int color){
	struct data *temp = (data*)malloc(sizeof(data));
	strcpy(temp->name, name);
	temp->color = color;
	
	return temp;
}

void push(char name[], int color){
	struct data *temp = newdata(name, color);
	
	if(!head){
		head = tail = temp;
		head->prev = NULL;
		tail->next = NULL;
	}
	
	else if(temp->color > head->color){
		temp->next = head;
		head->prev = temp;
		head = temp;
		head->prev = NULL;
	}
	
	else if(temp->color < tail->color){
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
		tail->next = NULL;
	}
	
	else{
		curr = head;
		while(curr->color > temp->color){
			curr = curr->next;
		}
		temp->prev = curr->prev;
		curr->prev->next = temp;
		temp->next = curr;
		curr->prev = temp;
	}
}

data *pop(){
	
	if(!head){
		return NULL;
	}
	
	else if(head==tail){
		data del = *head;
		free(head);
		head = tail = NULL;
		
		return &del;
	}
	else{
		head = head->next;
		free(head->prev);
		head->prev = NULL;
		data del = *head;
		
		return &del;
	}
}

void search(char name[]){
//	data* notfound;
//	strcpy(notfound->name, "not found");
//	notfound->color = -1;
//	puts("check");
	curr = head;
	
	if(!head){
		puts("no found");
		system("pause");
		return;
	}
	
	else{
		while(strcmpi(curr->name, name)!=0 && curr != NULL){
			curr=curr->next;
		}
		if(curr == NULL){
			printf("result: %s no found", name);
			system("pause");
			return;
		} 
		else{
			printf("result: %s --> %d", name, curr->color);
			system("pause");
			return;
		}
	}
}

void print(){
	curr = head;
	char code[10];
	while(curr){
		if(curr->color == 4) strcpy(code, "RED");
		else if(curr->color == 3) strcpy(code, "YLL");
		else if(curr->color == 2) strcpy(code, "GRN");
		else if(curr->color == 1) strcpy(code, "BLK");
		else strcpy(code, "NO DATA");
		printf("%s %s\n", curr->name, code);
		curr = curr->next;
	}
	system("pause");
}

int main(){
	int cases;
	
	while(cases!=5){
		system("cls");
		puts("1.view");
		puts("2.add");
		puts("3.search");
		puts("4.pop");
		puts("5.exit");
		
		scanf("%d", &cases); fflush(stdin);
		
		switch(cases){
			case 1:{
				if(!head);
				else {
					print();
				}
				break;
			}
			case 2:{
				char name[50];
				char code[50];
				int color;
				scanf("%s %s", &name, &code); fflush(stdin);
				
				if(strcmpi(code, "RED")==0) color = 4 ;
				else if(strcmpi(code, "YLL")==0) color = 3;
				else if(strcmpi(code, "GRN")==0) color = 2;
				else if(strcmpi(code, "BLK")==0) color = 1;
				push(name, color);
				break;
			}
			case 3:{
				char name[50];
				scanf("%s", &name); fflush(stdin);
				search(name);
				break;
			}
			case 4:{
				pop();
				print();
				break;
			}
		}
	}
	
	
	return 0;
}


