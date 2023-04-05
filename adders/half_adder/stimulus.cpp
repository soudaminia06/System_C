#include "systemc.h"

//struct Stimulation : public 
SC_MODULE (Stimulation) {
  // Module IO
  
  sc_out<bool> a;
  sc_out<bool> b;
  sc_in<bool> sum;
  sc_in<bool> carry;

  sc_trace_file* f ;
  
  // Processes
  void stim () {
/*	srand(time(NULL)) ;
  for(int i = 0; i < 10; i++){
  a = rand() % 2;
  b = rand() % 2;;
  wait(2, SC_NS);
  cout << " a = " << a.read() <<" b = " << b.read()<< " sum = " << sum.read() << " "<<" carry = " << carry.read() << " "<<endl;*/
  //for(int i = 0; i < 2; i++){
  a = 0;
  b = 0;
  wait(2, SC_NS);

  cout << " a = " << a.read() <<" b = " << b.read()<< " sum = " << sum.read() << " "<<" carry = " << carry.read() << " "<<sc_time_stamp() << std::endl;
  a = 1;
  b = 0;
 wait(2, SC_NS);
  cout << " a = " << a.read() <<" b = " << b.read()<< " sum = " << sum.read() << " "<<" carry = " << carry.read() << " "<<sc_time_stamp() << std::endl;
  a = 0;
  b = 1;
  wait(2, SC_NS);
  cout << " a = " << a.read() <<" b = " << b.read()<< " sum = " << sum.read() << " "<<" carry = " << carry.read() << " "<<sc_time_stamp() << std::endl;
  a = 1;
  b = 1;
  wait(2, SC_NS);
  cout << " a = " << a.read() <<" b = " << b.read()<< " sum = " << sum.read() << " "<<" carry = " << carry.read() << " "<<sc_time_stamp() << std::endl;
//  }
  };

   
  /*void monitor() {
    while (true) {
      std::cout << " a = " << a.read();
      std::cout << " b = " << b.read();
      std::cout << " sum = " << sum.read() << " ";
      std::cout << " carry = " << carry.read() << " ";
      std::cout << sc_time_stamp() << std::endl;
     wait(2, SC_NS);
    }
  }*/
  
  // Constructor
  SC_CTOR(Stimulation) {
	  // Set up the waveform dump
   f = sc_create_vcd_trace_file("waves");
  sc_trace(f, a, "a");
  sc_trace(f, b, "b");
  sc_trace(f, sum, "sum");
  sc_trace(f, carry, "carry");


    // Register a thread in SystemC
    //sc_start(100, SC_NS);
    SC_THREAD(stim);
    //sensitive << clk.neg();
  //  sensitive << clr.neg();
    // Register a clocked thread in SystemC
   //SC_CTHREAD(monitor, a.pos());
    //SC_CTHREAD(monitor, b.pos());
  }    
  ~Stimulation()
  {
};
	  sc_close_vcd_trace_file(f);
  }
    
};
