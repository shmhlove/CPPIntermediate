/* 빌드 하는 법
	g++ test1.cpp
	cl test1.cpp /nologo /EHsc
	
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
	Point()
	{
		cout << "Point()" << endl;
	}
	~Point()
	{
		cout << "~Point()" << endl;
	}
};

void* operator new(size_t sz)
{
	cout << "my new" << endl;
	return malloc(sz);
}

void operator delete(void* p) noexcept
{
	cout << "my delete" << endl;
	free(p);
}

int main()
{
	cout << "new" << endl;
	
	// malloc :  메모리만 할당
	Point* p1 = (Point*)malloc(sizeof(Point));
	
	// new : 메모리할당 + 생성자 호출
	Point* p2 = new Point;
	// delete : 메모리해제 + 소멸자 호출
	delete p2;
	
	// operator new : 메모리만 할당
	// operator delete : 메모리만 해제
	Point* p3 = static_cast<Point*>(operator new(sizeof(Point)));
	operator delete(p3);
	
}