#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    // starting number for the filename
    typedef uint8_t  BYTE;
    int file_counter = 0;
    BYTE buffer [512];
    char *filename = malloc(sizeof(int) * 3);

    // Open new jpg and check if it is NULL
    FILE *img;

    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // remember filenames
    char *raw_files = argv[1];

    // open raw_files for reading
    FILE *inptr = fopen(raw_files, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", raw_files);
        return 2;
    }

    // read 512 bytes into buffer
    while(fread(&buffer, 512, 1, inptr) == 1)
    {
       // start of a new JPEG?
        if(buffer[0] == 0xff &&
        buffer[1] == 0xd8 &&
        buffer[2] == 0xff &&
        (buffer[3] & 0xf0) == 0xe0)
        {
            if (file_counter > 0)
            {
                fclose(img);
            }

            sprintf(filename, "%03i.jpg", file_counter);
            img = fopen(filename, "w");
            fwrite(&buffer, 512, 1, img);
            file_counter++;
        }

        // already found a JPEG
        else
        {
            if (file_counter > 0)
            {
                fwrite(buffer, 512, 1, img);
            }
        }
    }

    free(filename);

    // close files
    fclose(inptr);
    fclose(img);

    return 0;

}