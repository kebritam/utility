# Utility
> A collection of utility tools for C++

This project implements a Collection of utility tools for C++ like: Defer scope guard, Either, Optional and etc.

## Installation

You can just transfer the header and source files to your project and start using them. Or you can build it into a library.

## Usage example
```c++
const int x = 10;
DEFER
{
	printf("defer number: 1\n");
	printf("captured value: %d\n", x);
};

DEFER
{
	printf("defer number: 2\n");
	printf("captured value: %d\n", x);
};

printf("something else\n");
```

## Contributing

1. Fork it (<https://github.com/kebritam/utility>)
2. Create your feature branch (`git checkout -b feature/featureName`)
3. Commit your changes (`git commit -am 'Add your commit message'`)
4. Push to the branch (`git push origin feature/featureName`)
5. Create a new Pull Request
