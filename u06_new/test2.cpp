﻿/* 빌드 하는 법
	g++ test1.cpp
	cl test2.cpp /nologo /EHsc
	
	주의! VC++ 확장 문법 사용을 사용해야함.
	/Za 옵션을 사용하면 컴파일 안됨
*/
#include <stdio.h>
#include <iostream>
using namespace std;

class Point
{
private:
	int x, y;
public:
	Point() { printf("Point()\n"); }
	~Point() { printf("~Point()\n"); }
};

void* operator new(size_t sz)
{
    printf("my new\n");
	//cout << "my new" << endl;
	return malloc(sz);
}

void operator delete(void* p) noexcept
{
    printf("my delete\n");
	//cout << "my delete" << endl;
	free(p);
}

int main()
{
	// malloc :  only memory
	Point* p1 = (Point*)malloc(sizeof(Point));
	printf("end malloc\n\n");
    
	// new : memory and constructor
	Point* p2 = new Point;
	// delete : memory and destructor
	delete p2;
	printf("end new-delete\n\n");
    
	// operator new : only memory
	Point* p3 = static_cast<Point*>(operator new(sizeof(Point)));
    // operator delete : only memory
	operator delete(p3);
    printf("end operator new-delete\n\n");
}