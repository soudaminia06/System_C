#include <systemc.h>
#include "HalfSubtractor.h"

SC_MODULE(FullSubtractor) {
  // Input signals
  sc_in<bool> a, b, cin;

  // Output signals
  sc_out<bool> diff, borrow;

  // Internal signals
  sc_signal<bool> d1, b1, b2;

  // Half subtractor
  HalfSubtractor hs1;
  HalfSubtractor hs2;

  SC_CTOR(FullSubtractor) : hs1("hs1"), hs2("hs2") {
    // Connect half subtractor inputs
    hs1.a(a);
    hs1.b(b);
    hs2.a(d1);
    hs2.b(cin);

    // Connect half adder outputs
    hs1.diff(d1);
    hs1.borrow(b1);
    hs2.diff(diff);
    hs2.borrow(b2);

    // Calculate the carry out
    SC_METHOD(output);
    sensitive << b1 << b2;
  }

  // Carry out calculation method
  void output() {
    borrow.write(b1.read() || b2.read());
  }
};

