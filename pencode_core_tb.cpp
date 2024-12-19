#include "pencode_core.h"

#include <iostream>
#include <fstream>

void print_outputs(int i, bool data_out, bool data_ref)
{
    printf("Bit index %d, out: %d ref: %d", i, data_out, data_ref);
}

int main(int argc, char *argv[])
{
    bool data_in[block_length] = {
    		#include "input.txt"
    		};
    bool data_out[block_length];
    bool data_ref[block_length] = {
    		#include "reference_output.txt"
    		};

    run(data_in, data_out);

    bool mismatch = false;
    for (int i = 0; i < block_length; i++)
    {
        if (data_out[i] != data_ref[i])
        {
            print_outputs(i, data_out[i], data_ref[i]);
			printf(" mismatch\n");
            mismatch = true;
        }
        else
        {
            print_outputs(i, data_out[i], data_ref[i]);
        	printf("\n");
        }
    }
    
    if (mismatch)
    {
        printf("Test failed");
        return -1;
    }
    else
    {
        printf("Test passed");
        return 0;
    }
}


