//
//
// yuval.c -- Password Check Device, 115200 baud FTDI
// Based on "Hello World" Ny Neil Gershenfeld
//
// set lfuse to 0x5E for 20 MHz xtal
//
// Yuval Gonczarowski
// 10/20/2016
//
// (c) Massachusetts Institute of Technology 2010
// This work may be reproduced, modified, distributed,
// performed, and displayed for any purpose. Copyright is
// retained and must be preserved. The work is provided
// as is; no warranty is provided, and users accept all 
// liability.
//

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>

#define output(directions,pin) (directions |= pin) // set port direction for output
#define set(port,pin) (port |= pin) // set port pin
#define clear(port,pin) (port &= (~pin)) // clear port pin
#define pin_test(pins,pin) (pins & pin) // test for port pin
#define bit_test(byte,bit) (byte & (1 << bit)) // test for bit set
#define bit_delay_time 8.5 // bit delay for 115200 with overhead
#define bit_delay() _delay_us(bit_delay_time) // RS232 bit delay
#define half_bit_delay() _delay_us(bit_delay_time/2) // RS232 half bit delay
#define char_delay() _delay_ms(10) // char delay
#define button_pressed() (!(PINA >> 7))
#define led_active() ((PINA >> 3) & 1)

#define serial_port PORTA
#define led_port PORTA
#define serial_direction DDRA
#define led_direction DDRA
#define serial_pins PINA
#define serial_pin_in (1 << PA0)
#define serial_pin_out (1 << PA1)
#define led_out (1 << PA3)

#define max_buffer 10
volatile char buffer[max_buffer] = {0};
volatile unsigned int len;

// functions
void set_button_interrupt();
void get_char(volatile unsigned char *pins, unsigned char pin, char *rxbyte);
void put_char(volatile unsigned char *port, unsigned char pin, char txchar);
void put_string(volatile unsigned char *port, unsigned char pin, char *str);
ISR(PCINT0_vect);
void newline();

void newline() {
   put_char(&serial_port, serial_pin_out, '\n');
   put_char(&serial_port, serial_pin_out, '\r');
}
void set_button_interrupt()
{
   //PA7 = PCINT7
   // Set GIMSK pin PCIE0 to high to enable PCINT[7:0]
   set(GIMSK, 1 << PCIE0);
   set(PCMSK0, 1 << PCINT7);
   sei();
}

void get_char(volatile unsigned char *pins, unsigned char pin, char *rxbyte) {
   //
   // read character into rxbyte on pins pin
   //    assumes line driver (inverts bits)
   //
   *rxbyte = 0;
   while (pin_test(*pins,pin))
      //
      // wait for start bit
      //
      ;
   //
   // delay to middle of first data bit
   //
   half_bit_delay();
   bit_delay();
   //
   // unrolled loop to read data bits
   //
   if pin_test(*pins,pin)
      *rxbyte |= (1 << 0);
   else
      *rxbyte |= (0 << 0);
   bit_delay();
   if pin_test(*pins,pin)
      *rxbyte |= (1 << 1);
   else
      *rxbyte |= (0 << 1);
   bit_delay();
   if pin_test(*pins,pin)
      *rxbyte |= (1 << 2);
   else
      *rxbyte |= (0 << 2);
   bit_delay();
   if pin_test(*pins,pin)
      *rxbyte |= (1 << 3);
   else
      *rxbyte |= (0 << 3);
   bit_delay();
   if pin_test(*pins,pin)
      *rxbyte |= (1 << 4);
   else
      *rxbyte |= (0 << 4);
   bit_delay();
   if pin_test(*pins,pin)
      *rxbyte |= (1 << 5);
   else
      *rxbyte |= (0 << 5);
   bit_delay();
   if pin_test(*pins,pin)
      *rxbyte |= (1 << 6);
   else
      *rxbyte |= (0 << 6);
   bit_delay();
   if pin_test(*pins,pin)
      *rxbyte |= (1 << 7);
   else
      *rxbyte |= (0 << 7);
   //
   // wait for stop bit
   //
   bit_delay();
   half_bit_delay();
   }

void put_char(volatile unsigned char *port, unsigned char pin, char txchar) {
   //
   // send character in txchar on port pin
   //    assumes line driver (inverts bits)
   //
   // start bit
   //
   clear(*port,pin);
   bit_delay();
   //
   // unrolled loop to write data bits
   //
   if bit_test(txchar,0)
      set(*port,pin);
   else
      clear(*port,pin);
   bit_delay();
   if bit_test(txchar,1)
      set(*port,pin);
   else
      clear(*port,pin);
   bit_delay();
   if bit_test(txchar,2)
      set(*port,pin);
   else
      clear(*port,pin);
   bit_delay();
   if bit_test(txchar,3)
      set(*port,pin);
   else
      clear(*port,pin);
   bit_delay();
   if bit_test(txchar,4)
      set(*port,pin);
   else
      clear(*port,pin);
   bit_delay();
   if bit_test(txchar,5)
      set(*port,pin);
   else
      clear(*port,pin);
   bit_delay();
   if bit_test(txchar,6)
      set(*port,pin);
   else
      clear(*port,pin);
   bit_delay();
   if bit_test(txchar,7)
      set(*port,pin);
   else
      clear(*port,pin);
   bit_delay();
   //
   // stop bit
   //
   set(*port,pin);
   bit_delay();
   //
   // char delay
   //
   bit_delay();
   }

void print_buffer() {
   put_string(&serial_port, serial_pin_out, (char*)buffer);
}

void put_string(volatile unsigned char *port, unsigned char pin, char *str) {
   //
   // print a null-terminated string
   //
   static int index;
   index = 0;
   do {
      put_char(port, pin, str[index]);
      ++index;
      } while (str[index] != 0);
   }
ISR(PCINT0_vect) {
   //
   // pin change interrupt handler
   //
   static char chr;
   if (!button_pressed()) { // avoid interrupt on both push and release
       set_button_interrupt();
       return;
   } 
   put_string(&serial_port, serial_pin_out, "Setup!");
   newline();
   chr = '0';
   len = 0;
   while(1)
   {
       get_char(&serial_pins, serial_pin_in, &chr);
       if (chr == '\n') {
            buffer[len++]='\0';
            break;
       }
// Avoid non-letter characters, convert uppercase to lowercase
       if ((chr >= 'A') && (chr <= 'Z')) {
            chr = chr - 'A' + 'a';
       }
       if ((chr < 'a') || (chr > 'z')) {
            continue;
       }
       buffer[len++] = chr;
       if (len == (max_buffer-1))
            len = 0;
   }
   put_string(&serial_port, serial_pin_out, "Complete.");
   newline();
   set_button_interrupt();
}

int main(void) {
   //
   // main
   //
   static char chr;
   static int i;
   static int flag;
   //
   // set clock divider to /1
   //
   CLKPR = (1 << CLKPCE);
   CLKPR = (0 << CLKPS3) | (0 << CLKPS2) | (0 << CLKPS1) | (0 << CLKPS0);
   //
   // initialize output pins
   //
   set(serial_port, serial_pin_out);
   clear(led_port, led_out);
   output(serial_direction, serial_pin_out);
   output(led_direction, led_out);

   set_button_interrupt();

   // main loop
   while (1) {
      get_char(&serial_pins, serial_pin_in, &chr);
      put_string(&serial_port, serial_pin_out, "Password?");
      newline();
      for (i=0, flag=0;i<len-1;++i)
      {
        get_char(&serial_pins, serial_pin_in, &chr);
        if (chr != buffer[i])
        {
            put_string(&serial_port, serial_pin_out, "Wrong");
            clear(led_port,led_out);
            newline();
            flag=1;
            break;
        }
      }
      if (flag) continue;
      put_string(&serial_port, serial_pin_out, "PASS! ");
      print_buffer();
      newline();
      set(led_port,led_out);
      }
}



