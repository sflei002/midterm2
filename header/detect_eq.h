//define local variable(s) here.  Use static keyword to keep local, e.g:
//   static int i;  // defines a local int named i
static unsigned char i;
/*complete the state machine*/

void Detect_EQ()
{
	B1 = PORTB & 0x02;
    switch(detect_eq_state)
    {
        case DEQInit:
            i = 0;
	    B1 = 0;
	    detect_eq_state = waitlow;
            break;
	case waitlow:
	    if((~PINA & 0xF8) == 0x00){
		detect_eq_state = waitlow;
	    }
	    else if((~PINA & 0xF8) > 0x00){
                detect_eq_state = dhigh;
            }
	    break;
	case dhigh:
	    if((~PINA & 0xF8) > 0x00){
                detect_eq_state = dhigh;
            }
            else if((~PINA & 0xF8) == 0x00){
                detect_eq_state = dlow;
		i = 0;
            }
	    break;
	case dlow:
	    if(((~PINA & 0xF8) == 0x00) && (i <= 10)){
                detect_eq_state = dlow;
            }
            else if(((~PINA & 0xF8) == 0x00) && (i > 10)){
                detect_eq_state = waitlow;
                i = 0;
            }
	    else if((~PINA & 0xF8) > 0x00){
		detect_eq_state = dhigh;
		i = 0;
	    }
	    break;
        default:
            detect_eq_state = DEQInit;
            break;
    }
    switch(detect_eq_state)
    {
        case DEQInit:
            break;
	case waitlow:
	    B1 = 0;
            break;
        case dhigh:
	    B1 = 1;
            break;
        case dlow:
	    ++i;
            break;
        default:
            break;
    }
}
