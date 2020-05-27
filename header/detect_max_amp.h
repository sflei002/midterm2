
//define local variable(s) here.  Use static keyword to keep local, e.g:
//   static int i;  // defines a local int named i

/* complete the state machine. */
static unsigned char i;
static unsigned char tmp;
void Detect_Max_Amp()
{ max_amp = 0x00;
    switch(detect_max_amp_state)
    {
        case DMAInit:
	    detect_max_amp_state = awaitlow;
	    i = 0;
            break;
        case awaitlow:
            if((~PINA & 0xF8) == 0x00){
                detect_max_amp_state = awaitlow;
            }
            else if((~PINA & 0xF8) > 0x00){
                detect_max_amp_state = ahigh;
            }
            break;
        case ahigh:
            if((~PINA & 0xF8) > 0x00){
                detect_max_amp_state = ahigh;
		tmp = (~PINA & 0xF8);
            }
            else if((~PINA & 0xF8) == 0x00){
                detect_max_amp_state = alow;
                i = 0;
            }
            break;
        case alow:
            if(((~PINA & 0xF8) == 0x00) && (i <= 10)){
                detect_max_amp_state = alow;
            }
            else if(((~PINA & 0xF8) == 0x00) && (i > 10)){
                detect_max_amp_state = awaitlow;
                i = 0;
            }
            else if((~PINA & 0xF8) > 0x00){
                detect_max_amp_state = ahigh;
		i = 0;
            }
            break;
        default:
            break;
    }
    switch(detect_max_amp_state)
    {
        case DMAInit:
            break;
	case awaitlow:
         
            break;
        case ahigh:
            if(tmp > max_amp){
		max_amp = tmp;
	    }
            break;
        case alow:
            ++i;
            break;
        default:
            break;
    }
}
