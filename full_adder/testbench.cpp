#include "systemc.h"
#include "design.cpp"
#include "stimulus.cpp"

int sc_main(int argc, char* argv[]) {
 // sc_signal <bool> a, b, cin sum, carry;
  sc_signal <bool> a;
  sc_signal <bool> b;
  sc_signal <bool> cin;
  sc_signal <bool> sum;
  sc_signal <bool> carry;



  // Connect the DUT
  FullAdder adder("adder");
  adder.a(a);
  adder.b(b);
  adder.cin(cin);
  adder.sum(sum);
  adder.carry(carry);

  // Connect the test bench
  Stimulation tb("Stimulation Test");
  tb.a(a);
  tb.b(b);
  tb.cin(cin);
  tb.carry(carry);
  tb.sum(sum);
  
  
  sc_start();
  
  return 0;
}
