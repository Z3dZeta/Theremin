//D7 = Echo pin > PD7 > Input
//D8 = Trig pin > PB0 > Output

DDRC &= ~(1 << PD7);  //Echo pin als Input
PORTC |= (1 << PD7);  //Echo pin pull-up High

DDRC |= (1 << PB0);  //Trig pin als output

typedef enum {
  trig_on,
  trig_off,
  echo_on,
}

State currentState = trig_off;

while (1) {

  switch (currentState){
    case trig_on:
      PINB |= (1 << PB6);
      currentState = trig_off;
  }

    case trig_off:
      if ((1 << PB5) == 1){
        currentState = echo_off;
      }
}
