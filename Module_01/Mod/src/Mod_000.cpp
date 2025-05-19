#include"../../Interface/inc/intf.hpp"
#include"../inc/Mod_000.hpp"

//Implementation of the output interface functions
int putdata_1(void){
 return Implementation_1();
}
void putdata_2(int * data){
 Implementation_2(data); 
}
char putdata_3(void){
int i= Implementation_1();
return Implementation_3(i);
}

/*Own Module Implementation*/


// Implementation_1: Returns an integer after complex processing
int Implementation_1(void) {
    unsigned char data = getdata_1();
    int processed_data = 0;

    // Complex processing logic with switch cases
    switch (data % 4) {
        case 0:
            processed_data = data * 2;
            break;
        case 1:
            processed_data = data + 10;
            break;
        case 2:
            processed_data = data - 5;
            break;
        case 3:
            processed_data = data / 2;
            break;
        default:
            processed_data = data;
            break;
    }

    if (processed_data > 50) {
        if (processed_data % 2 == 0) {
            processed_data += 5;
        } else {
            processed_data -= 5;
        }
    }

    return processed_data;
}

// Implementation_2: Processes data passed by pointer and modifies it in place
void Implementation_2(int *data) {
    if (data == nullptr) {
        return; // Handle null pointer
    }

    // Retrieve input data using getdata_1 and getdata_2
    unsigned char input1 = getdata_1();
    int input2 = getdata_2();

    int value = *data;
    int processed_data = 0;

    // Loop to perform iterative processing
    for (int i = 0; i < 5; ++i) {
        if (value % 2 == 0) {
            processed_data += (value / 2) + input1; // Add half of the value and input1 if it's even
        } else {
            processed_data += (value * 3) - input2; // Add triple the value minus input2 if it's odd
        }

        // Modify value for the next iteration
        value -= 10;
        if (value <= 0) {
            break; // Exit the loop if value becomes non-positive
        }
    }

    // Additional processing after the loop
    if (processed_data > 100) {
        if (processed_data % 5 == 0) {
            processed_data /= 5;
        } else {
            processed_data *= 2;
        }
    } else {
        if (processed_data % 3 == 0) {
            processed_data += input1; // Add input1 if divisible by 3
        } else {
            processed_data -= input2; // Subtract input2 otherwise
        }
    }

    *data = processed_data; // Update the original data with the processed result
}

// Implementation_3: Takes an integer as input, processes it, and returns a character
char Implementation_3(int input) {
    int processed_data = 0;

    // Retrieve input data using getdata_2 and getdata_3
    int data_from_getdata_2 = getdata_2();
    int data_from_getdata_3 = 0;
    getdata_3(&data_from_getdata_3);

    // Combine input and retrieved data for processing
    int combined_data = input + data_from_getdata_2 + data_from_getdata_3;

    // Complex processing logic with switch cases
    switch (combined_data % 5) {
        case 0:
            processed_data = combined_data + 20;
            break;
        case 1:
            processed_data = combined_data - 15;
            break;
        case 2:
            processed_data = combined_data * 3;
            break;
        case 3:
            processed_data = combined_data / 2;
            break;
        case 4:
            processed_data = combined_data % 10;
            break;
        default:
            processed_data = combined_data;
            break;
    }

    // Additional processing based on processed_data
    if (processed_data > 200) {
        if (processed_data % 7 == 0) {
            processed_data /= 7;
        } else {
            processed_data -= 30;
        }
    }

    // Convert processed data to a character
    char result = static_cast<char>((processed_data % 26) + 'A'); // Map to A-Z
    return result;
}

//Dummy function