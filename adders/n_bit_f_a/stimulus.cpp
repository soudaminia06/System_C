#include "systemc.h"
//#include "design.cpp"
//#include "const.h"


SC_MODULE (Stimulation) {
  // Module IO
  
  sc_signal<sc_bv<1>>  a[N];
  sc_signal<sc_bv<1>>  b[N];
  sc_signal<sc_bv<1>> cin;
  sc_signal<sc_bv<1>> sum[N];
  sc_signal<sc_bv<1>> carry_out;

  sc_trace_file* f ;
  FullAdder* adder[N];
  int i;

  
  // Procinesses
  void stim () {
	srand(time(NULL)) ;
	while (true){

        for (i = 0; i < N; i++) {
            a[i].write(rand() % 2);
            b[i].write(rand() % 2);
	}
	cin.write(rand()%2);

        // print out the inputs
        cout << "Inputs:" << endl;
       
		cout << "a = " << "  ";
		for(i = N-1; i>=0 ; i--){
			cout << a[i];
		}
		cout << "  ";

		cout << "b = ";
		for(int i = N-1; i>=0 ; i--){
			cout << b[i];
		}
		cout << "  ";
		cout << " cin = " << cin.read() << endl;

		cout << "sum = ";
		for(i = N-1; i>=0 ; i--){
	 	cout << sum[i];
		}
		cout << " ";

		cout << " carry_out = " << carry_out.read() << endl;
	
		cout << "end " << endl;
		//wait(10, SC_NS);

	
 
                // Combine signals for tracing
		sc_bv<N> a_sig, b_sig, sum_sig;
	
		
		for (i = 0; i < N; i++) {
                a_sig[i] = a[i].read().get_bit(0);
                b_sig[i] = b[i].read().get_bit(0);
                sum_sig[i] = sum[i].read().get_bit(0);
		
		}

		f = sc_create_vcd_trace_file("waves");

		// Add signals to trace
	        sc_trace(f, cin, "cin");
	       	sc_trace(f, carry_out, "carry_out");
		
		// Trace combined signals
		sc_trace(f, a_sig, "a_sig");
	       	sc_trace(f, b_sig, "b_sig");
	       	sc_trace(f, sum_sig, "sum_sig");


		wait(20, SC_NS);
	}

	    //SC_THREAD(stim);
    }
   SC_CTOR(Stimulation){
	   SC_THREAD(stim);



   }

    ~Stimulation(){
	    sc_close_vcd_trace_file(f);
	    	    
    }
};


