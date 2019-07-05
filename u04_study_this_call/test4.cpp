/* 빌드 하는 법
	g++ test4.cpp
	cl test4.cpp /nologo /EHsc
	
	주의! VC++ 확장 문법 사용을 사용해야함.
	/Za 옵션을 사용하면 컴파일 안됨
*/

#include <iostream>
#include <windows.h>
using namespace std;

class Thread
{
public:
	void run()
	{
		// CreateThread(0, 0, threadMain, 0, 0, 0);	error. threadMain에는 this가 숨어있다.
		CreateThread(0, 0, threadMain, 0, 0, 0);
		CreateThread(0, 0, threadMain, (void*)this, 0, 0);
	}
	
	// CreateThread 라이브러리를 사용하기 위해서는 아래 함수는 반드시 static 함수 이어야한다.
	DWORD static __stdcall threadMain(void* p)
	{
		// Main();	// error. static으로 변경 후 this가 없기 때문에 Main을 호출할 수가 없다.
		
		Thread* const slef = static_cast<Thread*>(p);
		slef->Main();
		
		return 0;
	}
	
	virtual void Main() {}
};

class MyThread : public Thread
{
public:
	virtual void Main() { cout << "스레드 작업" << endl; }
};

int main()
{
	MyThread p;
	p.run();
}