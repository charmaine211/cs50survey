//Copies a BMP file


#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy factor infile outfile\n");
        return 1;
    }


    // Filenames
    int n = atoi(argv[1]);
    char* infile = argv[2];
    char* outfile = argv[3];


    if (n <= 0 || n >= 100)
    {
        printf("Must be between 0 and 100\n");
        return 2;


    }


    // Input file open
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }


    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }


    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER original_bf;
    fread(&original_bf, sizeof(BITMAPFILEHEADER), 1, inptr);


    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER original_bi;
    fread(&original_bi, sizeof(BITMAPINFOHEADER), 1, inptr);


    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (original_bf.bfType != 0x4d42 || original_bf.bfOffBits != 54 || original_bi.biSize != 40 || original_bi.biBitCount != 24 || original_bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }


    // Initialize the new_bf and bi
    BITMAPFILEHEADER bf = original_bf;
    BITMAPINFOHEADER bi= original_bi;


    // Determine new height and width
    bi.biHeight = n * original_bi.biHeight;
    bi.biWidth = n * original_bi.biWidth;


    // Determine padding for scanlines for original en new file
    int original_padding =  (4 - (original_bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;


    // Determine new image sizes for bi and bf
    bi.biSizeImage = (bi.biWidth *sizeof(RGBTRIPLE) + padding) * abs(bi.biHeight);


   // 54 is BF+BI
    bf.bfSize = bi.biSizeImage + 54;


    // Write the new BFH and BIH into new bf and bi
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);


    // iterate over infile's scanlines
    //changed to original_biheight to prevent confusion
    for (int i = 0, original_biHeight = abs(original_bi.biHeight); i < original_biHeight; i++)
    {
        //Not efficient, but scans over the same input line for n * output rows
        for (int l = 0; l < n; l++)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < original_bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;


                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);


              //BGR + BGR + BGR factor # of times on width
              for (int r = 0; r < n; r++)
              {
                  fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
              }
            }


            //Input files padding, pass over seeker
            fseek(inptr, original_padding, SEEK_CUR);


            //Add multiple of 4 padding to new image size
            for (int k = 0; k < padding; k++)
            {
                fputc(0x00, outptr);
            }


            //pushes cursor back and iterate # of n times on "L" row
            if (l < n - 1)
            {
                long offset = original_bi.biWidth * sizeof(RGBTRIPLE)+ original_padding;


                // By default, files are unsigned (nonnegative).
                // Need to define negative signed long
                fseek(inptr, -offset, SEEK_CUR);
                //this shoves cursor back the entire length to start
            }
        }
    }


    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);


    // that's all folks
    return 0;
}
