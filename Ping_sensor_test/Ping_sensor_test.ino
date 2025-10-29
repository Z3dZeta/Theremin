
int main(void) {

  DDRD &= ~(1 << PD7);  // Echo pin as Input
  PORTD |= (1 << PD7);  // Echo pin pull-up High

  DDRB |= (1 << PB0);  // Trig pin as output

  //Set up timer on default mode
  TCCR1A = 0;
  TCCR1B = (1 << WGM12) | (1 << CS11) | (1 << CS10);
  OCR1A = 39999;  // Compare value

  TCCR1B |= (1 << CS11);   //Prescaler on 8
  TIMSK1 |= (1 << TOIE1);  //Enable overflow interrupt

  uint16_t pingTimeStart;
  uint16_t pingTimeEnd;

  typedef enum {
    trig_on,
    trig_off,
    echo
  } State;

  State currentState = trig_off;

  sei();

  /*
--- TO DO ---
Add logic for measuring distance

How to make it so the ping sensor gets controlled by the timer1 > probably not with switch cases
  > Should be using interrupts, interrupt needs to trigger the trig pin

Probably more shit I can't think off
*/

  while (1) {
    // Switch cases for the ping sensor
    switch (currentState) {
      case trig_on:
        PORTB |= (1 << PB1);  // trigger high
        currentState = trig_off;
        pingTimeStart = TCNT1;
        break;

      case trig_off:
        if ((PINB & (1 << PB1)) != 0) {  // check input
          PORTB & ~(1 << PB1);           // Trigger off
          currentState = echo;
          pingTimeEnd = TCNT1;
          break;
        }

        printf("%u\n", pingTimeEnd - pingTimeStart);  //check statement REMOVE

        break;

      case echo:
        if ((PINB & (1 << PB0))) {
        
        }
        break;
    }
  }

  return 0;
}
