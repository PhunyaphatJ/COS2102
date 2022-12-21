#include <iostream>
using namespace std;
class MyObj{
	int width,height;
	float price;
	public:
		MyObj(){
			cout<<"my Object\n";
		}
		MyObj(int w,int h,float p)
		{
			set(w,h,p);
//			cout<<"obj: "<<width<<" "<<height<<" "<<price<<" "<<endl;
		}
		~MyObj(){
			cout<<"bye\n";
		}
	void set(int w,int h,float p){
		width = w;
		height = h;
		price = p;
	}
	void show();
};
void MyObj::show(){
		cout<<"obj: "<<width<<" "<<height<<" "<<price<<" "<<endl;
}
struct node{
	node *next;
	MyObj x;
};
class Linked_list{
	node *head,*tail;
	public:
		Linked_list(){
		head = NULL;
		tail = NULL;
		MyObj*t = new MyObj;
		}
		void add_node(MyObj x){
			node *tmp = new node;
			tmp->x = x;
			tmp->next = NULL;
			
			if(head == NULL)
			{
				head = tmp;
				tail = tmp;
			}else
			{
				tail->next = tmp;
				tail = tail->next;
			}
		}
		void show(){
			node *tmp;
			tmp = head;
			while(tmp!=NULL){
				cout<<tmp->x<<endl;
				tmp = tmp->next;
			}
		}
};
int main(){
//	MyObj *t;
//	cout<<"hello\n";
	
//	MyObj *p = new MyObj;
//	p->set(4,10,980);
//	p->set(5,10,12000);
//	p->show();
//	MyObj *j = p;
////	delete p;
//	j->show();
//	p = new MyObj(5,20,550.50);
//	p->show();
}
