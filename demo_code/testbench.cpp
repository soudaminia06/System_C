#include "systemc.h"
#include "design.cpp"
#include "stimulus.cpp"

int sc_main(int argc, char* argv[]) {
  sc_clock clk("clock", 10, SC_NS, 0.5);
  sc_signal<bool> a;
  sc_signal<bool> b;
  sc_signal<bool> q;

  // Connect the DUT
  Example example("method_example");
  example.clk(clk);
  example.a(a);
  example.b(b);
  example.q(q);

  // Connect the test bench
  ExampleStim tb("ExampleTest");
  tb.clk(clk);
  tb.a(a);
  tb.b(b);
  tb.q(q);
  
  // Set up the waveform dump
  sc_trace_file* f = sc_create_vcd_trace_file("waves");
  sc_trace(f, clk, "clock");
  sc_trace(f, a, "a");
  sc_trace(f, b, "b");
  sc_trace(f, q, "q");

  //Run the simulation
  sc_start(40, SC_NS);
  
  // Close the 
  sc_close_vcd_trace_file(f);
  
  return 0;
}

