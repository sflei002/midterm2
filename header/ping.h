
//define local variable(s) here.  Use static keyword to keep local, e.g:
//   static int i;  // defines a local int named 
static unsigned char i;

/*complete the state machine*/

void Ping()
{
	B0 = PORTB & 0x01;
    switch(ping_state)
    {
        case PInit:
	    i = 0;
	    ping_state = P_high;
            break;
	case P_high:
	    if(i <= 1){
		ping_state = P_high;
	    }
	    else if(i > 1){
                ping_state = P_low;
		i = 0;
            }
	    break;
	case P_low:
	    if(i <= 9){
                ping_state = P_low;
            }
            else if(i > 9){
                ping_state = P_high;
		i = 0;
            }
	    break;
        default:
            ping_state = PInit;
            break;
    }
    switch(ping_state)
    {
        case PInit:
            break;
	 case P_high:
	    B0 = 1;
	    ++i;
            break;
        case P_low:
	    B0 = 0;
	    ++i;
            break;
        default:
            break;
    }
}
