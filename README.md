# FOB

FOB is a work-in-progress compiler backend API for generating IR and assembly. It is written from scratch in C99 and doesn't use any third party libraries.

See my other project [FOF](https://github.com/notjoshki/fof.git) - an example C compiler that uses FOB for the backend.

## Supported Architectures

- Linux x86_64

## Usage

Simply copy and paste the ```fob/``` directory into your project and compile its C files alongside your own source files. You can then include any of the header files from the ```fob/``` directory that you need.

## License

FOB is distributed under the [BSD 3-Clause](./LICENSE) license.
