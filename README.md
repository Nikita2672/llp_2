# LLP 2-nd laboratory work

Вариант: LINQ

## Prerequisites

- CMake
- Ninja
- Flex
- Bison

## Setup on Windows

Make sure you have set the following environment variables:

1. **CMake:**
   - Example: `C:\Program Files\JetBrains\CLion 2022.2.1\bin\cmake\win\bin`

2. **Ninja:**
   - Example: `C:\Program Files\JetBrains\CLion 2022.2.1\bin\ninja\win\`

3. **Flex**
4. **Bison**

## How to Build and Run

### Windows

```bash
cmake . -B build                                                                                                                                                                        ✔ 
cmake --build build --target all
cd build
.\parser.exe
```
### Linux
```bash
cmake . -B build                                                                                                                                                                        ✔ 
cmake --build build --target all
cd build
./parser
```
