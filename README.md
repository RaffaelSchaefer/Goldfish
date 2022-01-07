# Goldfish 🐠

A simple C++ library for unit testing with jest like syntax.

## Features

- Checking for variables 
- Checking for pointers
- Checking for strings
- Checking for array
- Checking for boolean
- Logging to .md files
- Time measurement for Test Duration

## Installation

Just include the Goldfish header file in your project.

```c++
#include "libGoldfish.h"
```

And include this in your CMakeLists.txt

```cmake
add_library(Goldfish lib/Goldfish/libGoldfishAnswer.cpp lib/Goldfish/libGoldfishBoolean.cpp lib/Goldfish/libGoldfishString.cpp lib/Goldfish/libGoldfishUtil.cpp lib/Goldfish/libGoldfishLog.cpp)
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

## Roadmap

### 0.0.2 Release

- Add Exception functions
- Return Objects
- Test suits which can be run in threads

## Documentation

[Documentation](https://github.com/RaffaelSchaefer/Goldfish/wiki)

## Authors

- [Raffael E. Schäfer](https://https://github.com/RaffaelSchaefer)
