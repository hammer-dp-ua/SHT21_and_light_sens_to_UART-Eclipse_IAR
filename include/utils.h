//#include "stdlib.h"
//#include "arm_math.h"
#include <stdlib.h>
#include <math.h>

#define MALLOC_ADDRESSES_SIZE 100

void set_flag(unsigned int *flags, unsigned int flag_value);
void reset_flag(unsigned int *flags, unsigned int flag_value);
unsigned char read_flag(unsigned int flags, unsigned int flag_value);
unsigned char contains_string(char being_compared_string[], char string_to_be_contained[]);
char *set_string_parameters(char string[], char *parameters[]);
unsigned short get_string_length(char string[]);
unsigned char is_string_starts_with(char long_string[], char short_string[]);
char *float_to_string(float number, unsigned char precise);
unsigned int powi(unsigned int x, unsigned char y);
char *num_to_string(int number);
unsigned int divide_by_10(unsigned int dividend);
unsigned char get_first_digit(unsigned int long_digit);
char *array_to_string(char array[], unsigned char array_length);
char *debug_malloc(unsigned int size, unsigned int invoked_function);
void debug_free(char *memory_location_to_free);
void add_debug_malloc_address(char *allocated_memory_location);
void remove_debug_malloc_address(char *freed_memory_location);
float my_atoff(char *float_string);
