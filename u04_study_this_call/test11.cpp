#include <stdio.h>
#include <iostream>
using namespace std;

class Point
{
public:
	int x, y;
	void print(){}
};

int main()
{
	int n = 10;
	int *p1 = &n;
	
	void(Point::*f)() = &Point::print;	// 멤버 함수 포인터
	
	int Point::*p2 = &Point::x;			// 멤버 변수 포인터 (?? 아직 Point는 메모리에 없는디 ??)
										// x는 Point안에서 얼마나 떨어져있는지 offset 즉, 0
	int Point::*p3 = &Point::y;			// 요고는 4
	
	// C의 offset_of 매크로와 동일한 기법
	
	//cout << p2 << ", " << p3 << endl;
	printf("%d, %d\n", p2, p3);
	
	Point pt;
	pt.y = 10;
	pt.*p3 = 20;	// pt의 위치에서 p3만큼 offset을 뛰어넘어가면 y가 지목된다.
	
	cout << pt.y << endl; // 20
}