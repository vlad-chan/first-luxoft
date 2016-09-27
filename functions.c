/* 
 * File:   functions.c
 * Author: Chankov 
 * Provide functions that counts "1" in 32 bit long number 
 */ 

//------------Count_MSB------------
// Number of continuous "1" beginning from MSB 
// Input: 32 bit long DATA input 
// Output: 0 .. 32, char (0 - if MSB =0)
unsigned char Count_MSB(unsigned long t){
    unsigned long mask = 0x80000000; 
    unsigned char i = 0;
    
    while(t & mask){        //mask DATA to pick out MSB 
        i++;                //if MSB "1", increment counter 
        mask = mask >> 1;   //right shift mask to pick out next bit 
    } 
    
    return i;               //number of continuous "1"
} 

//------------Count_LSB------------
// Number of continuous "1" beginning from LSB 
// Input: 32 bit long DATA input 
// Output: 0 .. 32, char (0 - if LSB =0)
unsigned char Count_LSB(unsigned long t){
    unsigned long mask = 0x01; 
    unsigned char i = 0; 
    
    while(t & mask){        //mask DATA to pick out LSB 
        i++;                //if LSB "1", increment counter 
        mask = mask << 1;   //left shift mask to pick out next bit 
    } 
    
    return i;               //number of continuous "1"
} 

//------------Count_ones------------
// Number of "1" in DATA input 
// Input: 32 bit long DATA input 
// Output: 0 .. 32, char 
unsigned char Count_ones(unsigned long t){
    unsigned long mask = 0x80000000; 
    unsigned char i = 0; 
    
    do{                     //do 32 times
        if(t & mask){       //mask DATA to pick out MSB 
            i++;            //if bit "1", increment counter 
        } 
        mask = mask >> 1;   //right shift mask to pick out next bit 
    }
    while(mask != 0x00);    //mask =0 after 32 times of right shifting
    
    return i;               //number of "1"
} 

//------------Count_xor------------
// Exclusive or of all bits in DATA input 
// Input: 32 bit long DATA input 
// Output: char, 0 - if number of "1" in DATA input is paired or =0
//               1 - if number of "1" in DATA input isn't paired 
unsigned char Count_xor(unsigned long t){
    unsigned long tmp1, tmp2; 
    
    tmp1 = t & 0x01;                //pick out LSB from DATA 
    
    for(char i = 0; i < 32; i++){   //do 31 times 
        t = t >> 1;                 //right shift DATA to put next bit as LSB 
        tmp2 = t & 0x01;            //mask DATA to pick out LSB         
        tmp1 = tmp1 ^ tmp2;         //XOR next bit with previous 
    } 
    
    return (unsigned char)tmp1;     //result 
} 
