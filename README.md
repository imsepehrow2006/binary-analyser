# binary-analyser

A small tool written in C. Point it at any file and it works out what the file
actually is from its first few bytes, then prints the first 256 bytes as hex with the
ASCII next to it, the same way `xxd` or PowerShell's `Format-Hex` does.

```text
Filename: .\samples\leaf.png
Size of the file: 1883127 bytes
Type of the file: PNG (A PNG image file)
00000000: 89 50 4E 47 0D 0A 1A 0A 00 00 00 0D 49 48 44 52  |.PNG........IHDR|
00000010: 00 00 06 D5 00 00 07 80 08 06 00 00 00 B1 11 D8  |................|
00000020: 0A 00 00 00 01 73 52 47 42 00 AE CE 1C E9 00 1C  |.....sRGB.......|
00000030: BB B1 49 44 41 54 78 DA EC DD FB 4F 15 74 18 C7  |..IDATx....O.t..|
00000040: F1 E7 1C 0E 47 D0 D6 CC 92 B4 D6 0F A5 A5 56 33  |....G.........V3|
00000050: B7 80 40 E0 D0 81 BC 40 DC 1B D0 C5 46 14 2D 53  |..@....@....F.-S|
00000060: C1 B8 C5 65 5C CF 81 23 47 40 24 8D BB 30 65 8C  |...e\..#G@$..0e.|
00000070: 90 A5 AD E5 5A 73 FD C0 A2 60 29 16 99 6D E8 16  |....Zs...`)..m..|
00000080: 65 D6 6A 0C 51 A6 E3 40 70 1E 7F 61 8E BF E1 F0  |e.j.Q..@p..a....|
00000090: 7E 6D DF 5F BF FF C0 E7 F9 3C 8F 00 00 00 CF A4  |~m._.....<......|
000000A0: AA 46 55 35 CD 4C 5C 78 F9 F7 EF 1B 2C 17 CF DB  |.FU5.L\x....,...|
000000B0: 43 67 26 46 23 75 F6 C6 36 55 35 A9 AA 51 44 44  |Cg&F#u..6U5..QDD|
000000C0: 55 0D 02 00 00 00 00 00 00 00 00 00 2C 07 AA 6A  |U...........,..j|
000000D0: 58 12 A6 99 55 35 F4 8F DF 06 A2 BE 38 E5 78 49  |X...U5......8.xI|
000000E0: 16 DD FC E9 9A EF 5F 63 97 AC 3A E7 8A 56 D5 2D  |......_c..:..V.-|
000000F0: 04 6A 00 00 00 00 00 00 00 00 00 58 96 54 E7 C2  |.j.........X.T..|
```

It loads the whole file into memory first and prints from there, rather than reading
a byte at a time.

## It goes by the bytes, not the extension

Every format leaves a fixed signature in its first few bytes. A PNG starts
`89 50 4E 47` and says `IHDR`, as you can see above. A jpg starts `FF D8 FF`. Windows
believes whatever the extension says, so a jpg renamed to `.png` still shows up as a
PNG in Explorer. This doesn't — it reads what's actually there.

So far it knows Windows executables (MZ), Linux executables (ELF), PNG, JPEG, PDF, and
zip archives, which covers .docx, .jar and .apk too since those are all zips
underneath.

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
.\analyse.exe samples\leaf.png
```

Any path works, not just files in `samples`. Try it on something from System32 and
watch it come back as MZ. To save the output instead of filling your terminal:

```powershell
.\analyse.exe samples\leaf.png > output.txt
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

## Credits

The test image in `samples/` is from [Pixabay](https://pixabay.com), used under the
Pixabay Content License.
