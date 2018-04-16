#include "Sprite.h"

Sprite::Sprite(const char * imagepath){
    image = loadBMP_custom(imagepath)

    // Data read from the header of the BMP file
    unsigned char header[54]; // Each BMP file begins by a 54-bytes header
    unsigned int dataPos;     // Position in the file where the actual data begins
    unsigned int width, height;
    unsigned int imageSize;   // = width*height*3
    // Actual RGB data
    unsigned char * data;

    // Read ints from the byte array
    dataPos    = *(int*)&(header[0x0A]);
    imageSize  = *(int*)&(header[0x22]);
    width      = *(int*)&(header[0x12]);
    height     = *(int*)&(header[0x16]);

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &textBufferID);
    glBindTexture(GL_TEXTURE_2D, textBufferID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0,
                GL_BGR, GL_UNSIGNED_BYTE, bitmap_data);
    glActiveTexture(GL_TEXTURE0);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);

    texID = glGetUniformLoaction(progID, )
}

Sprite::~Sprite(){
    
}