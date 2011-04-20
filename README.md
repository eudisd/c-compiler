C Compiler
==========
By Eudis Duran
--------------

## Compiling

### Linux:

You can build the source with a single command.
Make sure you are in the root src directory, and 
type: "make"  This will build both the compiler
and virtual machine.  The resulting executables will
be placed in the root binary folder for the project.
The programs are named "c" for the compiler, and "cvm" for 
the virtual machine.

### Example Programs/Tests

The example programs can be built in a similar fasion.
Change directory to examples/ and execute a "make"
call.  That will build all the examples for execution.

### Windows:

Assuming you have visual C++, building the compiler is
only a matter of creating a project and adding the files
to that project and building.  The compiler is written in
ansi C, so it should work just fine (I have not tested it).

## Usage:

To compile a source file, first make sure that it adheres
to the small C subset that is specified in the Documentation
file, as not all of C is implemented yet.

Once you have checked that off, locate the compiler and VM
executable in the bin directory and change to that directory
through the command line.  Assuming you have a test
file, say test.c, you could type in the following to compile
the file:

$ ./c test.c -o test.vm

That would compile the c source and produce a a virtual machine
bytecode executable.  To run that exectuable, type in the
following:

$ ./cvm test.vm

That would execute the program.

You can display a help screen by typing in --help in either of the
program's command line arguments, like so:

$ ./c --help

or

$ ./cvm --help

