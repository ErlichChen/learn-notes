# A tiny printf for embedded applications

[printf](http://www.sparetimelabs.com/tinyprintf/tinyprintf.php)

The library is only some 200 lines long and has a memory footprint of about 1.4kb. So you can propably use it in an 8 bit microcontroller with just some kilobytes of memory. And at 9600 bauds this code downloads in under two seconds, which is nice when debugging as my attention span seems to be rather short nowdays.

To use it, just download the two files and inlcude them in the make process of your project. In your source code #include "printf.h" and use the printf as you would use the stdio.h one. Of course being tiny, it has limitations, no floating point support and long support is optional, but the most usefull features in embedded development, printing chars, strings, decimal and hex, are supported.

Before you can use the printf you need to initialize the library by supplying it with a character output function. Typically printf calls putc function but I chose not to do it that way. As the idea is that the code is as much as possible independent of anything else I did not want to presume the existence of any header files nor did I want to just declare the putc function with extern and trust the library user to provide it and linker to find it. Instead you need to pass a pointer to your putc function yourself. See the header file for an example and the code for details.

The library actually implements functions tfp_printf and tfp_sprintf and declared two macros, printf and sprintf, that expand to the names of the library functions. Now, I know, this sort of non function style macro usage, especially with lower case names, can be evil. A better/cleaner solution would have been the use of variadic macros but for reasons lost in the dusk of history I did not. Feel free to modify either the macros or the function names.

To conserve space the library does not support printing long ints unless you define the macro PRINTF_LONG_SUPPORT. To support long the compiler will pull the 32 bit math libraries (assuming long is 32 bits here) and this will greatly increase the memory footprint. When debugging, especially when bringing up a board, space can be at premium, yet, if you are working with a 16/32 bit processor you may need to print 32 bit hex values. You can do that, without enablind the long support as follows:

```c
long v=0xDEADBEEF;
printf("v=%04X%04X\n", v >> 16, v & 0xffff); // actually the '& 0xffff' is propably superfluous if int is 16 bits
```

This should output:
v=DEADBEEF
Well, thats about all, just wanted to put this into the web so that if you need something like his you do not need to write it from scratch like I had to.