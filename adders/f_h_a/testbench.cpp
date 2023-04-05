#include "systemc.h"
#include "design.cpp"
#include "Stimulus.cpp"

int sc_main(int argc, char* argv[]) {
 // sc_signal <bool> a, b, cin sum, carry;
  sc_signal <bool> a;
  sc_signal <bool> b;
  sc_signal <bool> cin;
  sc_signal <bool> sum;
  sc_signal <bool> carry_out;



  // Connect the DUT
  FullAdder adder("adder");
  adder.a(a);
  adder.b(b);
  adder.cin(cin);
  adder.sum(sum);
  adder.carry_out(carry_out);

  // Connect the test bench
  Stimulation tb("Stimulation Test");
  tb.a(a);
  tb.b(b);
  tb.cin(cin);
  tb.sum(sum);
  tb.carry_out(carry_out);
  
  
  sc_start(100,SC_NS);
  
  return 0;
}
