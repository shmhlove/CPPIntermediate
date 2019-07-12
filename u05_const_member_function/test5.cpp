/* 빌드 하는 법
	g++ test1.cpp
	cl test1.cpp /nologo /EHsc
	
	주의! VC++ 확장 문법 사용을 사용해야함.
	/Za 옵션을 사용하면 컴파일 안됨
*/

#include <stdio.h>
#include <iostream>
using namespace std;

struct Cache
{
	char cache[16];
	bool cache_valid = false;
};

class Point
{
private:
	int x, y;
	Cache* pCache;
	
public:
	Point(int a = 0, int b = 0) : x(a), y(b)
	{
		pCache = new Cache;
	}
	~Point()
	{
		delete pCache;
	}
	
	// 사용자가 const 객체를 만들 수 있기때문에상수
	// 상수 멤버함수로 만들어야한다.
	const char * toString() const
	{
		// static이 없으면 return 후 s가 파괴된다.
		// static char s[16];
		// sprintf(s, "%d, %d", x, y);
		
		// sprintf의 오버헤드가 크다고 가정하면
		// toString이 호출되었을때 x와y값이 변하지 않았다면
		// sprintf를 다시 호출하지 않도록 해보자.
		// 하지만 상수멤버함수 이기때문에 멤버변수를 변경할 수 없다.
		
		// 1. 멤버변수 선언시 mutable 키워드를 사용한다.
		//		-> mutable 멤버변수는 상수멤버함수 안에서도 값을 변경할 수 있다.
		// 2. 외부클래스에 접근하고 싶은 멤버를 두고 객체를 생성하면 접근할 수 있다.
		if (false == pCache->cache_valid)
		{
			sprintf(pCache->cache, "%d, %d", x, y);
			pCache->cache_valid = true;
		}
		
		return pCache->cache;
	}
};

int main()
{
	const Point p1(1, 1);
	
	cout << p1.toString() << endl;
	cout << p1.toString() << endl;
}