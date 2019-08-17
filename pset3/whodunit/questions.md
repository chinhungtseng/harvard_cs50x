# Questions

## What's `stdint.h`?

__stdint.h__ is a header file in the C standard library introduced in the C99 standard library section 7.18 to allow programmers to write more portable code
by probiding a set of typeddefs that specify exact-width integer types,
together with the defined minimum and maximum allowable values for each type, using macros.

This header is particularly useful for embedded programming which often involves considerable manipulation of hardware
specific I/O registers requiring integer data of fixed widths, specific locations and exact alignments.
__stdint.h__ (for C or C++), and __cstdint__(for C++) can be downloaded or quickly created if they are not provided.

reference:

- https://en.wikibooks.org/wiki/C_Programming/stdint.h
- http://pubs.opengroup.org/onlinepubs/9699919799/

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

intN_t is signed: the value range is (-2^(N-1)) ~ (2^(N -1) - 1)
uintN_t is unsigned 0 ~ 2^N

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

|--------|-----------|------|-------|-------|---------|
| Name   | Specifier | Bits | Bytes | Min   | Max     |
|--------|-----------|------|-------|-------|---------|
| BYTE   | uint8_t   | 8    | 1     | 0     | 2^8 -1  |
| DWORD  | uint32_t  | 32   | 4     | 0     | 2^32 -1 |
| LONG   | int32_t   | 32   | 4     | -2^31 | 2^31 -1 |
| WORD   | uint16_t  | 16   | 2     | 0     | 2^16 -1 |
|--------|-----------|------|-------|-------|---------|

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

from source: https://en.wikipedia.org/wiki/BMP\_file\_format

__Bitmap file header__

this block of bytes is at the start of the file and is used to ientigy the file.
A typical application reads this block first to ensure that the file is actually a BMP file an that it is not damages.
The first 2 bytes of the BMP file format are the character "B" then the character "M" in ASCII encodeing.
All of the integer values are stored in little-endian format(i.e.least-sinificant byte first.)

|-------|---------|-----------|-------------|
| ASCII | Decimal | Binary    | Hexadecimal |
|-------|---------|-----------|-------------|
| B     | 66      | 0100 0010 | 0x42        |
| M     | 77      | 0100 1101 | 0x4D        |
|-------|---------|-----------|-------------|

## What's the difference between `bfSize` and `biSize`?

https://stackoverflow.com/questions/25713117/what-is-the-difference-between-bisizeimage-bisize-and-bfsize

The difference between `bfSize` and `biSize` is :

- biSize = 40 bytes
- bfSize = biSizeImage + sizeof(BITMAPFILEHEADER)(14 Bytes) + sizeof(BITMAPINFORHEADER)(40 Bytes)

## What does it mean if `biHeight` is negative?

- https://docs.microsoft.com/en-us/windows/win32/directshow/top-down-vs--bottom-up-dibs

For RGB DIBs, the image orientation is indicated by the __biHight__ member of the __BITMAPINFOHEADER__ structure.

- When __biHeight__ is positibe, the image is bottom-up.
- When __biHeight__ is negative, the image is top-dowm.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

- https://docs.microsoft.com/en-us/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader
- https://en.wikipedia.org/wiki/BMP\_file\_format

biBitCount: the number of bits per pixel, which is the color depth of the image.
Typical values are 1, 4, 8, 16, 24 and 32.

|--------|------|------------|
| offset | type | name       |
|--------|------|------------|
| 28     | WROD | biBitCount |
|--------|------|------------|

## Why might `fopen` return `NULL` in `copy.c`?

- https://stackoverflow.com/questions/5987626/why-does-fopen-return-a-null-pointer

There are many reasons `fopen()` can return `NULL`:

- The file doesn't exist
- The file is opened in a mode that doesn't allow other accesses
- The network is down
- The file exists, but you don't have permissions
- A file exists with the name you gave, but the current directory of the process is not what yu expected so the relateve pathname fails to find and open the file.

so, if `fopen()` return `NULL` in `copy.c`, the reason might:

- The file's name that you want to copy is `incorrect`
- The file's content is empty
- You don't have permisstion to execute the file

## Why is the third argument to `fread` always `1` in our code?

First, I'll see the documentation of `fread` and know how it work
```
man fread

```

`size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);`

The function fread() reads `nmemb` items of data, each size bytes long,
from the stream pointed to by `stream`,
storing them at the location given by `ptr`.

`fread` in `copy.c`:

```c
fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

```

It will read sizeof(RGBTRIPLE) from the `inptr` file and stores it in the valuable `&triple`.

## What value does `copy.c` assign to `padding` if `bi.biWidth` is `3`?

```c

// determine padding for scanlines
int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

```
The definition of `RGBTRIPLE` is:

```c
typedef struct
{
    BYTE rgbtBlue;
    BYTE rgbtGreen;
    BYTE rgbtRed;
} __attribute__((__packed__))
RGBTRIPLE;
```
so, the `sizeof(RGBTRIPLE))` is `BYTE (8 bits) * 3` = `3 bytes`

int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4 =
`(4 - (3 * 3) % 4) % 4` =
`3`

## What does `fseek` do?

```c
man fseek
```

__DESCRIPTION__

The `fseek()` function sets the file position indicator for the stream pointed to by __stream__.
The new potition measured in bytes, is obtained by adding __offset__ bytes to th position specified by __whence__.

If whence is set to:

- SEEK_SET: beginning of file
- SEEK_CUR: current position of the file pointer
- SEEK_END: end of file

- https://www.quora.com/What-is-fseek-in-C-programming

## What is `SEEK_CUR`?

`SEEK_CUR` is a parameter in `fseed()` which is `the current position indicator`
