#include <iostream>
using namespace std;
template <class T>
T max(T x1,T x2,T x3){
    T max = x1;
    if(max<x2)
        max = x2;
    if(max<x3)
        max = x3;
    return max;
}
class Rectangle{
    int width;
    public:
    Rectangle(){width=0;}
    Rectangle(int w){width=w;}
    int area(){return width*width;}
    bool operator<(Rectangle r){
        if(area()<r.area())
            return true;
        return false;
    }
    Rectangle& operator=(const Rectangle &r){
        if(this==&r)return *this;
        width = r.width;
        return *this;
    }
    void print(){
        cout<<"width : "<<width<<endl;
        cout<<"area : "<<area()<<endl;
    }
};

  ostream& operator<<(ostream& os,Rectangle r){
	r.print();
	return os;
}
int main(){
    cout<<max(3,4,5)<<endl;
    cout<<max(8.5,5.5,2.5)<<endl;
    cout<<max('a','b','c')<<endl;
    Rectangle r1(10),r2(6),r3(7);
    cout<<max(r1,r3,r2);
}