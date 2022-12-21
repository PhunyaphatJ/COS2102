#include <iostream>
#include <cmath>
#include <string.h>
#include <math.h>
using namespace std;
class Circle;
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
		void midpoint(Point&,Point&);
		friend bool check(Circle,Point);
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
void Point::midpoint(Point &a,Point &b){
	x = (a.x+b.x)/2;
	y = (a.y +b.y)/2;
}

class Circle{
	int r;
	Point p;
	public:
		Circle(){
			r=0;
		}
		Circle(float x,float y,int r){
			p.set(x,y,"noname");
			this->r = r;
		}
		void show(void);
		float getX();
		float getY();
		int getR();
		Point getP();
//		friend bool check(Circle,Point);
		~Circle(){
			cout<<"b b b\n"<<endl;
		}
};
void Circle::show(){
	printf("mid point : %f , %f \n",p.getX(),p.getY());
	printf("radius : %d\n\n",r);
}

float Circle::getX(){
	return p.getX();
}
float Circle::getY(){
	return p.getY();
}
int Circle::getR(){
	return r;
}
Point Circle::getP(){
	return p;
}
bool check(Circle circle,Point point){
//	float distance = sqrt(pow((circle.p.x - point.x),2)+pow((circle.p.y - point.y),2));
	float distance = sqrt(pow(circle.getP().x - point.getX(),2)+pow((circle.getP().y - point.getY()),2));
	if(distance>circle.getR()){
		return false;
	}else 
		return true;
}
int main(){
	Circle a(5,-1,3);
	a.show();
	Point b(2,4);
	if(check(a,b)){
		cout<<"inside "<<endl;
	}else{
		cout<<"outside"<<endl;
	}
}
