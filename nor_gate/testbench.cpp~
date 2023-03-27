#include "systemc.h"
#include "design.cpp"
#include "stimulus.cpp"

int sc_main(int argc, char* argv[]) {
  sc_clock clk("clock", 10, SC_NS, 0.5);
  sc_signal<bool> clr;
  sc_signal<bool> a;
  sc_signal<bool> b;
  sc_signal<bool> q;
  sc_signal<bool> q_bar;



  // Connect the DUT
  Second second("second example");
  second.clk(clk);
  second.clr(clr);
  second.a(a);
  second.b(b);
  second.q(q);
  second.q_bar(q_bar);

  // Connect the test bench
  Stimulation tb("Stimulation Test");
  tb.clk(clk);
  tb.clr(clr);
  tb.a(a);
  tb.b(b);
  tb.q(q);
  tb.q_bar(q_bar);
  
  // Set up the waveform dump
  sc_trace_file* f = sc_create_vcd_trace_file("waves");
  sc_trace(f, clk, "clock");
  sc_trace(f, clr, "clear");
  sc_trace(f, a, "a");
  sc_trace(f, b, "b");
  sc_trace(f, q, "q");
  sc_trace(f, q_bar, "q_bar");

  //Run the simulation
  sc_start(40, SC_NS);
  
  // Close the 
  sc_close_vcd_trace_file(f);
  
  return 0;
}
