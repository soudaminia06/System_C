/*#include <systemc.h>
#include "full_adder.cpp"

// n-bit multiplier module
SC_MODULE(n_bit_multiplier) {
  sc_in<sc_uint<N>> A;
  sc_in<sc_uint<N>> B;
  sc_out<sc_uint<64>> O;

  full_adder* fa[N][N];

  SC_HAS_PROCESS(n_bit_multiplier);
 // SC_CTOR(n_bit_multiplier)


  n_bit_multiplier(sc_module_name name) : sc_module(name)
  {
    // Initialize output to 0
    O.write(0);

    // Loop through each bit of B
    for (int i=0; i<N; i++) {
      // Loop through each bit of A
      for (int j=0; j<N; j++) {
        // Use full_adder module to add temp1 values
        fa[i][j] = new full_adder("fa");
       //  sc_dt::sc_uint<1> data = (A.read() >> j) & 1;
     //    fa[i][j]->A(data);
       
	
        fa[i][j]->A((A.read() >> j) & 1);
        fa[i][j]->B((B.read() >> i) & 1);
        fa[i][j]->cin((j == 0) ? 0 : fa[i][j-1]->cout);
        fa[i][j]->sum(O[i+j]);
        fa[i][j]->cout(fa[i+1][j]->A);
      }
    }
  }
};*/





/*#include "systemc.h"
#include "const.h"//constant file which acts A parameter.
#include "full_adder.h" 
 
// Multiplier module
SC_MODULE(MUL) {
     // input ports
    sc_in<sc_uint<M>> A;
    sc_in<sc_uint<M>> B;

   //output ports 
    sc_out<sc_uint<N>> O;


  // Temporary arrays to store temp1 values
  sc_signal<sc_uint<M> > temp1[M];
  sc_signal<sc_uint<N> > carry[M];
  sc_signal<sc_uint<N> > temp3[M];

  full_adder* fa[N];*/

/*SC_CTOR(MUL) {
    // Initialize the first bit of the temp1 values
    if (B.read()== 0b0) {
        temp1[0] = A.read();
         carry[0] = temp1[0];
    } else {
        temp1[0] = 0;
    }
 //   carry[0] = temp1[0] << 0;
    temp3[0] = carry[0];

    // Loop through each bit of B
    for (int i=1; i<=N-1; i++) {
        // Calculate temp1 values based on the current bit of B
        if (B.read()== i) {
            temp1[i] = A.read();
	    // carry[i] = temp1[i] 
        } else {
            temp1[i] = 0;
        }
        //carry[i] = temp1[i] << i;
	
            carry[i] = temp1[i];
             for(int j = 0; j < i; j++) {
             carry[i] = carry[i] * 2;
               }*/
	





/*SC_CTOR(MUL) {
    // Initialize the first bit of the temp1 values
    if (B.read() == 0b0) {
        temp1[0] = A.read();
        carry[0] = temp1[0];
    } else {
        temp1[0] = 0;
        carry[0] = 0;
    }
    temp3[0] = carry[0];

    // Loop through each bit of B
    for (int i = 1; i <= N-1; i++) {
        // Calculate temp1 values based on the current bit of B
        if (B.read() == i) {
            temp1[i] = A.read();
        } else {
            temp1[i] = 0;
        }
        carry[i] = 0;
        for (int j = 0; j < i; j++) {
            carry[i] = carry[i] | (temp1[i-j] & 0x1) << j;
            temp1[i-j] >>= 1;
        }
    }
}
  


        // Use full_adder module to add temp1 values
       // full_adder* fa = new full_adder("fa");
	for (int i = 0; i < M; i++) {
            fa[i] = new full_adder(sc_gen_unique_name("fa"));

        fa->A[i](temp3[i-1]);
        fa->B[i](carry[i]);
        fa->O[i](temp3[i]);
	}
    }

    // Assign final output to the last element of temp3
    O = temp3[N-1];

}
};*/



/*#include "systemc.h"
#include "const.h"
#include "full_adder.h"

// Multiplier module
SC_MODULE(MUL) {
    // input ports
    sc_in<sc_uint<N>> A;
    sc_in<sc_uint<N>> B;

    // output port
    sc_out<sc_uint<M>> O;

    // Temporary arrays to store temp1 values
    sc_signal<sc_uint<M>> temp1[N];
    sc_signal<sc_uint<M>> carry[N];
    sc_signal<sc_uint<M>> temp3[N];

    full_adder* fa[N];

    SC_CTOR(MUL) {
        // Initialize the first bit of the temp1 values
        if (B.read()[0] == 0b1) {
            temp1[0] = A.read();
        } else {
            temp1[0] = 0;
        }
        carry[0] = temp1[0];

        for (int i = 1; i < N; i++) {
            // Calculate temp1 values based on the current bit of B
            if (B.read()[i] == 0b1) {
                temp1[i] = A.read();
            } else {
                temp1[i] = 0;
            }

            // Compute carry[i] = temp1[i] << i using A for loop
            for (int j = 0; j < i; j++) {
                carry[j] = 0b0;
            }
            for (int j = i; j < M; j++) {
                carry[i][j] = temp1[i][j-i];
            }

            // Use full_adder module to add temp1 values
            fa[i] = new full_adder(sc_gen_unique_name("fa"));
            fa[i]->A(temp3[i-1]);
            fa[i]->B(carry[i]);
            fa[i]->O(temp3[i]);
        }

        // Assign final output to the last element of temp3
        O = temp3[N-1];
    }
};*/



#include "systemc.h"
#include "half_adder.h"
#include "const.h" //constant file which acts as A parameter

SC_MODULE(NBitMultiplier) {
    // Input ports
    sc_in<sc_uint<1>> A[N];
    sc_in<sc_uint<1>> B[N];

    // Output ports
    sc_out<sc_uint<1>> O[2*N];

    // Internal signals
    sc_signal<sc_uint<1>> temp1[N];
    sc_signal<sc_uint<1>> carry[N];

    // Half adder modules
    HalfAdder* adder[N];

    SC_CTOR(NBitMultiplier) {
        // Instantiating half adder modules for each pair of bits
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int index = i * N + j;
                adder[index] = new HalfAdder(sc_gen_unique_name("adder"));
                adder[index]->a(A[i]);
                adder[index]->b(B[j]);
                adder[index]->sum(temp1[index]);
                //adder[index]->sum(temp1.read()[index]);
       		

                // Connecting carry signals
                if (j == 0b0) {
                    adder[index]->carry(carry[i]);
                } else {
                    adder[index]->carry(carry[i + j]);
                }
            }
        }

        // Generating the final output
        for (int i = 0; i < 2*N; i++) {
            O[i].write(0); // initialises all bits to 0

            for (int j = 0; j < N*N; j++) {
                if (j / N + j % N == i) {
                    O[i].write( O[i].read() ^ temp1[j].read());
                }
            }
        }
    }
};

/*#include "systemc.h"
#include "half_adder.h"
#include "const.h" //constant file which acts as A parameter

SC_MODULE(NBitMultiplier) {
    sc_in<sc_uint<N>> A;
    sc_in<sc_uint<N>> B;
    sc_out<sc_uint<2*N>> O;

    // internal signals
    sc_signal<sc_uint<2*N>> temp;

    // half adder module
    HalfAdder* ha[N*N];

    SC_CTOR(NBitMultiplier) {
        // instantiating for N*N half adder modules
        for (int i = 0; i < N*N; i++) {
            ha[i] = new HalfAdder(sc_gen_unique_name("ha"));
            int j = i / N;      
            int k = i % N;      
            ha[i]->a(A[j]);
            ha[i]->b(B[k]);
            ha[i]->sum(temp[i]);
            ha[i]->carry(temp[i+1]);
        }

        // Generating the final output
        for (int i = 0; i < 2*N; i++) {
            O[i] = SC_LOGIC_0; // initialize all bits to 0

            for (int j = 0; j < N*N; j++) {
                if (j / N + j % N == i) {
                    O[i] = O[i] ^ temp[j];
                }
            }
        }
    }
};*/


  

