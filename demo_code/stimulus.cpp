#include "systemc.h"

struct ExampleStim : public sc_module {
  // Module IO
  sc_in<bool> clk;
  sc_out<bool> a;
  sc_out<bool> b;
  sc_in<bool> q; 
  
  // Processes
  void stim () {   
    while (true)    // while(1) is used for infinite loop
   {
    a.write(false);
      b.write(false);
      wait();
      a.write(true);
      wait();
      a.write(false);
      b.write(true);
      wait();
      a.write(true);
      wait();
      a.write(false);
      b.write(true);
      wait();
   }
  }
  
  void monitor() {
    while (true) {
      std::cout << "a = " << a.read();
      std::cout << " b = " << b.read();
      std::cout << " q = " << q.read() << " ";
      std::cout << sc_time_stamp() << std::endl;
     wait();
    }
  }
  
  // Constructor
  SC_CTOR(ExampleStim) {
    // Register a thread in SystemC
    SC_THREAD(stim);
    sensitive << clk.neg();
    // Register a clocked thread in SystemC
    SC_CTHREAD(monitor, clk.neg());
  }    
    
};
