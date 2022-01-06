
# Goldfish 🐠

A simple C++ library for unit testing.

## Features

- Check for duplicates.
- Check if two pointer are pointing to the same variable.
- Check if the value is the same as the expected ones.

## Installation

Just include the Goldfish header file in your project.

```c++
# include "libGoldfish.h"
```

## Usage/Examples

### Example 1

```c++
#include "libGoldfish.h"

int main() {
    int i = 5;
    Goldfish::toEqual("The Variable i equals 5: ", i, 5);
    return 0;
}
```

### Example 2

```c++
#include <string>
#include "libGoldfish.h"

int main() {
    std::string s = "Lore ipsum";
    Goldfish::toMatch("The Variable s equals 'Lore ipsum': ", s, "Lore ipsum");
    return 0;
}
```

### Example 3

```c++
#include "libGoldfish.h"

int main() {
    int i = 2022;
    int *foo = &i;
    int *bar = foo;
    Goldfish::toBe("Foo is the same as bar: ", foo, bar);
    return 0;
}
```

### Example 4

```c++
#include "libGoldfish.h"

int main() {
    Goldfish::toBeNull("nullptr = null: ", nullptr);
    return 0;
}
```

### Example 5

```c++
#include "libGoldfish.h"

int main() {
    Goldfish::toBeGreaterThen("10 > 5", 10, 5);
    Goldfish::toBeLessThen("5 < 10", 5, 10);
    return 0;
}
```

## Documentation

[Documentation](https://github.com/RaffaelSchaefer/Goldfish/wiki)

## Authors

- [Raffael E. Schäfer](https://https://github.com/RaffaelSchaefer)
