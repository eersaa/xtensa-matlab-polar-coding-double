#include "pencode_core.h"

void run(bool data_in[block_length], bool data_out[block_length])
{
    BLOCK_COPY:for (int i = 0; i < block_length; i++)
    {
        data_out[i] = data_in[i];
    }

    TOP_STAGES:for (int i = 0; i < stages; i++) // Which stage
    {
        int B = 1 << (stages-(i+1)+1);
        int nB = 1 << ((i+1)-1);

        BATCH_NUM:for (int j = 0; j < nB; j++) // Controls which batch of XOR operations is ongoing withing stage.
        {
            int base = ((j+1)-1)*B;
            BATCH_ITERATOR:for (int l = 0; l < (B >> 1); l++) // Iterate over the batch
            {
                data_out[base+l] = data_out[base+l] ^ data_out[base + (B>>1) + l];
            }
            
        }
        
    }
}
