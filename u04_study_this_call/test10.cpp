/* 빌드 하는 법
	g++ test4.cpp
	cl test10.cpp /nologo /EHsc
	
	주의! VC++ 확장 문법 사용을 사용해야함.
	/Za 옵션을 사용하면 컴파일 안됨
*/

#include <iostream>
#include <string>
using namespace std;

class A
{
	int a;
public:
	void fa() { cout << this << endl; }
};
class B
{
	int b;
public:
	void fb() { cout << this << endl; }
};

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
	
	obj.fa(); // fa(&obj);
	obj.fb(); // fb(&obj + sizeof(A));
	
	void (C::*f)();
	cout << sizeof(f) << endl; // 8byte (함수주소 + this object)
	
	f = &C::fa;
	(obj.*f)();	// fa(&obj);
	
	f = &C::fb;
	(obj.*f)();	// fb(&obj + sizeof(A));
}