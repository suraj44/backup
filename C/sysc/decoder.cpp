SC_MODULE(decoder)
{
	sc_in<sc_int(1)> in[4];
	sc_out<sc_int(1)> in[16];
	SC_CTOR(decoder)
	{
		sensitive_pos << clock;
	}
};

int sc_main(int argc, char* argv[])
{
	
}