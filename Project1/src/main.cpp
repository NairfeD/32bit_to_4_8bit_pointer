#include <Arduino.h>
#include <ESP8266WiFi.h>

#define SIZE_OF_ARRAY (4)

uint8_t* int_to_array(uint32_t big_int);
typedef uint8_t* (*tpdf_i_t_a) (uint32_t);

void setup() {
    // put your setup code here, to run once:

    //example use case
    uint32_t val32b = 0x12345678;
    uint8_t* pArray;
    uint8_t Revert = 0;

    tpdf_i_t_a NewFunc = int_to_array;
    pArray = NewFunc(val32b);
    Revert = *pArray | *(pArray+1) << 8 | *(pArray +2) << 16 | *(pArray+3) << 24;
}

void loop() {
    // put your main code here, to run repeatedly:
}

//requested function
uint8_t* int_to_array(uint32_t big_int){
    uint8_t sfArr[SIZE_OF_ARRAY]; //Shifting array 32bit to 4 8bit
    uint8_t* small_int = sfArr;

    //little endian shifting
    sfArr[0] = big_int;
    sfArr[1] = big_int >> 8;
    sfArr[2] = big_int >> 16;
    sfArr[3] = big_int >> 24;

    return(small_int);
}