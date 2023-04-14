

#include "stimulus.cpp"

int sc_main(int argc, char* argv[]) {

	
	//multiplier

  // instantiating the DUT
    multiplier mul("mul");
    Stimulation sim("sim");
    mul.clk(sim.clk);
    mul.rst(sim.rst);
    mul.a(sim.a);
    mul.b(sim.b);
    mul.out(sim.out);

    sc_start(100,SC_NS);

    sc_stop();

    return 0;
}



