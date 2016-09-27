/* 
 * File:   functions.h
 * Author: Chankov 
 * Provide functions that counts "1" in 32 bit long number 
 */

//------------Count_MSB------------
// Number of continuous "1" beginning from MSB 
// Input: 32 bit long DATA input 
// Output: 0 .. 32, char (0 - if MSB =0)
unsigned char Count_MSB(unsigned long t);

//------------Count_LSB------------
// Number of continuous "1" beginning from LSB 
// Input: 32 bit long DATA input 
// Output: 0 .. 32, char (0 - if LSB =0)
unsigned char Count_LSB(unsigned long t); 

//------------Count_ones------------
// Number of "1" in DATA input 
// Input: 32 bit long DATA input 
// Output: 0 .. 32, char 
unsigned char Count_ones(unsigned long t);

//------------Count_xor------------
// Exclusive or of all bits in DATA input 
// Input: 32 bit long DATA input 
// Output: char, 0 - if number of "1" in DATA input is paired or =0
//               1 - if number of "1" in DATA input isn't paired 
unsigned char Count_xor(unsigned long t);
