#include "systemc.h"
#include "design.cpp"
#include "stimulus.cpp"

int sc_main(int argc, char* argv[]) {
  sc_signal <bool> a, b, sum, carry;
 /* sc_signal<bool> a;
  sc_signal<bool> b;
  sc_signal<bool> sum;
  sc_signal<bool> carry;*/



  // Connect the DUT
  HalfAdder adder("adder");
  adder.a(a);
  adder.b(b);
  adder.sum(sum);
  adder.carry(carry);

  // Connect the test bench
  Stimulation tb("Stimulation Test");
  tb.a(a);
  tb.b(b);
  tb.carry(carry);
  tb.sum(sum);
  
  
  // Set up the waveform dump
 /* sc_trace_file* f = sc_create_vcd_trace_file("waves");
  sc_trace(f, a, "a");
  sc_trace(f, b, "b");
  sc_trace(f, sum, "sum");
  sc_trace(f, carry, "carry");*/

  //Run the simulation
  sc_start();
  
  // Close the 
 // sc_close_vcd_trace_file(f);
  
  return 0;
}
