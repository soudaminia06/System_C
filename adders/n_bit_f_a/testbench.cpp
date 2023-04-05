#include "systemc.h"
#include "design.cpp"
#include "stimulus.cpp"

int sc_main(int argc, char* argv[]) {
    // creating a module for the n bit adder and the stimulation 
    NBitAdder nba("nba");
    Stimulation tb("tb");

       // connecting the ports of the modules of the n bit adder to the testbench 
    for (int i = 0; i < N; i++) {
        nba.a[i](tb.a[i]);
        nba.b[i](tb.b[i]);
        nba.sum[i](tb.sum[i]);
    }
    nba.cin(tb.cin);
    nba.carry_out(tb.carry_out);

    // start the simulation
    sc_start(100,SC_NS);
    sc_stop();

    return 0;
}



