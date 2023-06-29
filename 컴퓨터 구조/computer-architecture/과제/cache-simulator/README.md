# cache-simulator
![License](https://img.shields.io/badge/Licence-MIT-blue.svg)<br>
This is a set associative cache simulator written in ``C``. Write policy is write-back and it follows LRU replacement strategy for the oldest line.

## What is set associative cache?
> Set-associative cache is a trade-off between direct-mapped cache and fully associative cache.
> A set-associative cache can be imagined as a (n*m) matrix. The cache is divided into ‘n’ sets and each set contains ‘m’ cache lines. A memory block is first mapped onto a set and then placed into any cache line of the set.
> The range of caches from direct-mapped to fully associative is a continuum of levels of set associativity. (A direct-mapped cache is one-way set-associative and a fully associative cache with m cache lines is m-way set-associative.)
> Many processor caches in today's designs are either direct-mapped, two-way set-associative, or four-way set-associative. - **wikipedia**

## How to exeucte
1. Use make to compile ```cachesim.c```
```
make cachesim
```

2. Execute ```cachesim```
```
./cachesim -s={cache size} -a={associativity} -b={block size} -f={trace file name}
```

- cache size: 32 bytes ~ 1024 bytes (power of 2)
- associativity: 1, 2, 4... (power of 2)
- block size: 4 bytes ~ 256 bytes (power of 2)
- trace file name: ```file_name.trc```

e.g, For 64 bytes cache size, associativity of 2, 8 bytes block size and ```sample.trc```, You can execute the simulator by
```
./cachesim -s=64 -a=2 -b=8 -f=sample.trc
```

## How to write trace file?
You can execute the simulator using the trace file. The trace file is the record of memory accesses. It has the following format.
```
{address} {R/W} {data}
00010000 W 1
00010004 W 2
00010008 W 3
0001000C W 4
00010000 R
00010004 R
00010008 R
0001000C R
```
Memory addresses are in hexadecimal format and the size is 32 bits. R/W means read/write.

For ```W```, the value to write is shown as the third number. For ```R```, there is no third value.

One memory access always works at the unit of 1 word.

## Contact
You can contact me via e-mail (scv1702 at gmail.com).

## License

<img align="right" src="http://opensource.org/trademarks/opensource/OSI-Approved-License-100x137.png">

The class is licensed under the [MIT License](http://opensource.org/licenses/MIT):

Copyright &copy; 2021 Changyu Shin, Jihyeon Lee

* [Changyu Shin](http://github.com/scv1702)
* [Jihyeon Lee](https://github.com/ljhyeon)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

