#include <iostream>
#include <String.h>
using namespace std;
class Point{
	private:
	static int num;
	float x,y;
	char name[20];
	public:
		Point(){
			num++;
			set(0,0,"noname");
//			cout<<num<<endl;
		}
		Point(float x){
			++num;
			set(x,0,"noname");
//			cout<<num<<endl;
		}
		Point(float x,float y){
			++num;
			set(x,y,"noname");
//			cout<<num<<endl;
		}
		Point(float x,float y,char *s){
			num++;
			set(x,y,s);
//			cout<<num<<endl;
		}
		Point(char *s){
			num++;
			set(0,0,s);
//			cout<<num<<endl;
		}
		void set(float x,float y,char *s){
			this->x = x;
			this->y = y;
			strcpy(name,s);
		}
		void setX(float x){
			this-> x= x;
		}
		void setY(float y){
			this->y = y;
		}
		void setName(char *s){
			strcpy(name,s);
		}
		float getX(){
			return x;	
		}
		float getY(){
			return y;	
		}
		char* getName(){
			return &name[2];	
		}
		~Point(){
			--num;
			cout<<"bye "<<name<<endl;
		}
		static int count(){
			return num;
		}
		void show(void);
};
int Point::num;
void Point::show(){
	cout<<"--------------------------"<<endl;
	cout<<"name = "<<name<<endl;
	cout<<"x = "<<x<<endl;
	cout<<"y = "<<y<<endl;
    cout<<"--------------------------"<<endl;
}
int main(){
	Point pointA;
	cout<<"static function "<<Point::count()<<endl;
	Point pointB(10),pointC(10,5),pointD(1,1,"monke"),pointX("dog");
		cout<<"static function "<<Point::count()<<endl;
	pointA.show();
	pointB.show();
	pointC.show();
	pointD.show();
	pointX.show();
	
	}
