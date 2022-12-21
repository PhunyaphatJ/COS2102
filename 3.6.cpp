#include <iostream>
// #include <string.h>
using namespace std;
class Rectangle{
	static int num;
	float width,height;
	string name;
//	 char name[20];
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
		Rectangle(float w,float h,string s){
			++num;
			set(w,h,s);
		}
		void set(float w,float h,string s){
			this->width= w;
			this->height = h;
			this->name = s;
//			strcpy(name,s);
		}
		void setName(string s){
//			 strcpy(name,s);
			this->name = name;
		}
		void setWidth(float w){
			this->width = w;
		}
		void setHeight(float h){
			this->height = h;
		}
		string getName(){
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

class MyRect{
	int row,col;
	Rectangle **rect;
	void deleteObj(){ //delte
		if(rect!=0){
		for(int i=0;i<row;i++)
			delete[] rect[i];
		delete[] rect;
	}
}
	void setRowCol(int r,int c){ //function create new obj
	row =r;
	col = c;
	rect = new Rectangle *[row];
	for(int i=0;i<row;i++){
		rect[i] = new Rectangle[col];
	}
}
	public:
		MyRect(){
			rect=0;
			row=col=0;
		}
		MyRect(int r,int c);
		~MyRect();
		void set();
		void show();
		void setObj(int r,int c,int w,int h,string name);
		void reset(int r,int c);
		Rectangle getRect();
};
MyRect::MyRect(int r,int c){
	setRowCol(r,c);
}
void MyRect::setObj(int r,int c,int w,int h,string name){
	cout<<"set obj\n";
	printf("MyRect[%d][%d]\n",r,c);
	cout<<"name : "<<name<<endl;
	cout<<"widht : "<<w<<endl;
	cout<<"height : "<<h<<endl;
	rect[r][c].set(w,h,name);
}
void MyRect::set(){
	int w,h;
	string name;
	for(int i=0;i<row;i++){
		for(int j =0;j<row;j++){
			printf("MyRect[%d][%d]",i,j);
			cout<<" name : ";cin>>name;
			cout<<" width : ";cin>>w;
			cout<<" height : ";cin>>h;
			rect[i][j].set(w,h,name);
		}
	}
}
void MyRect::reset(int r,int c){
		deleteObj();
		//
		setRowCol(r,c);
	}

Rectangle MyRect::getRect(){
	int r,c;
	cout<<"row : ";cin>>r;
	cout<<"col : ";cin>>c;
	return rect[r][c];
}
void MyRect::show(){
	cout<<"\n----------show-----------------\n";
	for(int i = 0;i<row;i++){
		for(int j=0;j<col;j++){
			printf("MyRect[%d][%d]",i,j);
			rect[i][j].show();
			cout<<"-------------------------------\n";
		}
	}
}
MyRect::~MyRect(){
	deleteObj();
	}

int main(){
	MyRect *a;
	MyRect b(3,3);
	cout<<"b before reset\n";
	b.show();
	b.reset(2,2);
	b.set();
	cout<<"b after reset\n";
	b.show();
	b.setObj(1,0,33,33,"setObj");
	Rectangle c;
	c = b.getRect();
	cout<<"c = b.getRect\n";
	c.show();
	b.show();
}
