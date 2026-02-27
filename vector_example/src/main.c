#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "./asm/avx/avx.h"

#include "./vector/vector.h"
#include "./vector/vector_math.h"

int main(){

    /* Basic vector operations */
    s_vector* vector_ptr = vector_new(sizeof(uint8_t), u8, 1);

    uint8_t test_data[] = {
        0xff, 0x00, 0x90, 0x01
    };

    vector_push(vector_ptr, &test_data[0]);      
    vector_push(vector_ptr, &test_data[1]);    
    vector_push(vector_ptr, &test_data[2]);    
    vector_push(vector_ptr, &test_data[3]);                

    vector_insert(vector_ptr, &test_data[0], 2);

    if(vector_empty(vector_ptr) == false){
        printf("Vector size: %lu\n",vector_size(vector_ptr));
    }

    vector_erase(vector_ptr, 1);            

    uint8_t test_ptr;
    vector_pop(vector_ptr, (void*) &test_ptr);   
    vector_pop(vector_ptr, (void*) &test_ptr);   
    vector_pop(vector_ptr, (void*) &test_ptr);   
    vector_pop(vector_ptr, (void*) &test_ptr);   

    
    vector_delete(vector_ptr);

    /* Sum of vectors */

    s_vector* vector_a = vector_new(sizeof(float), f32, 32);
    s_vector* vector_b = vector_new(sizeof(float), f32, 32);
    s_vector* vector_result = vector_new(sizeof(float), f32, 64);

    for(uint8_t index =0; index < 32; index++){
        float x = 0.1f;

        vector_push(vector_a, &x);
        vector_push(vector_b, &x);
    }

    vector_add(vector_a, vector_b, vector_result);

    vector_delete(vector_a);
    vector_delete(vector_b);
    vector_delete(vector_result);

    return 1;
}