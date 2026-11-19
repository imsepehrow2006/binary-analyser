# binary-analyser

A hex dumper written in C. Point it at any file and it prints the first 256 bytes as
hex with the ASCII next to it, the same way `xxd` or PowerShell's `Format-Hex` does

```
Filename: samples\cat.jpg
Size of the file: 33107 bytes
00000000: FF D8 FF E0 00 10 4A 46 49 46 00 01 01 00 00 01  |......JFIF......|
00000010: 00 01 00 00 FF DB 00 84 00 09 06 07 12 13 12 15  |................|
00000020: 12 13 13 15 15 15 15 15 15 15 15 15 15 15 15 15  |................|
00000090: 2D 2D 2D 2D 2D 2D 2D 2D 2D 2D FF C0 00 11 08 01  |----------......|
000000A0: B6 02 BD 03 01 22 00 02 11 01 03 11 01 FF C4 00  |....."..........|
```

It loads the whole file into memory first and prints from there, rather than reading
a byte at a time.

## Build

Needs gcc. On Windows:

```powershell
.\build.ps1
```

Or directly:

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic -g src\main.c src\dump.c -o analyse.exe
```

## Usage

```powershell
.\analyse.exe samples\hello.txt
```

Any path works, not just files in `samples`. To save the output instead of filling
your terminal:

```powershell
.\analyse.exe samples\hello.txt > output.txt
```

With no filename it prints usage and exits.

## Why I built it

This is the first thing I've made in C. I started it about three months ago and tried
to learn the language while writing it, which went badly — I knew the syntax but had
no idea how to put it together, so I kept getting stuck. I stopped, went back and
learned C properly from the start (Bro Code's series on YouTube, plus AI for hints
when I got stuck), writing about twenty small programs along the way. Then I came back
and rebuilt this from scratch.

## Why C

I like it, and so far I find it easier to get on with than C++ or Rust. Longer term I
want to write my own compiler, so starting close to the metal seemed sensible.
