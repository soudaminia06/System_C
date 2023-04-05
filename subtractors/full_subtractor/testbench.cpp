#include "systemc.h"
#include "design.cpp"
#include "stimulus.cpp"

int sc_main(int argc, char* argv[]) {
 // sc_signal <bool> a, b, cin diff, borrow;
  sc_signal <bool> a;
  sc_signal <bool> b;
  sc_signal <bool> cin;
  sc_signal <bool> diff;
  sc_signal <bool> borrow;



  // Connect the DUT
  FullSubtractor sub("sub");
  sub.a(a);
  sub.b(b);
  sub.cin(cin);
  sub.diff(diff);
  sub.borrow(borrow);

  // Connect the test bench
  Stimulation tb("Stimulation Test");
  tb.a(a);
  tb.b(b);
  tb.cin(cin);
  tb.borrow(borrow);
  tb.diff(diff);
  
  
  sc_start();
  
  return 0;
}
