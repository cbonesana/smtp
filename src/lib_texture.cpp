/*
 * texture.cpp
 *
 *  Created on: 10-nov-2012
 *      Author: Claudio "Dna" Bonesana
 *    Coworker: Nathan Koefer
 */

#include "lib_texture.h"

/* Texture and filters */
GLuint texture[TEXTURE_NUMBER];				// Texture array
GLuint textureFilter=0;
Image images[TEXTURE_NUMBER];

bool ImageLoad(char *filename, Image *image) {
	FILE *file;
	unsigned long i;
	unsigned long filesize;
	unsigned long offset;
	unsigned long size_w;
	unsigned long size_h;
	unsigned long size;
	unsigned long bit_per_pixel;

	unsigned char temp;
	unsigned char bites[256];

	cout << "Data for: " << filename << endl;

	// make sure the file is there.
	if ((file = fopen(filename, "r"))==NULL){
		printf("File Not Found!\n");
		return false;
	}

	fseek(file, 0, SEEK_SET);
	fread(&bites, 256, 1, file);

	offset = bufferToLong(4,&bites[10]);
	printf("\toffset: %lu (0x%lx)", offset, offset);

	filesize = bufferToLong(4,&bites[2]);
	printf("\tfile size: %ld (0x%lx)\n", filesize,filesize);

	size_w = bufferToLong(4,&bites[18]);
	size_h = bufferToLong(4,&bites[22]);

	printf("\twidth:  %ld (0x%lx)", size_w, size_w);
	printf("\theight: %ld (0x%lx)\n", size_h, size_h);

	bit_per_pixel = bufferToLong(2, &bites[28]);

	printf("\tBit per pixel: %ld (0x%lx)\n",bit_per_pixel, bit_per_pixel);

	image->sizeX = size_w;
	image->sizeY = size_h;

	size = (image->sizeX * image->sizeY * bit_per_pixel)/8;

	printf("\tSize: %ld (0x%lx)\n", size, size);

	// seek past the rest of the bitmap header.
	fseek(file, offset, SEEK_SET);

	// read the data.
	image->data = (char *) malloc(size);
	if (image->data == NULL) {
		cout << "Error allocating memory for color-corrected image data" << endl ;
		return false;
	}

	if ((i = fread(image->data, size, 1, file)) != 1) {
		cout << "Error reading image data!" << endl;
		return false;
	}

	for (i=0;i<size;i+=3) { // reverse all of the colors. (bgr -> rgb)
		temp = image->data[i];
		image->data[i] = image->data[i+2];
		image->data[i+2] = temp;
	}

	fclose(file);
	cout << endl;

	return true;
}

bool LoadGLTextures(char *filename, int lvl, GLuint *texture) {
	// load Texture
	Image *image;

	// allocate space for texture
	image = (Image *) malloc(sizeof(Image));
	if (image == NULL) {
		cout << "Error allocating space for image" << endl;
		return false;
	}

	// load image
	if (!ImageLoad(filename, image)) {
		return false;
	}

	glGenTextures(3, &texture[lvl+0]);

	// Create Nearest Filtered Texture
	glBindTexture(GL_TEXTURE_2D, texture[lvl+0]);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST); // less cpu, less quality, more frame per seconds
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, image->sizeX, image->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image->data);

	// Create Linear Filtered Texture
	glBindTexture(GL_TEXTURE_2D, texture[lvl+1]);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, image->sizeX, image->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image->data);

	// Create MipMapped Texture
	glBindTexture(GL_TEXTURE_2D, texture[lvl+2]);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, image->sizeX, image->sizeY, GL_RGB, GL_UNSIGNED_BYTE, image->data);

	if (image){
		if (image->data){
			free(image->data);
		}
		free(image);
	}
	return true;
}
