#include <iostream>
#include <string.h>
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
		float dot(Point&);
		Point midpoint(Point&,Point&);
};
int Point::num;
void Point::show(){
	cout<<"--------------------------"<<endl;
	cout<<"name = "<<name<<endl;
	cout<<"x = "<<x<<endl;
	cout<<"y = "<<y<<endl;
    cout<<"--------------------------"<<endl;
}

float Point::dot(Point &x2){
	return x*x2.x + y * x2.y;
}
Point Point::midpoint(Point &a,Point &b){
	x = (a.x+b.x)/2;
	y = (a.y +b.y)/2;
//	Point d(x,y);
//	return d; 
//    return Point(x,y);
	return *this;
}
int main(){
	Point a(4,7),b(8,12),c,d;
	cout<<a.dot(b)<<endl;;
	d =c.midpoint(a,b);
	c.show();
	d.show();

}
