#include<stdio.h>
#include <iostream>
#include<cstdio>
#include ".\MyHeader.h" //.\로 현재 디렉토리를 나타낸다.  ..\ .2개는 상위 디렉토리
using namespace std;

class Point
{
private:

public:
    int x; // 기본 접근 제어 지시자는 private 
    int y;


    Point(int x=0, int y=0)//: x(0), y(0)
    {
        this->x = x; this->y = y;
    }
    int GetX() { return x; } //정보 은닉
    int GetY() { return y; }
    void SetX(int x) { this->x = x; }
    void SetY(int y) { this->y = y; }
    double distance(Point p) //Point p와의 거리
    {
        int x2 = (x - p.x) * (x - p.x);
        int y2 = (y - p.y) * (y - p.y);
        return  sqrt(x2 + y2);
    }
};

class Point3D : public Point //2D Point class 상속
{
private:
    int z; //z축

public:
    Point3D(int x = 0, int y = 0, int z = 0) : Point(x,y)
    {
        this->z = z;
    }
    int Z() { return z; }
    void SetZ(int z) { this->z = z; }
    double distance(Point3D p) //Point p와의 거리
    {
        int x2 = (X() - p.X()) * (X() - p.X());
        int y2 = (Y() - p.Y()) * (Y() - p.Y());
        int z2 = (z - p.z) * (z - p.z);
        return  sqrt(x2 + y2+z2);
    }
};

int main()
{
   /* cout << "Hello C plus plus World!\n\n";

    int a, b;
    a = 10;
    b = 20;

    cout << "초기값은 a=" << a << ", b= " << b<<endl;

    swapValue(a, b);
    cout << "결과값(swapValue)은 a=" << a << ", b= " << b<<endl;

    swapRef(a, b); //reference type 호출
    printf("결과값(swapRef:ref)은 a=%d, b=%d \n", a, b);

    swapRef(&a, &b); //pointer type 호출
    printf("결과값(swapRef:포인터)은 a=%d, b=%d \n\n", a, b);*/
    Point p1; //p(0,0)
    Point p2(10, 20);
    Point *p3 = new Point(20,30);  //동적 할당
    printf("Point class 변수의 동적 할당: p3(%d,%d)\n\n", p3->x, p3->y); //포인터이기 때문에 화살표
    printf("두 점 p1(%d,%d)과 p2(%d,%d)의 거리는 %f 입니다.\n", p1.x, p1.y, p2.x, p2.y, p1.distance(p2));

    Point3D pp1;
    Point3D pp2(10, 20, 30);
    Point3D* pp3 new Point3D(40, 50, 60); 
    //cout<<"두 점 p1("
    printf("Point3D class 변수의 동적 할당: pp3(%d,%d, %d)\n\n", pp3->X(), pp3->Y(), pp3->Z()); //포인터이기 때문에 화살표
    printf("두 점 pp1(%d,%d,%d)과 pp2(%d,%d,%d)의 거리는 %f 입니다.\n", 
        pp3->X(), pp3->Y(), pp3->Z(), pp2.X(), pp2.Y(), pp2.Z(), pp2.distance(*pp3));

}
