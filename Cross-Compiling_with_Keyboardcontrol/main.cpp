#include "keyboardControl.h"
#include <fstream>
#include <vector>




int main(){
	gpioInitialise();
    KeyboardControl con;
    //pid_test();
    con.Communicate();
    gpioTerminate();
    
    
    return 0;
}
