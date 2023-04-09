#include <bits/stdc++.h>
using namespace std;

typedef class Node* node;

class Node{
	private:
		int data;
		Node *next;
	public:
		node makeNode(int x); 	
		int Size(node a);
		void insertF(node &a, int x);
		void insertE(node &a, int x);
		void insertM(node &a, int x, int pos);
		void makeList(node &a);
		void inNode(node a);
		int dem(node a);
		void xoaSNT(node &a);
		void sapXep(node &a);
		int check(node a);
		void xoaTrung(node &a);
};

//cap phat dong 1 node moi voi du lieu la so nguyen x
node Node::makeNode(int x){
	node temp = new Node();
	temp->data = x;
	temp->next = NULL;
	return temp;
}


//dem phan tu
int Node::Size(node a){
	int cout = 0;
	while(a != NULL){
		++cout;
		a = a->next;
	}
	return cout;
}

//them phan tu vao dau dslk
void Node::insertF(node &a, int x){ 
	node temp = makeNode(x);
	if(a == NULL){
		a = temp;
	}else{
		temp->next = a;
		a = temp;
	}
}

//them phan tu vao cuoi dslk

void Node::insertE(node &a, int x){
	node temp = makeNode(x);
	if(a == NULL){
		a = temp;
	}else{
		node p = a;
		while(p->next != 0){
			p = p->next; 
		}
		p->next = temp;
	}
}

//them phan tu vao vi tri pos
void Node::insertM(node &a, int x, int pos){
	int n = Size(a);
	if(pos<=0 || pos > n+1){
		cout << "Vi tri chen khong hop le!\n";
	}
	if(pos == 1){
		insertF(a,x); return;
	}
	else if(pos == n+1){   
		insertE(a,x); return;
	}
	node p=a;
	for(int i=1; i < pos-1; i++){
		p = p->next;
	}
	node temp = makeNode(x);
	temp->next = p->next; 
	p->next = temp;
}
//Tao 1 danh sach lien ket
void Node::makeList(node &a){
	int x;
	int n; cout << "Nhap so luong phan tu: "; cin>>n; cout<<endl;
	for(int i=0; i<n; i++){
		cout << "Nhap gia tri can them: "; cin>>x;
		a->insertE(a,x);
	}
}

//In danh sach
void Node::inNode(node a){
	for(node p=a; p!=NULL; p = p->next){
		cout << p->data <<" ";
	}
	cout << endl;
}

//Dem k
int Node::dem(node a){
	int k; 
	do{
		cout<<"Nhap vao so k: ";cin>>k;cout<<endl;
		if(k==0){
			cout<<"Moi nhap lai k!\n";
		}
	}while(k==0);
	int cout = 0;	 
	for(node p=a; p!=NULL; p = p->next){
		if(p->data == k) cout++;
	}
	return cout;
}

//sap xep tang dan
void Node::sapXep(node &a){
	for(node p=a; p->next!=NULL; p=p->next){
		node min = p;
		for(node q = p->next; q!=NULL; q = q->next){
			if(q->data < min->data){
				min = q;
			}
		}
		int temp = min->data;
		min->data = p->data;
		p->data = temp;
	}
}
//kiem tra xem co 3 so chan duong gan nhau ko
int Node::check(node a){
	int k = 0;
	node c,d;;
	for(node p=a; p!=NULL; p=p->next){
		k++;
		if(p->data>0 && p->data%2==0){
			c = p->next;
			if(c->data>0 && c->data%2==0){
				d = c->next;
				if(d->data>0 && d->data%2==0){
					cout << "Vi tri cua 3 so duong chan dung gan nhau la: " << k<< " " << k+1 << " " << k+2 <<endl;
					return 1;
				}
			}
		}
	}
	return 0;
}
//check SNT
int checkSNT(int x){
	if(x<2) return 0;
	for(int i=2; i<=sqrt(x); i++){
		if(x%i==0){
			return 0;
		}
	}
	return 1;
}
//xoa so nguyen to

void Node::xoaSNT(node &a){
	node truoc=NULL; node sau;
	node k; 
	for(k=a; k->next!=NULL; k = k->next){
		if(checkSNT(k->data)==1 && k==a){
			a=a->next;
		}else if(checkSNT(k->data)==1){
			sau = k->next;
			truoc->next = sau;
			k = truoc;
		}
		truoc=k;
	}
}

//xoa phan tu trung nhau trong danh sach
void Node::xoaTrung(node &a){
	node truoc,sau;
	for(node p=a; p->next!=NULL; p = p->next){
		for(node q=p->next; q!=NULL; q = q->next){
			if(p->data == q->data){
				sau=q->next;
				truoc->next=sau;
				q=truoc;
			}
			truoc=q;
		}
	}
}

int main(){
	node head = NULL;
	head->makeList(head);
	cout << "Danh sach lien ket don da nhap la: ";
	head->inNode(head);
	int choice; 
	do{
		cout << "---------------------MENU---------------------\n";
		cout << "1. Them 1 phan tu vao danh sach!\n";
		cout << "2. Dem xem co bao nhieu gia tri = k!\n";
		cout << "3. Kiem tra trong danh sach co 3 so chan duong dung canh nhau hay khong?\n";
		cout << "4. Sap xep danh sach theo thu tu tang dan!\n";
		cout << "5. Xoa tat ca cac so nguyen to trong danh sach!\n";
		cout << "6. Xoa tat ca cac phan tu co gia tri trung nhau trong danh sach, chi giu lai 1!\n";
		cout <<"-----------------------------------------------\n";
		cout << "Moi nhap lua chon cua ban: "; cin >> choice;
		switch (choice){
			case 1:{
				int x; cout << "Nhap gia tri can chen: "; cin >> x;
				int pos; cout << "Nhap vi tri can chen: "; cin >> pos;
				head->insertM(head, x, pos);
				cout << "Danh sach lien ket moi la: ";
				head->inNode(head);
				break;
			}
			case 2:{
				int x = head->dem(head);
				if(x==0){
					cout << "Khong tim thay gia tri can tim!"<<endl;
				}else{
					cout << "So lan xuat hien cua gia tri la: "<<x<<endl;
				}
				break;
			}
			case 3:{
				int x = head->check(head);
				if(x==0){
					cout << "Khong co 3 so duong chan dung gan nhau!\n";
				}
				break;
			}
			case 4:{
				head->sapXep(head);
				cout << "Danh sach lien ket moi la: ";
				head->inNode(head);
				break;
			}
			case 5:{
				head->xoaSNT(head);
				cout << "Danh sach lien ket moi la: ";
				head->inNode(head);
				break;
			}	
			case 6:{
				head->xoaTrung(head);
				cout << "Danh sach lien ket moi la: ";
				head->inNode(head);
				break;
			}
			case 0:	{
				cout << "Ban da thoat chuong trinh!";
				exit(0);
				break;
			}						
		}
	}while(1);
}

