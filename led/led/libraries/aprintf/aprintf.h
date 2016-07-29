/*
    This code should be pasted within the files where this function is needed.
    This function will not create any code conflicts.

    The function call is similar to printf: ardprintf("Test %d %s", 25,
   "string");

    To print the '%' character, use '%%'

    This code was first posted on http://arduino.stackexchange.com/a/201
*/

#ifndef ARDPRINTF
#define ARDPRINTF

#define ARDBUFFER \
  16  // Buffer for storing intermediate strings. Performance may vary depending
      // on size.

int ardprintf(char *str,
              ...);  // Variadic Function. Returns number of passed arguments.

#endif
