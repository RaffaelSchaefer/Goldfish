
# Goldfish 🐠

A simple C++ library for unit testing

## Features

- Check for duplicates.
- Check if two pointer are pointing to the same variable.
- Check if the value is the same as the expected ones.

## Installation

Just include the Goldfish header file in your project

```c++
# include "libGoldfish.h"
```

## Usage/Examples

### Exsample 1

```c++
# include "libGoldfish.h"

int main() {
    int i = 5;
    Goldfish::toEqual("The Variable i equals 5: ", i, 5);
    return 0;
}
```

### Exsample 2

```c++
# include <string>
# include "libGoldfish.h"

int main() {
    std::string s = "Lore ipsum";
    Goldfish::toEqualString("The Variable s equals 'Lore ipsum': ", s, "Lore ipsum");
    return 0;
}
```

### Exsample 3

```c++
# include "libGoldfish.h"

int main() {
    int i = 2022;
    int *foo = &i;
    int *bar = foo;
    Goldfish::toBe("Foo is the same as bar", foo, bar);
    return 0;
}
```

## Documentation

[Documentation](https://github.com/RaffaelSchaefer/Goldfish/wiki)

## Authors

- [Raffael E. Schäfer](https://https://github.com/RaffaelSchaefer)
