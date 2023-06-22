#include <iostream>
#include <math.h>
using namespace std;
const double pi = 3.14;
class Shape{
	
	public:
	virtual void input()=0;
	virtual void show()=0;
	virtual int area() = 0;
	virtual int volume() = 0;
};

class TwoDimensional:public Shape{
		virtual int area() = 0;
};
class Rectangle:public TwoDimensional{
	int width,height;
	public:
		Rectangle(int w,int h){width = w;height = h;}
		int area(){
			return width*height;
		}
		void input(){
			cout<<"width : ";cin>>width;
			cout<<"height : ";cin>>height;
		}
		void show(){
			cout<<" Rectangle\n";
			printf("area = %d x %d = %d",width,height,area());
		}
		int volume(){}
};
class Triangle:public TwoDimensional{
	int base,height;
	public:
	Triangle(int b,int h){
		base = b;height = h;
	}
	int area(){
		return base*height/2;
	}
	void input(){
			cout<<"base : ";cin>>base;
			cout<<"height : ";cin>>height;
		}
		void show(){
			cout<<" Triangle\n";
			printf("area = %d x %d / 2 = %d",base,height,area());
		}
		int volume(){}

};
class Circle:public TwoDimensional{
	int radius;
	public:
		Circle(int r){
			radius = r;
		}
		int area(){
			return pi*pow(radius,2);
		}
		void input(){
			cout<<"radius : ";cin>>radius;
		}
		void show(){
			cout<<" Circle\n";
			printf("area = pi x %d^2 = %d",radius,area());
		}
		int volume(){}

};
class ThreeDimensional:public Shape{
	public:
};
class Cylinder:public ThreeDimensional{
	int radius,height;
	public:
		Cylinder(int r,int h){
			radius = r;
			height = h;
		}
		int volume(){
			return pi*(pow(radius,2)*height);
		}
		void input(){
			cout<<"radius : ";cin>>radius;
			cout<<"height : ";cin>>height;
		}
		void show(){
			cout<<" Cylinder\n";
			printf("volume = pi x %d^2 * %d = %d\n",radius,height,volume());
			printf("area = 2 x pi x %d x (%d + %d) = %d",radius,radius,height,area());
		}
		int area(){
			return 2*pi*radius*(radius+height);
		}
		
};
class Sphere:public ThreeDimensional{
	int radius;
	public:
	Sphere(int r){
		radius = r;
	}
	int volume(){
		return 4*pi*pow(radius,3)/3;
	}
	void input(){
			cout<<"radius : ";cin>>radius;
		}
		void show(){
			cout<<" Sphere\n";
			printf("volume = 4 * pi x %d^3 / 3 = %d\n",radius,volume());
			printf("area  = 4 * pi x %d^2  = %d",radius,area());
		}
		int area(){
			return 4*pi*pow(radius,2);
		}
	
};
ostream& operator<<(ostream& os,Shape &s){//
	os<<"ostream";
	s.show();
	cout<<endl;
	return os;
}
istream& operator>>(istream& is,Shape &s){//
	cout<<"istream"<<endl;
	s.input();
	return is;
}
int main(){
	Rectangle r1(5,4);
	// cout<<r1;
	// cin>>r1;
	// cout<<r1;
	Triangle t1(3,4);
	// cout<<t1;
	// cin>>t1;//
	// cout<<t1;
	Circle c1(6);
	// cout<<c1;
	// cin>>c1;
	// cout<<c1;
	Cylinder cy1(7,10);
	// cout<<cy1;
	// cin>>cy1;
	// cout<<cy1;
	Sphere s1(6);
	// cout<<s1;
	// cin>>s1;
	// cout<<s1;
	Shape *s[5];
	s[0] = &r1;
	s[1] = &t1;
	s[2] = &c1;
	s[3] = &cy1;
	s[4] = &s1;
	for(int i = 0;i<5;i++){
		cout<<"area = "<<s[i]->area()<<endl;
		if(i==3||i==4)
			cout<<"volume = "<<s[i]->volume()<<endl;
	}
}
