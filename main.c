/* 
 * File:   main.c
 * Author: Chankov 
 * Counting of "1" in 32 bit long number 
 */

#include <stdio.h>
#include "functions.h"

//input 32 bit long DATA 
#define DATA    0xE000000F 
#define DATA1   0x00000E0F 
#define DATA2   0x00000000 
#define DATA3   0xFFFFFFFF

int main(){ 
    printf("data: 0x%x => ", DATA); 
    printf("begin: %u ", Count_MSB(DATA));      //count "1" beginning from MSB 
    printf("end: %u ", Count_LSB(DATA));        //count "1" beginning from LSB 
    printf("bits set: %u ", Count_ones(DATA));  //count "1" in DATA 
    printf("bits xor: %u \n", Count_xor(DATA)); //xor all bits in DATA 
    
    return 0;
}
