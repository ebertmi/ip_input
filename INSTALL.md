#Installation

In order to install the ip_input library on a linux (ubuntu) system follow the next steps.

```shell
gcc -c -ggdb ip_input.c -o ip_input.o
ar rcs libip_input.a ip_input.o
chmod 0644 ip_input.h libip_input.a
mkdir -p /usr/local/include
chmod 0755 /usr/local/include
mv -f ip_input.h /usr/local/include
mkdir -p /usr/local/lib
chmod 0755 /usr/local/lib
mv -f libip_input.a /usr/local/lib
cd ..
rm -rf library50-c-5
```

After these steps you can use the library by including it with

```c
#include <ip_input.h>
```

and compile your code with:

```bash
gcc yourfile.c -lip_input
```

gcc now finds the library on its own. Otherwise add the ip_input source files to your project and include them with

```c
#include "ip_input.h"
```
