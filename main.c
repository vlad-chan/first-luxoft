/* 
 * File:   main.c
 * Author: Chankov
 */

#include <stdio.h>

#define DATA    0xE000000F 
#define DATA1   0x00000E0F 
#define DATA2   0x00000000 
#define DATA3   0xFFFFFFFF

unsigned char Count_MSB(unsigned long t); 
unsigned char Count_LSB(unsigned long t); 
unsigned char Count_ones(unsigned long t); 
unsigned char Count_xor(unsigned long t);

int main(){ 
    printf("data: 0x%x => ", DATA);
    printf("begin: %u ", Count_MSB(DATA)); 
    printf("end: %u ", Count_LSB(DATA)); 
    printf("bits set: %u ", Count_ones(DATA));
    printf("bits xor: %u \n", Count_xor(DATA));
    
    return 0;
}

unsigned char Count_MSB(unsigned long t){
    unsigned long mask = 0x80000000; 
    unsigned char i = 0; 
    
    while(t & mask){ 
        i++; 
        mask = mask >> 1; 
    } 
    
    return i;
} 

unsigned char Count_LSB(unsigned long t){
    unsigned long mask = 0x01; 
    unsigned char i = 0; 
    
    while(t & mask){ 
        i++; 
        mask = mask << 1; 
    } 
    
    return i;
} 

unsigned char Count_ones(unsigned long t){
    unsigned long mask = 0x80000000; 
    unsigned char i = 0; 
    
    do{  
        if(t & mask){
            i++; 
        } 
        mask = mask >> 1;
    }
    while(mask != 0x00); 
    
    return i; 
} 

unsigned char Count_xor(unsigned long t){
    unsigned long tmp1, tmp2; 
    
    tmp1 = t & 0x01; 
    
    for(char i = 0; i < 32; i++){
        t = t >> 1; 
        tmp2 = t & 0x01; 
        
        tmp1 = tmp1 ^ tmp2; 
    } 
    
    return (unsigned char)tmp1;
} 
