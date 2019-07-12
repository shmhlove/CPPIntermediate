/* 빌드 하는 법
	g++ test1.cpp
	cl test1.cpp /nologo /EHsc
	
	주의! VC++ 확장 문법 사용을 사용해야함.
	/Za 옵션을 사용하면 컴파일 안됨
*/

#include <iostream>
using namespace std;

struct Rect
{
	int ox, oy, width, height;
	Rect(int x = 0, int y = 0, int w = 0, int h = 0)
		: ox(x), oy(y), width(w), height(h) {}
	int getArea() const { return width * height; }
};

// error C2662: 'int Rect::getArea(void)': 'this' 포인터를 'const Rect'에서 'Rect &'(으)로  변환할 수 없습니다.
// 해결하려면 getArea()를 const로 만들어야한다.
// 보통 getter함수는 const로 만드는게 맞다.
// 사용자가 언제 const로 객체를 받을지 알수가 없기 때문에 support해줘야하니깐
void foo(const Rect& r)
{
	int n = r.getArea();
}

int main()
{
	Rect r(0, 0, 10, 10);
	int n = r.getArea();
	foo(r);
}