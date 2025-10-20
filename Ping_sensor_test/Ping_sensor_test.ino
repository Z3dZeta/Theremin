
int main(void) {

  DDRD &= ~(1 << PD7);  // Echo pin as Input
  PORTD |= (1 << PD7);  // Echo pin pull-up High

  DDRB |= (1 << PB0);  // Trig pin as output

  uint16_t pingTimeStart = 0;
  uint16_t pingTimeEnd = 0;

  typedef enum {
    trig_on,
    trig_off,
    echo
  } State;

  State currentState = trig_off;

  while (1) {

/*
--- TO DO ---
Add timer1 for measuring time between trig and echo
Add logic for measuring distance
Probably more shit I can't think off
*/
    // Switch cases for the ping sensor
    switch (currentState) {
      case trig_on:
        PORTB |= (1 << PB1);  // trigger high
        currentState = trig_off;
        pingTimeStart = 0; //Placeholders for the timers
        break;

      case trig_off:
        if ((PINB & (1 << PB1)) != 0) {  // check input
          PORTB & ~(1 << PB1);           // Trigger off
          currentState = echo;        
          break;
        }


        printf("%u\n", pingTimeEnd - pingTimeStart); //check statement REMOVE
        break;

      case echo:
        if ((PINB & (1 << PB0))) {
          pingTimeEnd = 0;
        }
        break;
    }
  }

  return 0;
}
