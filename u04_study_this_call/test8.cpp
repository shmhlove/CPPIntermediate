/* 빌드 하는 법
	g++ test4.cpp
	cl test8.cpp /nologo /EHsc
	
	주의! VC++ 확장 문법 사용을 사용해야함.
	/Za 옵션을 사용하면 컴파일 안됨
*/

#include <iostream>
#include <string>
using namespace std;

class A { int a; };
class B { int b; };

class C : public A, public B
{
	int c;
};

int main()
{
	C obj;
	
	A* pA = &obj;
	B* pB = &obj;	// &obj + sizeof(A);
	
	cout << &obj << endl;
	cout << pA << endl;
	cout << pB << endl;
}