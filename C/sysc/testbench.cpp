#include <helloclock.h>

int sc_main(int argc, char  *argv[])
{
	sc_clock clock1("clock1", 20, 0.5, 0, true);

	helloclock h("hello");
	return 0;
}