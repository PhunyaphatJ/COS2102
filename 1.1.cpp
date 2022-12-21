#include <iostream>
#include <String.h>
using namespace std;
class Point{
	private:
	float x,y;
	char name[20];
	public:
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
		char *getName(){
//			return name;
			return &name[2];	
		}
		void show(void);
};
void Point::show(){
	cout<<"name = "<<name<<endl;
	cout<<"x = "<<x<<endl;
	cout<<"y = "<<y<<endl;
}
int main(){
	Point point1,point2;
	point1.set(1.2,1.3,"Point1");
	point2.set(3.3,2.2,"Point2");
	point1.show();
	point2.show();
	point1.setX(10);
	point1.setY(20);
	point1.setName("Point1-setName");
	point1.show();
	cout<<"get : "<<point2.getName()<<endl<<point2.getX()<<endl<<point2.getY()<<endl;
}
