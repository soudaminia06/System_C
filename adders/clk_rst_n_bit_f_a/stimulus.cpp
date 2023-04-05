#include "systemc.h"
//#include "design.cpp"
//#include "const.h"


SC_MODULE (Stimulation) {
  // Module IO
  sc_in_clk clk;
  sc_in<bool> reset;

  sc_signal<sc_bv<1>>  a[N];
  sc_signal<sc_bv<1>>  b[N];
  sc_signal<sc_bv<1>> cin;
  sc_signal<sc_bv<1>> sum[N];
  sc_signal<sc_bv<1>> carry_out;
 // Internal signals
    sc_signal<sc_bv<1>> a_sig[N];
    sc_signal<sc_bv<1>> b_sig[N];
    sc_signal<sc_bv<1>> cin_sig;
    sc_signal<sc_bv<1>> sum_sig[N];
    sc_signal<sc_bv<1>> carry_out_sig;

    // N-bit adder module
    sc_trace_file* f ;
   // NBitAdder* adder[N];
    int i;

    SC_CTOR(Stimulation) //:
      // a[N] {"signal a"},
       //b[N] {"signal b"}
       /*a{"signal a", N},
       b{"signal b", N}*/

       	{
        // Instantiating the N-bit adder module
       /* adder = new NBitAdder("adder");

        // Connecting the input ports
        adder->clk(clk);
        adder->reset(reset);
        adder->a(a_sig);
        adder->b(b_sig);
        adder->cin(cin_sig);

        // Connecting the output ports
        adder->sum(sum_sig);
        adder->carry_out(carry_out_sig);*/

          SC_THREAD(stim);
    }      

    void stim() {
        // Generating random input values for a, b, and cin
        srand(time(NULL));
        while(true) {
		
            /*a_sig = rand() % (1 << N);
            b_sig = rand() % (1 << N);
            cin_sig = rand() % 2;*/

		
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
		};

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

	   	   
            // Applying the inputs on the rising edge of the clock
        //    wait(clk.posedge_event());
	    	
		for (i = 0; i < N; i++) {

            a[i].write(a_sig[i]);
            b[i].write(b_sig[i]);
		}
            cin.write(cin_sig);
      //  }
        // Finishing the simulation
        sc_stop();
    }
//}


    ~Stimulation(){
	    sc_close_vcd_trace_file(f);
    }
	    	    
    
};


       



