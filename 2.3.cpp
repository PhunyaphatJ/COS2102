#include <iostream>
#include <string.h>
using namespace std;
class Rectangle{
	static int num;
	float width,height;
//	string name;
	 char name[20];
	public:
		Rectangle(){
			++num;
			set(0,0,"noname");
		}
		Rectangle(float w){
			++num;
			set(w,0,"noname");
		}
		Rectangle(float w,float h){
			++num;
			set(w,h,"noname");	
		}
		Rectangle(float w,float h,char* s){
			++num;
			set(w,h,s);
		}
		void set(float w,float h,char *s){
			this->width= w;
			this->height = h;
//			this->name = s;
			strcpy(name,s);
		}
		void setName(char *s){
			 strcpy(name,s);
//			this->name = name;
		}
		void setWidth(float w){
			this->width = w;
		}
		void setHeight(float h){
			this->height = h;
		}
		char* getName(){
			return name;
		}
		float getWidth(){
			return width;
		}
		float getHeight(){
			return height;
		}
		float rectangleArea(){
			return width*height;
		}
		float findLenght(){
			return 2*(width+height);
		}
		static int count(){
			return num;
		}
		void show(void);
		
		~Rectangle(){
			cout<<endl;
			--num;
			cout<<"bye "<<name<<endl;
			cout<<num<<endl;
		}
};
void Rectangle::show(){
	cout<<"name = "<<name<<endl;
	cout<<"Width = "<<width<<endl;
	cout<<"Height = "<<height<<endl;
	cout<<"RectangleArea = "<<rectangleArea()<<endl;
    cout<<"RectangleLenght ="<<findLenght()<<endl;
}
int Rectangle::num;
int main(){
	cout<<Rectangle::count()<<endl;
	Rectangle myRec;
	cout<<Rectangle::count()<<endl;
	myRec.set(3,0,"A");
	myRec.setHeight(5);
	myRec.show();
	Rectangle aRec(5,2,"aRec");
	cout<<Rectangle::count()<<endl;
	aRec.show();
	Rectangle bRec(1),cRec(2,8);
	bRec.setName("bRec");
	bRec.setWidth(3.2);
	bRec.setHeight(4.4);
	cout<<"------------------------------------"<<endl;
	cout<<"name : "<<bRec.getName()<<endl;
	cout<<"width : "<<bRec.getWidth()<<endl;
	cout<<"height : "<<bRec.getHeight()<<endl;
	cout<<"Rectangle Area : "<<bRec.rectangleArea()<<endl;
	cout<<"Rectangle Lenght : "<<bRec.findLenght()<<endl;
	cout<<Rectangle::count();
}
