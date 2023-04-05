#include "systemc.h"
#include "design.cpp"
#include "stimulus.cpp"


int sc_main(int argc, char* argv[]) {
    // Instantiating the testbench module
    NBitAdder nba("nba");
    Stimulation tb("tb");


   
    // Creating the clock and reset signals
    sc_clock clk("clk", 10, SC_NS);
    sc_signal<bool> reset("reset");

     for (int i = 0; i < N; i++) {
        nba.a[i](tb.a[i]);
        nba.b[i](tb.b[i]);
        nba.sum[i](tb.sum[i]);
    }
    nba.cin(tb.cin);
    nba.carry_out(tb.carry_out);


    // Connecting the clock and reset signals
    nba.clk(tb.clk);
    nba.reset(tb.reset);

    // Starting the simulation
    reset = 1;
    sc_start(1, SC_NS);
    reset = 0;
    sc_start(100, SC_NS);
    sc_stop();

    return 0;
}

