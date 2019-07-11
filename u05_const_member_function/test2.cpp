/* 빌드 하는 법
	g++ test1.cpp
	cl test1.cpp /nologo /EHsc
	
	주의! VC++ 확장 문법 사용을 사용해야함.
	/Za 옵션을 사용하면 컴파일 안됨
*/

#include <iostream>
#include "Point.h"
using namespace std;

int main()
{
	const Point p(1, 1);
	//p.x = 10; 		// error, p가 const라 error
	//p.set(10, 20);    // error, args 문제와 내부적으로는 this.x = a, this.y = b가 명령되니 this가 const라 error
	p.print();	    // error, args this는 타입이 Point &라서 const Point를 받을 수 없음. print가 const라면 args가 const Point &로 변경되니 가능해짐.
}