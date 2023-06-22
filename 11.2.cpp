#include <iostream>
using namespace std;
template <class T>
class M{
    T *a;
    public:
    M(){
        a = new T[5];
    }

    void set(){
        for(int i=0;i<5;i++){
            printf("a[%d] : ",i);cin>>a[i];
        }
        }
    T findMax(){
        T max = a[0];
        for(int i=1;i<5;i++){
            if(max<a[i])
                max = a[i];
        }
        return max;
    }
    
    T findMin(){
        T min = a[0];
        for(int i=1;i<5;i++){
            if(min>a[i])
                min = a[i];
        }
        return min;
    }
    ~M(){
        delete []a;
    }
};
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
    bool operator>(Rectangle r){
        if(area()>r.area())
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
    void input(){
        cin>>width;
    }
};
  ostream& operator<<(ostream& os,Rectangle r){
	r.print();
	return os;
}
istream& operator>>(istream& is,Rectangle &r){
    r.input();
    return is;
}
int main(){
   M<int> x;
   x.set();
   cout<<x.findMax()<<endl;
   cout<<x.findMin()<<endl;
   M<double> y;
   y.set();
   cout<<y.findMax()<<endl;
   cout<<y.findMin()<<endl;
   M<char> c;
   c.set();
   cout<<c.findMax()<<endl;
   cout<<c.findMin()<<endl;
   M<Rectangle> r;
   r.set();
   cout<<r.findMax()<<endl;
   cout<<r.findMin()<<endl;
}
