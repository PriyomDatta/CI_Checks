#include "../../Interface/inc/intf.hpp"

unsigned char getdata_1(void){
//Call function from other module
return 20;
}
int getdata_2(void){
//Call function from other module
return 1;
}
void getdata_3(int *data){
//Call function from other module
*data = 30;
}