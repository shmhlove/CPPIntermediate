/* 빌드 하는 법
	g++ test4.cpp
	cl test4.cpp /nologo /EHsc
	
	주의! VC++ 확장 문법 사용을 사용해야함.
	/Za 옵션을 사용하면 컴파일 안됨
*/

#include <iostream>
#include <string>
#include "ecourse.hpp"
using namespace std;
using namespace ecourse;

#include <map>

// class Clock;
// map<int, Clock*> this_map;

class Clock
{
	static map<int, Clock*> this_map;
	string name;
public:
	Clock(string n) : name(n){}
	
	void start(int ms)
	{
		int id = ec_set_timer(ms, timerHandler);
		this_map[id] = this;
	}
	
	static void timerHandler(int id)
	{
		Clock* const slef = this_map[id];
		cout << slef->name << endl;
	}
};

map<int, Clock*> Clock::this_map;


int main()
{
	Clock c1("A");
	Clock c2("\tB");
	
	c1.start(1000);
	c2.start(500);
	
	ec_process_message();
}