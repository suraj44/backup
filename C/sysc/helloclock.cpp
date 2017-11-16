#include <systemc.h>

SC_MODULE(hello) 
{
	sc_in<bool> clock;
	void print()
	{
		cout <<"Hello world\n";
	}
		//SC_METHOD(behavior);
	SC_CTOR(print);
	{  

		sensitive_pos << clock;

	}
};

int sc_main(int argc, char  *argv[])
{
	sc_clock clock1("clock1", 20, 0.5, 0, true);

	helloclock h("hello");
	
	return 0;
}