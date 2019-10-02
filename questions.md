# Questions

## What's `stdint.h`?

A headerfile in de the C standard library that includes integer types

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

So we can specify how large the integer must be in bits. 

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE: 0 - 1 byte, DWORD: 0 - 4 bytes, LONG: 4 bytes and WORD: 0 - 2 bytes

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

BM, or 0x4d 0x42

## What's the difference between `bfSize` and `biSize`?

bfSize is the size in bytes of the bitmap. And biSize is the number of bytes required by the structure.

## What does it mean if `biHeight` is negative?

That the bitmap is topdown and it's origin uis the upper left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in `copy.c`?

When the file that the user wants to copy doesn't exist.

## Why is the third argument to `fread` always `1` in our code?

We don't need more space than the space of the files we're reading. We already specified the size of the filmes in bmp.h.

## What value does `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3

## What does `fseek` do?

Looks for the padding at the end of the scanline

## What is `SEEK_CUR`?

It denotes file pointer’s current position, in this case where RGBTRIPLE ends. The Offset makes us "jump" over the padding.
