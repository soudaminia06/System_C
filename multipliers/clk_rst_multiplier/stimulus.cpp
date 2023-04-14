#include "systemc.h"
#include "design.cpp"

SC_MODULE (Stimulation) {
   
  // define signals
    sc_signal<bool> clk;
    sc_signal<bool> rst;
    sc_signal<sc_biguint<N>> a;
    sc_signal<sc_biguint<N>> b;
    sc_signal<sc_biguint<2*N>> out;


  sc_trace_file* f ;
  
 // Processes
  void stim () {
	srand(time(NULL)) ;
	// initialising the  signals
	rst = 1;
	a = 0;
	b = 0;
	wait(5, SC_NS);
	rst = 0;
	wait(5, SC_NS);

	while(true){
		a = rand();
		b = rand();
    		clk = 1;
    		wait(5, SC_NS);
    		clk = 0;
    		wait(5, SC_NS);

    
    		cout << "Product of " << a.read() << " and " << b.read() << " = " << out.read() << endl;
	}
  }

   
   // Constructor
  SC_CTOR(Stimulation) {
	  // Set up the waveform dump
   f = sc_create_vcd_trace_file("waves");
  sc_trace(f, clk, "clk");
  sc_trace(f, rst, "rst");
  sc_trace(f, a, "a");
  sc_trace(f, b, "b");
  sc_trace(f, out, "out");
 


      SC_THREAD(stim);
  }

     ~Stimulation()
     {
	     sc_close_vcd_trace_file(f);
     }
    
};
