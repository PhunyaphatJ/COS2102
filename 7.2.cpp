#include <iostream>
#include <string.h>
using namespace std;
class Date{
	int day,month,year;
	public:
	Date(){
		set(-1,-1,-1);
	}
	Date(int d,int m,int y){
		set(d,m,y);
	}
	void set(int d,int m,int y){
		day = d;
		month = m;
		year = y;
	}
	int getDay(){
			return day;
	}
	int getMonth(){
		return month;
	}
	int getYear(){
		return year;
	}
	Date getDate(){
		return *this;
	}
	void show(){
		printf("Date: %d/%d/%d\n",day,month,year);
	}
};
class Address{
	char houseNo[20],subDistrict[20],district[20],province[20];
	int postalCode;
	public:
	Address(){
		set("xx/xx","xxxx","xxxx","xxxx",-1);
	}	
	Address(char* h,char* sub,char *dis,char* prov,int post){
		set(h,sub,dis,prov,post);
	}
	void set(char* house,char *subDist,char *dist,char *prov,int post){
		strcpy(houseNo,house);
		strcpy(subDistrict,subDist);
		strcpy(district,dist);
		strcpy(province,prov);
		postalCode = post;
		
	}
	char *getHouse(){
		return houseNo;
	}
	char *getSubDistrict(){
		return subDistrict;
	}
	char *getDistrict(){
		return district;
	}
	char *getProvince(){
		return province;
	}
	int getPostalCode(){
		return postalCode;
	}
	Address getAddr(){
		return *this;
	}
	void show(){
		printf("House No. : %s \t SubDistrict : %s\n",houseNo,subDistrict);
		printf("District : %s \t Province : %s\n",district,province);
		printf("PostalCode : %d\n\n",postalCode);
	}
};
class Person{
	char name[20];
	Date date;
	Address addr;
	public:
		Person(){
			strcpy(name,"NULL");
		}
		Person(char *name,int day,int month,int year,char *house,char *subDist,char *dist,char *prov,int post){
			set(name,day,month,year,house,subDist,dist,prov,post);
		}
		Person(char *name,Date d,Address a){
			date = d;
			addr = a;
			strcpy(this->name,name);
		}
		Person(char *name){
			strcpy(this->name,name);
		}
		Person(Person *p){
			*this = p;
		}
		void set(char *name,int day,int month,int year,char *house,char *subDist,char *dist,char *prov,int post){
			strcpy(this->name,name);
			date.set(day,month,year);	
			addr.set(house,subDist,dist,prov,post);
		}
		char *getName(){
			return name;
		}
		int getDay(){
			return date.getDay();
		}
		int getMonth(){
			return date.getMonth();
		}
		int getYear(){
			return date.getYear();
		}
		char *getHouse(){
			return addr.getHouse();
		}
		char *getSubDistrict(){
			return addr.getSubDistrict();
		}
		char *getDistrict(){
			return addr.getDistrict();
		}
		char *getProvince(){
			return addr.getProvince();
		}
		int getPostalCode(){
			return addr.getPostalCode();
		}
		void show(void);
		~Person(){
			cout<<"bye Person "<<name<<endl;
		}
};
void Person::show(){
	cout<<"name : "<<name<<endl;
	date.show();
	addr.show();
}
class Student:virtual public Person{
	char sID[20];
	char faculty[20];
	public:
		Student(){
			set("xxxxxx","xxxxxx");
		}
		Student(char *id,char *faculty,char *name,Date d,Address a):Person(name,d,a){
			set(id,faculty);
		}
		Student(char *id){
			set(id,"xxxxxxx");
		}
		Student(char *id,char *faculty){
			set(id,faculty);
		}
		Student(Student *s){
			*this = s;
		}
		void set(char *id,char *faculty){
			strcpy(sID,id);
			strcpy((*this).faculty,faculty);
		}
		void show();
		char *getID(){
			return sID;
		}
		char *getFacul(){
			return faculty;
		}
		~Student(){
			cout<<"bye Student "<<sID<<endl;
		}
};
void Student::show(){
	cout<<"ID : "<<sID<<endl;
	cout<<"Faculty : "<<faculty<<endl;
}
class Teacher:virtual public Person{
	char tID[20];
	char faculty[20];
	public:
		Teacher(){
			set("xxxx","xxxx");
		}
//		Teacher(char *id,char *faculty,char *name,int day,int month,int year,char* h,char *sub,char *dist,char* prov,int post):Person(name,day,month,year,h,sub,dist,prov,post){
//			set(id,faculty);
//		}
		Teacher(char *id,char *faculty,char *name,int day,int month,int year,char* h,char *sub,char *dist,char* prov,int post){
			set(id,faculty);
			Person::set(name,day,month,year,h,sub,dist,prov,post);
		}
		Teacher(char *id){
			set(id,"xxxxxxx");
		}
		Teacher(char *id,char *faculty){
			set(id,faculty);
		}
		Teacher(char *id,char *faculty,char *name):Person(name){
		set(id,faculty);
		}
		Teacher(Teacher *t){
			*this = t;
		}
		void set(char *id,char *faculty){
			strcpy(tID,id);
			strcpy(this->faculty,faculty);
		}
		void show();
		char *getID(){
			return tID;
		}
		char *getFaculty(){
			return faculty;
		}
		~Teacher(){
			cout<<"bye Teacher "<<tID<<endl;
		}
};
void Teacher::show(){
	cout<<"ID : "<<tID<<endl;
	cout<<"Faculty : "<<faculty<<endl;
}

class TeachingAssistant:public Student,public Teacher{
	char subject[20];
	char subjID[20];
	char tName[20];
	public:
		TeachingAssistant(){
			strcpy(subject,"xxxx");
			strcpy(subjID,"xxxxx");
			strcpy(tName,"xxxxx");
		}
		TeachingAssistant(Person *p,Student *s,Teacher *t,char *subj,char *subjID):Person(*p),Student(*s),Teacher(*t){
			strcpy(subject,subj);
			strcpy(this->subjID,subjID);
			strcpy(tName,t->Teacher::Person::getName());
		}
		TeachingAssistant(Date d,Address a,char *name,char *sID,char *sFac,char *tname,char *tID,char *tFac,char *subj,char *subjID):/*Person(name,*d,*a),*/Student(sID,sFac,name,d,a),Teacher(tID,tFac){
			strcpy(subject,subj);
			strcpy(this->subjID,subjID);
			strcpy(this->tName,tname);
		}
		char *getSubject(){
			return subject;
		}
		char *getTName(){
			return tName;
		}
		char *getSubjectID(){
			return subjID;
		}
		void show();
		~TeachingAssistant(){
			cout<<"bye TeachingAssistant"<<endl;
		}
};
void TeachingAssistant::show(){
	printf("Name : %s\n",tName);
	printf("Subject : %s\n",subject);
	printf("Subject ID : %s\n",subjID);
	cout<<"---------------"<<endl;
}
int main(){
	
	Date d1(01,01,2023);
	Address a1("ssss","ssss","ssss","ssss",1002);
	Person p1("somchai",d1,a1);
	Student s1("6704300987","Sci");
	Teacher t1("1000000000","SCI","somsuk");
	TeachingAssistant ta1(&p1,&s1,&t1,"OOP","Cos2102");
	cout<<"TeachingAssistant :"<<endl;
	ta1.Student::show();
	cout<<"Name : "<<ta1.Person::getName()<<endl;
	cout<<"Teacher : "<<endl;
	ta1.Teacher::show();
	ta1.show();
	
	TeachingAssistant ta2;
	cout<<"TeachingAssistant :"<<endl;
	ta2.Student::show();
	cout<<"Name : "<<ta2.Person::getName()<<endl;
	cout<<"Teacher : "<<endl;
	ta2.Teacher::show();
	ta2.show();
	
	Date d2(02,02,2024);
	Address a2("ssss","ssss","ssss","ssss",1022);
	Person p2("sakdaa",d2,a2);
	Student s2("8521522566","English");
	Teacher t2("2000000000","Eng","chaiya");
	TeachingAssistant ta3(&p2,&s2,&t2,"English commu","Eng1300");
	cout<<"TeachingAssistant :"<<endl;
	ta3.Student::show();
	cout<<"Name : "<<ta3.Person::getName()<<endl;
	cout<<"Teacher : "<<endl;
	cout<<"Name : "<<ta3.getTName()<<endl;
	cout<<"Subject : "<<ta3.getSubject()<<endl;
	cout<<"SubjectID : "<<ta3.getSubjectID()<<endl;
	cout<<"--------------------------"<<endl;
	
	
	TeachingAssistant ta4(d2,a2,"Phunya","6305000496","Sci","somya","123456789","Sci","Cos2103","Data");
	cout<<"TeachingAssistant :"<<endl;
	ta4.Student::show();
	cout<<"Name : "<<ta4.Person::getName()<<endl;
	cout<<"Teacher : "<<endl;
	ta4.Teacher::show();
	ta4.show();
	ta4.Person::show();
	
}
