#include "systemc.h"

struct Example : public sc_module {
  // Circuit inputs and outputs
  sc_in<bool> clk;
  sc_in<bool> a;
  sc_in<bool> b;
  sc_out<bool> q;
  
  // Declaration of our method
  void clocked_and() {
    q.write( a.read() & b.read() );
  }
  
  // Constructor declaration
  SC_CTOR(Example) {
    SC_METHOD(clocked_and);
    sensitive << clk.pos();
  }
};

