/* 빌드 하는 법
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
    printf("my new1\n");
	return malloc(sz);
}

void* operator new(size_t sz, int n, char* s)
{
    printf("my new2\n");
	return malloc(sz);
}

// 아래 재정의는 이미 C++ 표준에 구현되어 있음
//void* operator new(size_t sz, void* p)
//{
//    printf("my new3\n");
//	return p;
//}

void operator delete(void* p) noexcept
{
    printf("my delete\n");
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
    
	// new : memory and constructor
	Point* p4 = new(1, "A") Point;
	// delete : memory and destructor
    p4->~Point();
	delete p4;
	printf("end call destructor\n\n");
    
	// new : not memory, only call constructor
	Point p5;
    Point* p5_new = new(&p5) Point;
    printf("%p, %p\n", &p5, p5_new);
	printf("end call constructor\n\n");
}