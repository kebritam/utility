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

```
const int ten = 10;
const std::string str("string test");
kbt::Either<std::string, int> either1(10);
kbt::Either<std::string, int> either2(ten);
kbt::Either<std::string, int> either3("string test");
kbt::Either<std::string, int> either4(str);

/* With no return value */
either1.Match(
	[](const std::string& _str) { std::cout << "the string: " << _str << std::endl; },
	[](const int _number) { std::cout << "the number: " << _number << std::endl; });
either2.Match(
	[](const std::string& _str) { std::cout << "the string: " << _str << std::endl; },
	[](const int _number) { std::cout << "the number: " << _number << std::endl; });
either3.Match(
	[](const std::string& _str) { std::cout << "the string: " << _str << std::endl; },
	[](const int _number) { std::cout << "the number: " << _number << std::endl; });
either4.Match(
	[](const std::string& _str) { std::cout << "the string: " << _str << std::endl; },
	[](const int _number) { std::cout << "the number: " << _number << std::endl; });

/* With return value */
int res1 = either1.Match<int>(
	[](const std::string& _str) { std::cout << "the string: " << _str << std::endl; return 1; },
	[](const int _number) { std::cout << "the number: " << _number << std::endl; return 2; });
std::string res2 = either2.Match<std::string>(
	[](const std::string& _str) { std::cout << "the string: " << _str << std::endl; return "ret1"; },
	[](const int _number) { std::cout << "the number: " << _number << std::endl; return "ret2"; });
double res3 = either3.Match<double>(
	[](const std::string& _str) { std::cout << "the string: " << _str << std::endl; return 1.; },
	[](const int _number) { std::cout << "the number: " << _number << std::endl; return 2.; });
bool res4 = either4.Match<bool>(
	[](const std::string& _str) { std::cout << "the string: " << _str << std::endl; return true; },
	[](const int _number) { std::cout << "the number: " << _number << std::endl; return false; });

```

## Contributing

1. Fork it (<https://github.com/kebritam/utility>)
2. Create your feature branch (`git checkout -b feature/featureName`)
3. Commit your changes (`git commit -am 'Add your commit message'`)
4. Push to the branch (`git push origin feature/featureName`)
5. Create a new Pull Request
