/*#include "systemc.h"

SC_MODULE (Stimulation) {
  // Module IO
  
  sc_signal<sc_uint<1>>  a[N];
  sc_signal<sc_uint<1>>  b[N];
  sc_signal<sc_uint<1>> cin;
  sc_signal<sc_uint<1>> sum[N];
  sc_signal<sc_uint<1>> carry_out;

  sc_trace_file* f ;
  FullAdder* adder[N];
  int i;

  
  // Processes
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

	
 
                // Combining signals for tracing
		sc_uint<N> a_sig, b_sig, sum_sig;
	
		
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
};*/





#include "systemc.h"
//#include "const.h"//constant file which acts a parameter.


SC_MODULE(Stimulation) {
	// Module IO
  
  sc_signal<sc_uint<1>>  A[N];
  sc_signal<sc_uint<1>>  B[N];
  sc_signal<sc_uint<1>>  O[2*N];

   /* sc_signal<sc_uint<N>> A, B;
  sc_signal<sc_uint<N>> O;*/
 // sc_trace_file* f ;
//  int i;

//  MUL<16> mul;
  sc_trace_file* f ;
 // MUL* mul[N];
  int i;

 
  // Processes
  void stim () {
	srand(time(NULL)) ;
	while (true){

        for (i = 0; i < N; i++) {
            A[i].write(rand() % 2);
            B[i].write(rand() % 2);
	}
	
        // print out the inputs
        cout << "Inputs:" << endl;
       
		cout << "A = " << "  ";
		for(i = N-1; i>=0 ; i--){
			cout << A[i];
		}
		cout << "  ";

		cout << "B = ";
		for(int i = N-1; i>=0 ; i--){
			cout << B[i];
		}

		cout << " ";

		cout << "O = ";
		for(int i = N-1; i>=0 ; i--){
			cout << O[i];
		}

		cout <<endl;


	}
  }
 
  void display() {
    cout << "Time\tA\tB\tO\n";

     // Combining signals for tracing
		sc_uint<1> a_sig, b_sig, o_sig;
	
		
		for (i = 0; i < N; i++) {
                a_sig[i] = A[i].read();
                b_sig[i] = B[i].read()/*.get_bit(0)*/;
                o_sig[i] = O[i].read()/*.get_bit(0)*/;
		
		}

		f = sc_create_vcd_trace_file("waves");

			
		// Trace combined signals
		sc_trace(f, a_sig, "a_sig");
	       	sc_trace(f, b_sig, "b_sig");
	       	sc_trace(f, o_sig, "o_sig");



    for (int i = 0; i < 3; i++) {
      cout << sc_time_stamp() << "\t" << A << "\t" << B << "\t" << O << endl;
      wait(1, SC_NS);
    }
  }


              /* // Combining signals for tracing
		sc_uint<N> a_sig, b_sig, o_sig;
	
		
		for (i = 0; i < N; i++) {
                a_sig[i] = A[i].read().get_bit(0);
                b_sig[i] = B[i].read().get_bit(0);
                o_sig[i] = O[i].read().get_bit(0);
		
		}

		f = sc_create_vcd_trace_file("waves");

			
		// Trace combined signals
		sc_trace(f, a_sig, "a_sig");
	       	sc_trace(f, b_sig, "b_sig");
	       	sc_trace(f, o_sig, "o_sig");*/




  SC_CTOR(Stimulation) /*: mul("mul")*/ {
   /* mul.A(A);
    mul.B(B);
    mul.O(O);*/

    SC_THREAD(stim);
    SC_THREAD(display);
  }

  ~Stimulation(){
	    sc_close_vcd_trace_file(f);
	    	    
    }

};


