#include "systemc.h"

/*struct Second : public */
SC_MODULE (Second) {
  // Circuit inputs and outputs
  sc_in<bool> clk;
  sc_in<bool> clr;
  sc_in<bool> a;
  sc_in<bool> b;
  sc_out<bool> q;
  sc_out<bool> q_bar;
  
  // Declaration of our method
 /* void nor_gate() {
    q.write( a.read() or b.read() );
    q_bar.write( not q.read());
  }
  */
   void nor_gate() {
    q.write( a.read() or b.read() );
   q_bar.write( not (a.read() or b.read()));
  }
  

  
  // Constructor declaration
  SC_CTOR(Second) {
    SC_METHOD(nor_gate);
    sensitive << clk.pos();
    sensitive << clr.pos();
  }
};
