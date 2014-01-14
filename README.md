C Compiler
==========
By Eudis Duran
--------------

## Compiling

### Linux:

You can build the source with a single command.
Make sure you are in the root src directory, and 
type: "make all"  This will build both the compiler
and virtual machine.  The resulting executables will
be placed in the root binary folder for the project.
The programs are named "c" for the compiler, and "cvm" for 
the virtual machine.

### Example Programs/Tests
Once you have built the compiler and virtual machine, both
executables are also copied to the bin folder under 'examples.'
The example programs can be built in a similar fasion.
Change directory to examples/ and execute a "make"
call.  That will build all the examples for execution.
In this case however, the Makefile will use my C compiler
to build the examples, and will produce VM executables 
in the bin folder under the examples folders.

### Windows:
Not tested.  


## Usage:
To compile a source file, first make sure that it adheres
to the small C subset that is specified in the Documentation
file, as not all of C is implemented yet.

Once you have checked that off, locate the compiler and VM
executable in the bin directory and change to that directory
through the command line.  Assuming you have a test
file, say test.c, you could type in the following to compile
the file:

```bash
$ ./c test.c -o test.vm
```

That would compile the c source and produce a virtual machine
bytecode executable.  To run that exectuable, type in the
following:

```bash
$ ./cvm test.vm
```

That would execute the program.

You can display a help screen by typing in --help in either of the
program's command line arguments, like so:

```bash
$ ./c --help
```

or

```bash
$ ./cvm --help
```
