#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *next;
};

typedef struct node node;

node *makeNode(int x){
	node *newNode = new node();
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void addHead(node **head,int x){
	node *newNode = makeNode(x);
	newNode->next = *head;
	*head = newNode;
}

void printfList(node *head){
	if(head == NULL){
		cout << "List is empty";
		return;
	}
	while (head != NULL){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void pushBack(node **head,int x){
	node *newNode = makeNode(x);
	
	node *temp = *head;
	if (*head == NULL){
		*head = newNode;
		return;
	}
	
	while (temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
}

//void rotate(node **head,int k){
//	int n = count(*head);
//	int loop = k % n;
//	k = n - loop;
//	//khai báo current là dia chi cua node head
//	node *temp = *head;
//	int n = 1;
//	while (n < k && temp != NULL){
//		n++;
//		temp = temp->next;
//	}
//	//Temp is index kthNode
//	node *kthNode = temp;
//	
//	while (temp != NULL){
//		temp = temp->next;
//	}
//	temp->next = *head;
//	kthNode->next = NULL;
//	*head = kthNode->next;
//	
//}

int count(node *head){
	int count = 0;
	while (head != NULL){
		count++;
		head = head->next;
	}
	return count;
}

void popFront(node **head){
	if (*head == NULL){
		return;
	}
	node *temp = *head;
	*head = (*head)->next;
	delete temp;
}

void popBack(node **head){
	if (*head == NULL) return;
	node *temp = *head;
	
	if (temp->next == NULL){
		*head = NULL;
		delete temp;
		return;
	}
	
	while (temp->next->next != NULL){
		temp = temp->next;
	}
	
	node *last = temp->next;
	temp->next = NULL;
	delete last;
	
}

void printfAddress(node *head){
	while(head != NULL){
		cout << head->next << " ";
		head = head->next;
	}
	cout << endl;
}

void insertKthNode(node **head,int x,int k){
	if (k < 0){
		cout << "Index is not valid";
	}
	if (k == 1){
		addHead(head,x);
	}
	
	node *temp = *head;
	for (int i = 0; i<k-1;i++){
		temp = temp->next;
	}
	node *newNode = makeNode(x);
	newNode->next = temp->next;
	temp->next = newNode;
}

void deleteNode(node **head,int k){
	if (k < 0) cout << "Index is not valid";
	if (k == 1){
		popFront(head);
	}
	node *temp = *head;
	for (int i = 0;i<k-1;i++){
		temp = temp->next;
	}
	node *kthNode = temp->next;
	temp->next = kthNode->next;
	delete kthNode;
}

void insertNode(node **head,int x,node *q){
	if (*head == NULL){
		addHead(head,x);
	}
	node *newNode = makeNode(x);
	node *temp = *head;
	while (temp->next != q){
		temp = temp->next;
	}
	newNode->next = temp->next;
	temp->next = newNode;
}

void deleteAll(node *head){
	node *temp = head;
	node *next = NULL;
	
	while (temp != NULL ){
		next = temp->next;
		delete temp;
		temp = next;
	}
	if (head == NULL){
		printfList(head);
		cout << "List is empty" << endl;
	}
}

void deleteNodeX(node **head,int x){
	if (*head == NULL){
		return;
	}
	node *temp = *head;
	node *pre = NULL;
	if (temp == NULL || temp->data != x){
		cout << "Node invalid";
	}
	while (temp->data != x){
		pre = temp;
		temp = temp->next;
	}
	pre->next = temp->next;
	delete temp;
}

void removeAfterNode(node **head,node *delNode){
	if (head == NULL || delNode == NULL){
		return;
	}
	node *temp = *head;
	while (temp->next != delNode){
		temp = temp->next;
	}
	temp->next = delNode->next;
	delete delNode;
}

void selectionSort(node **head){

	for (node *i = *head;i!= NULL; i = i->next){
		node *minNode = i;
		for (node *j = i->next;j!= NULL; j = j->next){
			if (j->data < minNode->data){
				minNode = j;
			}
		}
		swap(minNode->data,i->data);
	}
}
node *getTail(node *head){
 	node *temp = head;
 	while (temp != NULL && temp->next != NULL){
 		temp = temp->next;
	 }
	return temp;
}

node *partitionLast(node *head, node *end){
	node *preNode = head;
	node *cur = head->next;
	node *pivot = head;
	while (cur != end->next){
		if (pivot->data > cur->data){
			swap(preNode->next->data,cur->data);
			preNode = preNode->next;
		}
		cur = cur->next;
	}
	swap(preNode->data,pivot->data);
	return preNode;
}

void solve(node *head, node *end){
	if (head == NULL || end == NULL || head == end)
		return;
	node *pivot = partitionLast(head,end);
	solve(head,pivot);
	solve(pivot->next,end);
}



void quickSort(node **head){
	node *temp = *head;
	if ( temp == NULL || temp->next == NULL ) return;
	
	node *tail = getTail(temp);
	solve(temp,tail);
	return;
}

node *merge(node *a,node *b){
	node *result = NULL;
	
	if (a == NULL){
		return b;
	}
	
	if (b == NULL){
		return a;
	}
	
	
		if (a->data < b->data){
			result = a;
			result->next = merge(a->next,b);
		}else{
			result = b;
			result->next = merge(a,b->next);
		}
	
	return result;
}

node *findNodeMiddle(node *head){
	node *slow = head;
	node *fast = head->next;
	
	while (fast != NULL && fast->next != NULL){
		
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

node *mergeSort(node *head){
	if (head == NULL or head->next == NULL){
		return head;
	}
	node *middle = findNodeMiddle(head);
	
	node *a = head;
	node *b = middle->next;
	middle->next = NULL;
	
	a = mergeSort(a);
	b = mergeSort(b);
	
	return merge(a,b);
}


int main(){
	node *head = NULL;
	addHead(&head,3);
	addHead(&head,1);
	addHead(&head,2);
	addHead(&head,5);
	node *tail = getTail(head);
	int choice = 0;
	do{
		cout << "1. Add element after node q" << endl;
		cout << "2. Delete first element" << endl;
		cout << "3. Delete node have data with x " << endl;
		cout << "4. Delete node after node q" << endl;
		cout << "5. Delete all" << endl;
		cout << "6. Selection sort" << endl;
		cout << "7. Printf list" << endl;
		cout << "8. Quick sort" << endl;
		cout << "9. Merge Sort" << endl;
		cout << "Enter option: ";
		cin >> choice;
		
		if (choice == 1){
			insertNode(&head,3,head->next);
		}else if (choice == 2){
			popFront(&head);
		}else if (choice == 3){
			deleteNodeX(&head,1);
		}else if (choice == 4){
			removeAfterNode(&head,head->next);
		}else if (choice == 5){
			deleteAll(head);
		}else if (choice == 6){
			selectionSort(&head);
		}else if (choice == 7){
			printfList(head);
		}else if (choice == 8){
			quickSort(&head);
		}else if (choice == 9){
			head = mergeSort(head);
		}
	}while (choice != 0);
		
}
