#include <iostream>
#include <string.h>
using namespace std;
class Date{
	int day,month;
	int *year;
	public:
	Date(){
		day = 0;month = 0; year =new int(0);
	}
	Date(int d,int m,int y){
		day = d; month = m;
		year = new int(y);
	}
	Date(const Date& d){ //Date copy 
		day = d.day; month = d.month;
		year = new int(*d.year);
	}
	void set(int d,int m,int y){
		day = d;month = m; *year =y;
	}
	int getDay(){
			return day;
	}
	int getMonth(){
		return month;
	}
	int getYear(){
		return *year;
	}

	void show(){
		printf("Date: %d/%d/%d\n",day,month,*year); 
	}
	Date operator=(const Date &d){//Date assignment
		if(this==&d) return *this;
		day = d.day; month = d.month;
			*year = *d.year;
		return *this;
	}
	~Date(){delete year;}
	void print(ostream& os){ 
		os<<"ostream Date ";
		os<<day<<"/"<<month<<"/"<<*year<<endl;
	}
	void input(istream& is){
		cout<<"istream Date ";
		cout<<"day : ";is>>day;
		cout<<"month : ";is>>month;
		cout<<"year : ";is>>*year;
	}
};

ostream& operator<<(ostream& os,Date &d){ //Date ostream
	d.print(os);
	return os;
}
istream& operator>>(istream& is,Date &d){//Date istream
	d.input(is);
	return is;
}
class Address{
	char houseNo[20],subDistrict[20],district[20],province[20];
	int *postalCode;
	public:
	Address(){
		strcpy(houseNo,"xxxxx");
		strcpy(subDistrict,"xxxxx");
		strcpy(district,"xxxxx");
		strcpy(province,"xxxx");
		postalCode = new int(0);
	}	
	Address(char* h,char* sub,char *dis,char* prov,int post){
		strcpy(houseNo,h);
		strcpy(subDistrict,sub);
		strcpy(district,dis);
		strcpy(province,prov);
		postalCode = new int(post);
	}
	Address(const Address &a){//Address copy
		strcpy(district,a.district);
		strcpy(houseNo,a.houseNo);
		strcpy(subDistrict,a.subDistrict);
		strcpy(province,a.province);
		postalCode = new int(*a.postalCode);
	}
	void set(char* house,char *subDist,char *dist,char *prov,int post){
		strcpy(houseNo,house);
		strcpy(subDistrict,subDist);
		strcpy(district,dist);
		strcpy(province,prov);
		*postalCode = post;
		
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
		return *postalCode;
	}
	void show(){
		printf("House No. : %s \t SubDistrict : %s\n",houseNo,subDistrict);
		printf("District : %s \t Province : %s\n",district,province);
		cout<<"PostalCode : "<<*postalCode<<endl;
	}
	Address& operator=(const Address &a){//Address assignment
		if(this==&a) return*this;
		strcpy(district,a.district);
		strcpy(houseNo,a.houseNo);
		strcpy(subDistrict,a.subDistrict);
		strcpy(province,a.province);
			*postalCode = *a.postalCode;
		return *this;
	}
	~Address(){
		delete postalCode;
	}
	void print(ostream& os){
	os<<"ostream Addressn ";
	os<<"House No. : "<<houseNo<<" SubDistrict : "<<subDistrict;
	os<<" District : "<<district<<" Province : "<<province;
	os<<" PostalCode : "<<getPostalCode()<<endl;
	}
	void input(istream& is){
		cout<<"istream Address ";
		cout<<"Enter housNo. :";is>>houseNo;
		cout<<"Enter subDistrict :";is>>subDistrict;
		cout<<"Enter District :";is>>district;
		cout<<"Enter Province :";is>>province;
		cout<<"Enter Postal Code:";is>>*postalCode;
//		postalCode = new int(post);
	}
};
ostream& operator<<(ostream& os,Address &a){//Address ostream
	a.print(os);
	return os;
}
istream& operator>>(istream& is,Address &a){//Address istream
	a.input(is);
	return is;
}

class Person{
	char *name;
	Date date;
	Address addr;
	public:
		Person(){
			name = new char[20];
			strcpy(name,"xxxx");
		}
		Person(char *n,int day,int month,int year,char *house,char *subDist,char *dist,char *prov,int post){
				name = new char[strlen(n)+1];
				strcpy(name,n);
				date.set(day,month,year);
				addr.set(house,subDist,dist,prov,post);
		}
		Person(char *n,Date &d,Address &a){
			date = d;
			addr = a;
			name = new char[strlen(n)+1];
			strcpy(name,n);
		}
		Person(char *n){
		name = new char[strlen(n)+1];
			strcpy(this->name,n);
		}
		Person(const Person&p){//Person copy
			date = p.date;
			addr = p.addr;
			name = new char[strlen(p.name)+1];
			strcpy(name,p.name);
		}
		void set(char *n,int day,int month,int year,char *house,char *subDist,char *dist,char *prov,int post){
			delete []name;
			name = new char[strlen(n)+1];
			strcpy(name,n);
			date.set(day,month,year);	
			addr.set(house,subDist,dist,prov,post);
		}
		char *getName(){
			return name;
		}
		Date getDate(){return date;
		}
		Address getAddr(){return addr;
		}
		~Person(){
			cout<<"bye Person "<<name<<endl;
			delete []name;
		}
		Person& operator=(const Person& p){//Person assignment
			if(this==&p)return *this;
			cout<<"Person operator =\n";
			date= p.date;
			addr=p.addr;
			delete []name;
				name = new char[strlen(p.name)+1];
				strcpy(name,p.name);
		 	return *this;
		}
		 void input(){
		 	cin>>date;
		 	cin>>addr;
		 	char n[20];
		 	cout<<"Name : ";cin>>n;
		 	name = new char[strlen(n)+1];
		 	strcpy(name,n);
		 }
		void show(void);
};
void Person::show(){
	cout<<"Name : "<<name<<endl;
	cout<<date;
	cout<<addr;
}
ostream& operator<<(ostream& os,Person &p){//Person ostream
	os<<"ostream Person"<<endl;
	p.show();
	cout<<endl;
	return os;
}
istream& operator>>(istream& is,Person &p){//Person istream
	cout<<"istream Person"<<endl;
	p.input();
	return is;
}
class Student:virtual public Person{
	char sID[20];
	char *faculty;
	public:
		Student(){
			strcpy(sID,"xx");
			faculty =new char[20];
			strcpy(faculty,"xxxx");			
		}
		Student(char *id,char *f,char *name,Date &d,Address &a):Person(name,d,a){
			strcpy(sID,id);
			faculty = new char[strlen(f)+1];
			strcpy(faculty,f);
		}
		Student(char *id){
			strcpy(sID,id);
			faculty =new char[20];
			strcpy(faculty,"xxxx");	
		}
		Student(char *id,char *f){
			faculty = new char[strlen(f)+1];
			strcpy(faculty,f);
			strcpy(sID,id);
		}
		Student(const Student &p):Person(p){//Student copy
			strcpy(sID,p.sID);
			faculty = new char[strlen(p.faculty)+1];
			strcpy(faculty,p.faculty);
		}
		void set(char *id,char *f){
			delete []faculty;
			strcpy(sID,id);
			faculty = new char[strlen(f)+1];
			strcpy(faculty,f);
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
		Student& operator=(const Student& s){//Student assignment
			if(this==&s)return *this;
			Person::operator=(s);
			strcpy(sID,s.sID);
			delete []faculty;
				faculty = new char[strlen(s.faculty)+1];
				strcpy(faculty,s.faculty);
		 	return *this;
		}
		void input(){
			cout<<"Person cin : ";
			Person::input();
			cout<<"Student cin : ";
			char i[20],f[20];
			cout<<"ID : ";cin>>i; 
			cout<<"faculty : ";cin>>f;
			strcpy(sID,i);
			faculty = new char[strlen(f)+1];
			strcpy(faculty,f);
		}
		void print(){
			Person::show();
			cout<<"Student : ";
			show();
			cout<<endl;
		}
};
void Student::show(){
	cout<<"ID : "<<sID;
	cout<<" Faculty : "<<faculty<<endl;
}
ostream& operator<<(ostream& os,Student &s){//Student ostream
	os<<"ostream Student"<<endl;
	s.print();
	return os;
}
istream& operator>>(istream& is,Student &s){//Student istream
	cout<<"istream Student "<<endl;
	s.input();
	return is;
}
class Teacher:virtual public Person{
	char *tID;
	char faculty[20];
	public:
		Teacher(){
			tID = new char[20];
			strcpy(tID,"xxxxx");
			strcpy(faculty,"xx");
		}
		Teacher(char *id,char *faculty,char *name,int day,int month,int year,char* h,char *sub,char *dist,char* prov,int post):Person(name,day,month,year,h,sub,dist,prov,post){
			tID = new char[strlen(id)+1];
			strcpy(tID,id);
			strcpy(this->faculty,faculty);
		}
	
		Teacher(char *id){
			tID = new char[strlen(id)+1];
			strcpy(tID,id);
			strcpy(this->faculty,"xxxxx");
			
		}
		Teacher(char *id,char *faculty){
			tID = new char[strlen(id)+1];
			strcpy(tID,id);
			strcpy(this->faculty,faculty);
		}
		Teacher(char *id,char *faculty,char *name,Date d,Address a):Person(name,d,a){
			tID = new char[strlen(id)+1];
			strcpy(tID,id);
			strcpy(this->faculty,faculty);
		}
//		Teacher(Teacher &t){
//			*this = t;
//		}
		Teacher(const Teacher &t):Person(t){//Teacher copy
			tID = new char[strlen(t.tID)+1];
			strcpy(tID,t.tID);
			strcpy(faculty,t.faculty);
		}
		void set(char *id,char *faculty){
			delete[]tID;
			tID = new char[strlen(id)+1];
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
			delete []tID;
		}
		Teacher& operator=(const Teacher &t){//Teacher assignment
			if(this==&t)return *this;
			Person::operator=(t);
			delete [] tID;
			strcpy(faculty,t.faculty);
				tID= new char[strlen(t.tID)+1];
				strcpy(tID,t.tID);
			return *this;
		}
		void input(){
			cout<<"Person cin : ";
			Person::input();
			cout<<"Teacher cin : ";
			char id[20],f[20];
			cout<<"ID : ";cin>>id;
			cout<<"Faculty : ";cin>>f;
			tID = new char[strlen(id)+1];
			strcpy(tID,id);
			strcpy(faculty,f);
		}
		void print(){
			Person::show();
			cout<<"Teacher : ";
			show();
			cout<<endl;
		}
};
void Teacher::show(){
	cout<<"ID : "<<tID;
	cout<<" Faculty : "<<faculty<<endl;
}
ostream& operator<<(ostream& os,Teacher &t){//Teacher ostream
	os<<"ostream Teacher"<<endl;
	t.print();
	return os;
}
istream& operator>>(istream& is,Teacher &t){//Teacher istream
	cout<<"istream Teacher"<<endl;
	t.input();
	return is;
}
class TeachingAssistant:public Student,public Teacher{
	char subject[20];
	char subjID[20];
	char *tName;
	public:
		TeachingAssistant(){
			strcpy(subject,"xxxx");
			strcpy(subjID,"xxxxx");
			tName = new char[20];
			strcpy(tName,"xxxx");
		}
		TeachingAssistant(Person &p,Student &s,Teacher &t,char *subj,char *subjID):Person(p),Student(s),Teacher(t){
			strcpy(subject,subj);
			strcpy(this->subjID,subjID);
			tName = new char[strlen(t.getName())+1];
			strcpy(tName,t.getName());
		}
		TeachingAssistant(Date d,Address a,char *name,char *sID,char *sFac,char *tname,char *tID,char *tFac,char *subj,char *subjID):Person(name,d,a),Student(sID,sFac,name,d,a),Teacher(tID,tFac){
			strcpy(subject,subj);
			strcpy(this->subjID,subjID);
			tName = new char[strlen(tname)+1];
			strcpy(this->tName,tname);
		}
		TeachingAssistant(const TeachingAssistant &ta):Person(ta),Student(ta),Teacher(ta){//TeachingAssistant copy
			strcpy(subject,ta.subject);
			strcpy(subjID,ta.subjID);
			tName = new char[strlen(ta.tName)+1];
			strcpy(tName,ta.tName);
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
		TeachingAssistant& operator=(TeachingAssistant &ta){//TeachingAssistant assignment
			if(this==&ta)return *this;
			delete [] tName;
			Teacher::operator=(ta);
			Student::set(ta.Student::getID(),ta.Student::getFacul());
			strcpy(subject,ta.subject);
			strcpy(subjID,ta.subjID);
			tName = new char[strlen(ta.tName)+1];
			strcpy(tName,ta.tName);
			return *this;
		}
		void show(){
		printf("Name : %s\n",tName);
		printf("Subject : %s\n",subject);
		printf("Subject ID : %s\n",subjID);
		};
		void print(){
			show();
			Person::show();
			cout<<"Student : ";
			Student::show();
			cout<<"Teacher : ";
			Teacher::show();
			cout<<endl;
		}
		~TeachingAssistant(){
			delete [] tName;
			cout<<"bye TeachingAssistant"<<endl;
		}
	void input(){
		Teacher::input();
		cout<<"Student cin : ";
		char id[20],facul[20];
		cout<<" ID : ";cin>>id;
		cout<<"Faculty : ";cin>>facul;
		Student::set(id,facul);
		char name[20];
		cout<<"Subject : ";cin>>subject;
		cout<<"Subject ID : ";cin>>subjID;
		cout<<"Teacher Name : ";cin>>name;
		tName = new char[strlen(name)+1];
		strcpy(tName,name);
		cout<<endl;
	}
};
ostream& operator<<(ostream& os,TeachingAssistant &ta){//TeachingAssistant ostream
	cout<<"ostream TeachingAssistant"<<endl;
	ta.print();
	return os;
}
istream& operator>>(istream& is,TeachingAssistant &ta){//TeachingAssistant istream
	cout<<"istream TeachingAssistant"<<endl;
	ta.input();
	return is;
}
int main(){
    cout<<"Address\n-------\n";
	Address a1("99/9","aaa","abab","abc",11111),a2;
	cout<<"a1 : ";
	cout<<a1;
	a2=a1;
	cout<<"a2 : ";
	cout<<a2;
	Address a3 = a2;
	cout<<"a3 : ";
	cout<<a3;
	cout<<"a1 cin : ";
//	cin>>a1;//
	cout<<"a1 after cin : ";
	cout<<a1;
	cout<<"\nDate\n-------\n";
	Date d1(01,01,2023),d2;
	cout<<"d1 : ";
	cout<<d1;
	d2 = d1;
	cout<<"d2 : ";
	cout<<d2;
	Date d3 = d1;
	cout<<"d3 : ";
	cout<<d3;
	cout<<"d1 cin : ";
//	cin>>d1;//
	cout<<"d1 after cin : ";
	cout<<d1;
	cout<<"\nPerson\n-------\n";
	Person p1("Phunyaphat",d1,a3),p2;
	cout<<"p1 : ";
	cout<<p1;
	p2 = p1;
	cout<<"p2 : ";
	cout<<p2;
	Person p3 =p2 ;
	cout<<"p3 : ";
	cout<<p3;
	cout<<"p1 cin : ";
//	cin>>p1;//
	cout<<"p1 after cin : ";
	cout<<p1;
	Student s1("123","humen","jaja",d2,a3),s2;
	cout<<"\nStudent\n-------\n";
	cout<<"s1 : ";
	cout<<s1;
	s2 = s1;
	cout<<"s2 : ";
	cout<<s2;
	Student s3 = s2;
	cout<<"s3 : ";
	cout<<s3;
	cout<<"s1 cin : ";
// 	cin>>s1;//
	cout<<"s1 after cin : ";
	cout<<s1;
	cout<<"\nTeacher\n-------\n";
	Teacher t1("111","sci","somchai",d2,a3),t2;
	cout<<"t1 : ";
	cout<<t1;
	t2 = t1;
	cout<<"t2 : ";
	cout<<t2;	
	Teacher t3 = t2;
	cout<<"t3 : ";
	cout<<t3;
	cout<<"t1 cin : ";
// 	cin>>t1;
	cout<<"t1 after cin : ";
	cout<<t1;
	cout<<"TeachingAssistant\n-------\n";
	TeachingAssistant ta1(p1,s1,t1,"oop","cos2102"),ta2;
	cout<<"ta1 : ";
	cout<<ta1;
	ta2 = ta1;
	cout<<"ta2 : ";
	cout<<ta2;
	TeachingAssistant ta3 = ta2;
	cout<<"ta3 : ";
	cout<<ta3;
	cout<<"ta1 cin : ";
// 	cin>>ta1;//
	cout<<"ta1 after cin : ";
	cout<<ta1;
	cout<<"----------------------\n";	
}
