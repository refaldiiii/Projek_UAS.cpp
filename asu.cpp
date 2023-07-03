#include<iostream>
#include<conio.h>
using namespace std;

short stack[5], top = 0, maxstack = 5;

struct node{
	int data;
	node *next;
	node *prev;
};
node *head = NULL;

bool isEmpty(){
	if(head == NULL){
		return true;
	}
	else{
		return false;
	}
}

void push(){
	int data;
	cout<<"Masukkan data : ";
	cin>>data;
	stack[top] = data;
	top++;
	
	struct node *bantu;
	bantu = new node;
	if(isEmpty()){
		bantu->data = data;
		bantu->prev = NULL;
		bantu->next = NULL;
		head = bantu;
	}
	else{
		bantu->data = data;
		bantu->next = head;
		head->prev = bantu;
		bantu->prev = NULL;
		head = bantu;
	}
}

void pop(){
	if(top>0){
		top--;
	}
	
	struct node *bantu;
	bantu = new node;
	if(isEmpty()){
		cout<<"Stack kosong"<<endl;
	}
	else if(head->next == NULL && head->prev == NULL){
		bantu = head;
		head = NULL;
		delete head;
	}
	else{
		bantu = head;
		head = head->next;
		head->prev = NULL;
		delete bantu;
	}
}

void full(){
	if(top >= maxstack){
		cout<<"Stack penuh"<<endl;
	}
	else{
		cout<<"Stack belum penuh"<<endl;
	}
}

void empty()
{
	if(isEmpty()){
	cout<<"Stack kosong"<<endl;	
	} 
	else{
		cout<<"Stack tidak kosong"<<endl;
	} 
}

void clear(){
	head = NULL;
}

void print(){
	node *bantu = head;
	cout<<"Isi stack : ";
	while (bantu != NULL){
		cout<<bantu->data<<" ";
		bantu = bantu->next;
	}
	cout<<endl;
}

int main(){
	char tambah;
	
	do{
		int pilih;
		cout<<"======================================================"<<endl;
       	cout<<"    PROGRAM STACK PADA DOUBLE LINKED CIRCULAR LIST    "<<endl;
	    cout<<"======================================================"<<endl;
     	cout<<"1. PUSH                                               "<<endl;
      	cout<<"2. POP                                                "<<endl;
    	cout<<"3. FULL                                               "<<endl;
	    cout<<"4. EMPTY                                              "<<endl;
    	cout<<"5. CLEAR                                              "<<endl;
    	cout<<"6. PRINT                                              "<<endl;
    	cout<<"======================================================"<<endl;
		cout<<"Masukkan nomor pilihan anda : ";
		cin>>pilih;
		
		switch(pilih)
		{
			case 1 : 
				push();
			break;
			
			case 2 : 
				pop();
			break;
			
			case 3 : 
				full();
			break;
			
			case 4 : 
				empty();
			break;
			
			case 5 : 
				clear();
			break;
			
			case 6 : 
				
			break;
		}
		
		print();
		cout<<endl;
		cout<<"Apakah anda ingin memilih lagi (Y/T)? : ";
		cin>>tambah;
		cout<<endl<<endl;

system("cls");
		
	} while(tambah == 'y');
	cout<<endl;
	
	
	system("pause");
	return 0;
}
