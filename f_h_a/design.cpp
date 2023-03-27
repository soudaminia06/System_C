#include <systemc.h>
#include "HalfAdder.h"

SC_MODULE(FullAdder) {
  // Input signals
  sc_in<bool> a, b, cin;

  // Output signals
  sc_out<bool> sum, carry_out;

  // Internal signals
  sc_signal<bool> s1, c1, c2;

  // Half adders
  HalfAdder ha1;
  HalfAdder ha2;

  SC_CTOR(FullAdder) : ha1("ha1"), ha2("ha2") {
    // Connect half adder inputs
    ha1.a(a);
    ha1.b(b);
    ha2.a(s1);
    ha2.b(cin);

    // Connect half adder outputs
    ha1.sum(s1);
    ha1.carry(c1);
    ha2.sum(sum);
    ha2.carry(c2);

    // Calculate the carry out
    SC_METHOD(output);
    sensitive << c1 << c2;
  }

  // Carry out calculation method
  void output() {
    carry_out.write(c1.read() || c2.read());
  }
};

