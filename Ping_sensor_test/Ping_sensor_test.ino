//D7 = Echo pin > PD7 > Input
//D8 = Trig pin > PB0 > Output

  DDRC &= ~(1 << PD7);  //Echo pin als Input
  PORTC |= (1 << PD7);  //Echo pin pull-up High

  DDRC |= (1 << PB0); //Trig pin als output

  while (1){
    
  }


