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
class Student:public Person{
	char sID[20];
	char faculty[20];
	public:
		Student(){
			set("xxxxxx","xxxxxx");
		}
		Student(char *id,char *faculty,char *name,int day,int month,int year,char* h,char *sub,char *dist,char* prov,int post):Person(name,day,month,year,h,sub,dist,prov,post){
			set(id,faculty);
		}
		Student(char *id){
			set(id,"xxxxxxx");
		}
		Student(char *id,char *faculty){
			set(id,faculty);
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
	Person::show();

}
class Teacher:public Person{
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
	Person::show();
}
int main(){
	Person p1("Pi",12,12,2012,"9/9","หัวหมาก","บางกะปิ","กรุงเทพ",10240);
	p1.show();
	Person p2;
	p2.show();
	Student s1;
	s1.show();
	cout<<"s2\n";
	Student s2("705000896","Business","chai",28,12,65,"99/9","บางนา","บางนา","กทม",10260);
	cout<<"\nID : "<<s2.getID()<<endl<<"Faculty : "<<s2.getFacul()<<endl;
	cout<<"Name : "<<s2.getName()<<endl;
	printf("Date : %d/%d/%d\n",s2.getDay(),s2.getMonth(),s2.getYear());
	printf("House No. : %s \t SubDistrict : %s \n",s2.getHouse(),s2.getSubDistrict());
	printf("District : %s \t Province : %s \n",s2.getDistrict(),s2.getProvince());
	printf("PostalCode : %d\n\n",s2.getPostalCode());
	Student s3("905000896","Human");
	s3.show();
	Student s4("105000896");
	s4.show();
	Teacher t1("805000896","Sci","somchai",30,02,66,"101/1","บางซื่อ","บางซื่อ","กทม",10800),t2;
	cout<<"\nID : "<<t1.getID()<<endl<<"Faculty : "<<t1.getFaculty()<<endl;
	cout<<"Name : "<<t1.getName()<<endl;
	printf("Date : %d/%d/%d\n",t1.getDay(),t1.getMonth(),t1.getYear());
	printf("House No. : %s \t SubDistrict : %s \n",t1.getHouse(),t1.getSubDistrict());
	printf("District : %s \t Province : %s \n",t1.getDistrict(),t1.getProvince());
	printf("PostalCode : %d\n\n",t1.getPostalCode());
	t2.show();
	Teacher t3("405000896","Engi");
	t3.show();
	Teacher t4("505000896");
	t4.show();
	Date d1(01,01,2001);
	Address a1("8/8","jaja","jaja","bbbb",13130);
	Person p3("som",d1,a1);
	p3.show();
	Date d2 = d1.getDate();
	Address a2 = a1.getAddr();
	d2.show();
	a2.show();
	
	
}
