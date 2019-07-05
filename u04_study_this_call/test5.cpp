/* 빌드 하는 법
	g++ test4.cpp
	cl test4.cpp /nologo /EHsc
	
	주의! VC++ 확장 문법 사용을 사용해야함.
	/Za 옵션을 사용하면 컴파일 안됨
*/

#include <iostream>
#include "ecourse.hpp"
using namespace std;
using namespace ecourse;

void foo(int id)
{
	cout << "foo : " << id << endl;
}

int main()
{
	int n1 = ec_set_timer(500, foo);
	int n2 = ec_set_timer(1000, foo);
	
	ec_process_message();
}