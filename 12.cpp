#include <iostream>
#include <exception>
// #define throw(...)

using namespace std;

class Animal
{
    public:
    Animal(){cout<<"Animal\n";}
    virtual void catch_Override() throw(int,double){
        throw 12;
    }
};

class Dog:public Animal
{
     public:
     Dog(){cout<<"Dog\n";}
     void catch_Override() throw(double){
        throw 12.5;
     }
};


void f()
{
    Dog d;
    throw d;
}

void f3()
{
   throw 'a';
}

void f2()
{
    try{
        f3();
    }catch(char c){
        throw c;
    }
}

void f1()
{
    try{
        f2();
    }catch(char c){
        cout<<"ex : "<<c<<endl;
    }
}

class MyException:public exception
{
    virtual const char* what()const throw(){
        return "exexexex";
    }
};
int main(){

    /* ---------------------------
            12.1 - 12.2 
    ------------------------------*/
    cout<<"12.1-12.2\n";
    try
    {
        throw(1); //int
        // throw(1.1); //double
        // throw('a'); //char
        char *s;
        // throw(s); //pointer -> char
        // throw("asdf"); //string (other exceptions)
    }
    catch(int x){
        cout<<"catch int"<<endl;
    }catch(double x){
        cout<<"catch double"<<endl;
    }catch(char x){
        cout<<"catch char"<<endl;
    }catch(char *c){
        cout<<"catch pointer char"<<endl;
    }catch(...){
        cout<<"Ohter exceptions"<<endl;
    }

    /* ---------------------------
                12.3
    ------------------------------*/
    cout<<"12.3\n";
    try
    {
       f();
    }
    catch(Dog)
    {
        cout<<"catch Dog"<<endl;
    }
    catch(Animal){
        cout<<"catch Animal"<<endl;
    }

    /* ---------------------------
                12.4
    ------------------------------*/
    cout<<"12.4\n";
    f1();

    /* ---------------------------
                12.5
    ------------------------------*/
    cout<<"12.5\n";
    Animal *a = new Animal();
    Animal *d = new Dog();
    try{
//         d->catch_Override();
        a->catch_Override();
    }
    catch(int i){
        cout<<"Exception: "<<i<<endl;
    }catch(double i){
        cout<<"Exception: "<<i<<endl;
    }

    /* ---------------------------
                12.6
    ------------------------------*/
    cout<<"12.6\n";
    MyException ex;
    try{
        throw ex;
    }catch(exception& e){
        cout<<e.what()<<endl;
    }
}
