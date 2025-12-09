*This project has been created as part of the 42 curriculum by lgirard.*

## Description

The goal of this project is to recreate the `printf` function as `ft_printf`.

The mandatory part is to recreate the behavior of `printf` with variadic functions. Our function has to handle these conversions: `cspdiuxX%`. We do not have to implement the different flags.

The bonus part is to manage any combination of these flags: `-0. #+`.

## Instructions

This project is compiled with cc and `-Wall` `-Werror` `-Wextra` flags as a library: `libftprintf.a`.

There is a Makefile for the compilation with the following rules:

`all`: Compile and create the lib.

`libftprintf.a`: Compile and create the lib (equivalent to `make all`).

`clean`: Delete binary files (.o).

`fclean`: Delete binary files and the lib.

`re`: Delete binary files and the lib, then compile and create the lib (equivalent to `make fclean && make all`).

`libft`: Only compile the libft.

`bonus`: Compile and create the lib with bonuses included.

## Resources

I do not have the different resources used for this project because the README creation was requested after I finished the project (the subject has changed).

I used AI (lechat) to explain what the different flags do and their limits/exceptions and also Copilot to fix grammar and spelling erros in the README.
