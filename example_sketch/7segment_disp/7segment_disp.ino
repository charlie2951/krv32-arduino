#include "seven_seg.h"
void setup() {
  // put your setup code here, to run once:
  // Initialization: Show Booting
    ss_show_word(SS_WORD_NONE);
    delay(5000);

    // Loop through some hex values
    for (uint16_t i = 0; i < 0x100; i++) {
        ss_write_hex(i);
        delay(2000);
    }

    // Task Complete
    ss_show_word(SS_WORD_DONE);


}

void loop() {
  // put your main code here, to run repeatedly:

}
