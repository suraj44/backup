#include <systemc.h>

SC_MODULE(andt)
{
	sc_in<bool> in1;
	sc_in<bool> in2;
	sc_out<bool> out;

	void doit()
	{
		out = in1&in2;
	};

	SC_CTOR(andt)
	{
		SC_METHOD(doit);

	}
};

int sc_main(int argc, char* argv[]) {
andt hello("HELLO");
// Print the hello world
//cout << "%d"<<hello.doit() << "\n" ;
return(0);
}