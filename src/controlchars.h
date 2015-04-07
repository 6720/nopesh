#ifndef CONTROLCHARS_H
#define CONTROLCHARS_H

/**
 * List of control characters taken from console_codes(4).
 */

/**
 * ^C. Not much more to say.
 */
#define CONTROL_ETX 0x03

/*
 * Bell (^G). Supposed to beep.
 */
#define CONTROL_BEL 0x07

/**
 * Backspace (^H). Backspaces one column, but not past the beginning of the 
 * line.
 */
#define CONTROL_BS 0x08

/**
 * ??? (^I). Goes to the next tab stop or to the end of the line, if there is 
 * no earlier tab stop.
 */
#define CONTROL_HT 0x09

/**
 * Linefeed (^J). Gives a linefeed. If LF/NL (newline mode), also give a 
 * carriage return.
 */
#define CONTROL_LF 0x0A

/**
 * Linefeed (^K). Gives a linefeed. If LF/NL (newline mode), also give a 
 * carriage return.
 */
#define CONTROL_VT 0x0B

/**
 * Linefeed (^L). Gives a linefeed. If LF/NL (newline mode), also give a 
 * carriage return.
 */
#define CONTROL_FF 0x0C

/**
 * Carriage return (^M). Gives a carriage return.
 */
#define CONTROL_CR 0x0D

/**
 * ??? (^N). Activates the G1 character set.
 */
#define CONTROL_SO 0x0E

/**
 * ??? (^O). Activates the G0 character set.
 */
#define CONTROL_SI 0x0F

/**
 * ??? (^X). Interrupts escape sequences.
 */
#define CONTROL_CAN 0x18

/**
 * ??? (^Z). Interrupts escape sequences.
 */
#define CONTROL_SUB 0x1A

/**
 * Escape (^[). Starts an escape sequence
 */
#define CONTROL_ESC 0x1B

/**
 * Delete (none). Ignored.
 */
#define CONTROL_DEL 0x7F

/**
 * ??? (none). Equivalent to `ESC ['.
 */
#define CONTROL_CSI 0x9B

#endif /* CONTROLCHARS_H */
