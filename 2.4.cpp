#include <iostream>
#include <string.h>
using namespace std;
class Person{
	static int num;
	char id[20],name[20],date[20];
	public:
		Person(){
			++num;
			strcpy(id,"null");
		}
		Person(char *id,char *name,char *date){
			++num;
			set(id,name,date);
		}
		void set(char *id,char *name,char *date){
			strcpy(this->id,id);
			strcpy(this->name,name);
			strcpy(this->date,date);
		}
		char *getName(){
			return name;
		}
		char *getID(){
			return id;
		}
		char *getDate(){
			return date;
		}
		void show(void);
		~Person(){
			--num;
			cout<<"bye "<<name<<endl;
		}
};int Person::num;
void Person::show(){
	cout<<"ID : "<<id<<endl;
	cout<<"name : "<<name<<endl;
	cout<<"Date : "<<date<<endl;
}
int main(){
	Person a("1139600123796","Phunyaphat","01/05/44");
	a.show();
	char *getN = a.getName();
	char *getID = a.getID();
	char *getDate = a.getDate();
	cout<<endl;
	cout<<getN<<endl<<getID<<endl<<getDate<<endl;
	
	a.set("1234567890123","somchai","01/01/01");
	cout<<endl;
	a.show();
}
