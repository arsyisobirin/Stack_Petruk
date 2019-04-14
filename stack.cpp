#include <iostream>
#define MAX_STACK_SIZE 10

using namespace std;

struct Element{
	int data, top;
	Element *next;
};

class myStack{
	
	private:
	Element tumpuk;
	Element *head = NULL;
	
	public:
	void awal(){
		tumpuk.top = -1;
	}
    
	bool isFull(){
        if(tumpuk.top == 9){
			return 1;
		}else{
			return 0;
		}
    }
   
    bool isEmpty(){
        if(tumpuk.top == -1){
			return 1;
		}else{
			return 0;
		}
    }
	
	void push_angka(int input){
		if(isFull()){
			cout << "Stack Penuh";
		}else{
			Element *tmp = new Element;
			tmp->data = input;
			tmp->next=NULL;
			if(isEmpty())
			{
				head=tmp;
				head->next=NULL;
			}else{
				tmp->next=head;
				head=tmp;
			}
			cout<<"Push berhasil \n";
			tumpuk.top++;
		}
	}
		
	void pop_angka(){
		if (isEmpty()){
			cout<<"\nStack Kosong\n";
		}else{
			Element *tmp = new Element;
			tmp = head;
			head = head->next;
			delete tmp;
			cout<<"\nPop Berhasil\n";
			tumpuk.top--;
		}	
	}
		
	void get_top(){
		if(isEmpty()){
			cout << "Stack Kosong";
		}else{
			cout << head->data;
		}
	}
	
	void print_stack(){
		if(isEmpty()){
			cout << "Stack Kosong" << endl;
		}else{
			cout << "Isi Tumpukan : ";
			Element *tmp = new Element;
			tmp = head;
			while(tmp!=NULL)
			{
				cout<<tmp->data<<"  ";
				tmp=tmp->next;
			}
		}
	}
};

int nama_menu();

int nama_menu(){
	int menu;
	cout << "========================================\n";
	cout << "\n=== Stack dengan konsep linked list ===\n\n";
	cout << "========================================\n";
	cout << "MENU : "<<endl<<endl;
	cout << "1. Push Angka"<<endl;
	cout << "2. Pop Angka"<<endl;
	cout << "3. Get Top"<<endl;
	cout << "4. Print Stack"<<endl;
	cout << "5. Exit"<<endl;
	cout << "Pilihan : ";
	cin >> menu;
	
	cin.ignore();
	//system("CLS");
	return menu;
}
int main(){
	myStack s;
	int menu, a;
	s.awal();
	do{
	menu = nama_menu();
		switch(menu){
			case 1:
					cout << "Masukan Angka = ";
					cin>>a;
					s.push_angka(a);
					cin.ignore();
					cin.get();
					break;
			case 2:
					if(s.isEmpty()){
						cout << "Stack Kosong" << endl;
					}else{
						cout << "Angka ";s.getTop(); cout << " akan dihapus";
						cin.get();
						s.pop_angka();
					}
					break;
			case 3:
					if(s.isEmpty()){
						cout << "Stack Kosong" << endl;
					}else{
						cout << "Elemen Paling Atas adalah ";s.get_top();
						cin.get();
					}
					break;
			case 4:
					s.print_stack();
					cin.get();
					break;
			case 5:
					exit(0);
			default:
					cout <<"\t\nPilihan tidak ada";
					cin.get();
					break;
		}
		system("cls");
	}while (menu != 5);
		cin.get();
		return 0;
}
