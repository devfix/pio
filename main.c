#include "pio/pio.h"

#define LED PA0

int main() {
    dMode(LED, OUTPUT);
    dWrite(LED, HIGH);
    if(dRead(LED) == HIGH) {
        
    }
}
