#include "systemc.h"
#include "design.cpp"
#include "stimulus.cpp"



int sc_main(int argc, char *argv[]) {
       NBitMultiplier nbm("nbm");
       Stimulation tb("tb");

   // connecting the ports of the modules of the n bit multiplier to the testbench 
    for (int i = 0; i < N; i++) {
        nbm.A[i](tb.A[i]);
        nbm.B[i](tb.B[i]);
        nbm.O[i](tb.O[i]);
    }


  sc_start(100,SC_NS);
  sc_stop();

  return 0;
}




