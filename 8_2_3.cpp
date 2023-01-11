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
		
		float operator++(){
			return ++height;
		}
		float operator++(int){
			float w = width++;
			return w;
		}
		friend float operator--(Rectangle &x){
			if(x.width<=0&&x.height<=0){
				cout<<"--xwidht height <=0\n";
				exit(1);
			}
			return --x.height;
		}
		friend float operator--(Rectangle &x,int){
			if(x.width<=0&&x.height<=0){
				cout<<"x--widht height <=0\n";
				exit(1);
			}
			float w = x.width--;
			return w;
		}
		bool operator <(Rectangle &x2){
			return (this->rectangleArea()<x2.rectangleArea())?true:false;
		}
		bool operator <=(Rectangle &x2){
			return (this->rectangleArea()<=x2.rectangleArea())?true:false;
		}
		bool operator >(Rectangle &x2){
			return (this->rectangleArea()>x2.rectangleArea())?true:false;
		}
		bool operator >=(Rectangle &x2){
			return (this->rectangleArea()>=x2.rectangleArea())?true:false;
		}
		bool operator !=(Rectangle &x2){
			return (this->rectangleArea()!=x2.rectangleArea())?true:false;
		}
		float operator[](int x){
			switch(x){
				case 0:
					return height;
					break;
				case 1:
					return width;
				default:
					return -1;
			}
		}
		float operator()(){
			return -1;
		}
		float operator()(float x){
			return x*x;		
		}
		float operator()(float x,float y){
			return x*y;
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
	Rectangle a;
	a.show();
	++a;
	cout<<"--------"<<endl;
	a.show();
	float posA = a++;
	cout<<"--------"<<endl;
	cout<<"posA postfix = "<<posA<<endl;
	a.show();
	cout<<"--------"<<endl;
	Rectangle b(2,3);
	cout<<"b"<<endl;
	b.show();
	cout<<"--------"<<endl;
	--b;
	cout<<"--prefix"<<endl;
	b.show();
	float posB = b--;
	cout<<"--------"<<endl;
	cout<<"posB postfix = "<<posB<<endl;
	cout<<"postfix--"<<endl;
	b.show();
	Rectangle c(2,2),d(2,2);
	if(b>=c){
		cout<<"t\n";
	}else{
		cout<<"f\n";
	}
	cout<<b[0]<<" "<<b[1]<<" "<<b[-999]<<endl;
	cout<<b()<<" "<<b(3)<<" "<<b(3,2)<<endl;
}
