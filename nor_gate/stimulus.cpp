#include "systemc.h"

//struct Stimulation : public 
SC_MODULE (Stimulation) {
  // Module IO
  sc_in<bool> clk;
  sc_in<bool> clr;
  sc_out<bool> a;
  sc_out<bool> b;
  sc_in<bool> q; 
  sc_in<bool> q_bar;
  
  // Processes
  void stim () {   
    while (true)    // while(1) is used for infinite loop
   {
      a.write(false);
      b.write(false);
      wait();
      a.write(false);
      b.write(true);
      wait();
      a.write(true);
      b.write(false);
      wait();
      a.write(true);
      b.write(true);
      wait();
    }
  }

 /* void stim () {   
    while (true)    // while(1) is used for infinite loop
   {
        int i;

  a.write(1);

  for(i=0; i<=5; i++)
  {
   b.write(1);
    wait(10, SC_NS);
    a.write(0);
    wait(10, SC_NS);
  }

  b.write(0);

  for(i=0; i<=18; i++)
  {
    a.write(1);
    wait(10, SC_NS);
    b.write(0);
    wait(10, SC_NS);
  }

  a.write(1);

  for(i=0; i<=3; i++)
  {
    b.write(1);
    wait(10, SC_NS);
    a.write(0);
    wait(10, SC_NS);
  }

  a.write(0);

  for(i=0; i<=18; i++)
  {
    b.write(1);
    wait(10, SC_NS);
    a.write(0);
    wait(10, SC_NS);
  }

  sc_stop();  //$finish
}
}*/
    
  
  void monitor() {
    while (true) {
      std::cout << "a = " << a.read();
      std::cout << " b = " << b.read();
      std::cout << " q = " << q.read() << " ";
      std::cout << " q_bar = " << q_bar.read() << " ";
      std::cout << sc_time_stamp() << std::endl;
     wait();
    }
  }
  
  // Constructor
  SC_CTOR(Stimulation) {
    // Register a thread in SystemC
    SC_THREAD(stim);
    sensitive << clk.neg();
    sensitive << clr.neg();
    // Register a clocked thread in SystemC
    SC_CTHREAD(monitor, clk.neg());
  }    
    
};
