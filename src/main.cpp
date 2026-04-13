#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include <iostream>
#include <string>

#include "stb_image.h"
#include "stb_image_write.h"



int main()
{
    std::cout << "PNG/Chunk Splitter!" << std::endl;

    //Load 
    int width, height, channels;
    std::string InputFileName = "Input image/";

    std::cout << "Enter the name of the PNG file to split (including extension): ";
    std::string fileName;
    std::getline(std::cin, fileName);

    InputFileName += fileName;

    unsigned char* data = stbi_load(InputFileName.c_str(), &width, &height, &channels, 0);

    if (!data)
    {
        std::cerr << "Failed to load image: " << InputFileName << std::endl;
        return 1;
    }

    std::cout << "Image loaded: " << width << "x" << height << " with " << channels << " channels." << std::endl;
    std::cout << "How big should the chunks/PNG be? (in pixels, e.g. 256 for 256x256): ";
    int chunkSize;
    std::cin >> chunkSize;
    int chunkX = 0;

    std::cout << "Splitting image into chunks of " << chunkSize << "x" << chunkSize << " pixels..." << std::endl;

    //Slice up
    for (int y = 0; y + chunkSize <= height; y += chunkSize)
    {
        for (int x = 0; x + chunkSize <= width; x += chunkSize)
        {
            // Allocate chunk buffer
            unsigned char* chunk = new unsigned char[chunkSize * chunkSize * channels];

            // Copy pixels
            for (int row = 0; row < chunkSize; row++) {
                memcpy(
                    chunk + row * chunkSize * channels,
                    data + (y + row) * width * channels + x * channels,
                    chunkSize * channels
                );
            }

            // Save chunk
            std::string filename = "Output Images/chunk_" + 
                std::to_string(chunkX++) + ".png";
            
            stbi_write_png(filename.c_str(), chunkSize, chunkSize, 
                channels, chunk, chunkSize * channels);

            delete[] chunk;
        }
    }

    stbi_image_free(data);
    std::cout << "Done! " << chunkX << " chunks created." << std::endl;
    return 0;
}