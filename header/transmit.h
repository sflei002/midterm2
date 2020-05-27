//define local variable(s) here.  Use static keyword to keep local, e.g:
//   static int i;  // defines a local int named i



/*complete the state machine*/

void Transmit()
{
    switch(transmit_state)
    {
        case TInit:
	    transmit_state = state1;
            break;
	case state1:
	    break;
        default:
            transmit_state = TInit;
            break;
    }
    switch(transmit_state)
    {
        case TInit:
            break;
	case state1:
	    PORTB = B0 | B1 | B2 | max_amp;
            break;
        default:
            break;
    }

}
