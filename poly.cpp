#include <iostream>
using namespace std;

class Polygon{
    protected:
        int length;
        int width;
    public:
        Polygon();
        void Dimensions();
        virtual void getArea()=0;
        // {
        //     cout<<"Polygon area: "<<length*width<<endl;
        // };

};

Polygon::Polygon(){
    cout<<"Please enter the length of the Polygon: ";
    cin>>length;
    cout<<"Please enter the width of the Polygon: ";
    cin>>width;
}
void Polygon::Dimensions(){
    cout<<"The dimensions of your polygon are: \n";
    cout<<"Width: "<<width<<"\nLength: "<<length<<endl;
}

class Rectangle:public Polygon{
    public:
        Rectangle();
        void getArea();
};
Rectangle::Rectangle(){
    cout<<"A rectangle object has been created!\n";
}
void Rectangle::getArea(){
    int area;
    area = length*width;
    cout<<"The area of the rectangle is: "<<area<<endl;
}

class Triangle:public Polygon{
    public:
        Triangle();
        void getArea();
};

Triangle::Triangle(){
    cout<<"\nA Triangle object has been created!\n";
}
void Triangle::getArea(){
    float area;
    area = 0.5*length*width;
    cout<<"\nThe area of the triangle is: "<<area<<endl;
}

int main(){
    cout<<"Rectangle object being created\n";
    Rectangle R1;
    cout<<"Triangle object being created\n";
    Triangle T1;
    T1.Dimensions();
    T1.getArea();
    R1.Dimensions();
    R1.getArea();
    cout<<"Let us now create a polygon\n";
    // Polygon P;
    // cout<<"Polygon created succesfully\n";
    // P.getArea();
    return 0;
}