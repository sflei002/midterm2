
//define local variable(s) here.  Use static keyword to keep local, e.g:
//   static int i;  // defines a local int named i



/*complete the state machine*/

void Detect_ZC()
{  B2 = PORTB & 0x04;
    switch(detect_zc_state)
    {
        case DZCInit:
		detect_zc_state = B2is1;
            break;
	case B2is1:
	    break;
        default:
            detect_zc_state = DZCInit;
            break;
    }
    switch(detect_zc_state)
    {
        case DZCInit:
            break;
	case B2is1:
	    B2 = 1;
            break;
        default:
            break;
    }
}
