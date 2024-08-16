#include "mbed.h"

DigitalOut myled(LED1);
Serial pc(USBTX, USBRX);  // The pin order has been corrected for USB serial communication.
Serial dev(PA_9, PA_10);

void dev_recv() {
    while(dev.readable()) {
        pc.putc(dev.getc());  // Missing semicolon added
    }    
}

void pc_recv() {
    while(pc.readable()) {
        dev.putc(pc.getc());  
    }    
}

int main() {
    pc.baud(9600);             
    dev.baud(115200);          // Corrected `device1` to `dev` and set the baud rate
    pc.attach(&pc_recv);       
    dev.attach(&dev_recv);     // Atach corrected to Attach & function name corrected to `dev_recv`
    pc.printf("Hello!! \r\n");
    
    while(1) {
        myled = 1;
        wait_us(1000000);      // Replaced wait with wait_us for the correct time delay
        myled = 0;
        wait_us(1000000);      // Replaced wait with wait_us for the correct time delay
    }
}