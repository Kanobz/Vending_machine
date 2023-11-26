#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int width;
    int height;
    int* data;
} Image;

void readPGM(const char* filename, Image* img) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char magic[3];
    fscanf(file, "%2s", magic);

    if (magic[0] != 'P' || magic[1] != '5') {
        fprintf(stderr, "Invalid PGM file format\n");
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d %d", &img->width, &img->height);

    int maxval;
    fscanf(file, "%d", &maxval);

    if (maxval > 255) {
        fprintf(stderr, "Only 8-bit PGM images are supported\n");
        exit(EXIT_FAILURE);
    }

    fgetc(file);  // Consume newline

    img->data = (int*)malloc(img->width * img->height * sizeof(int));
    fread(img->data, sizeof(int), img->width * img->height, file);

    fclose(file);
}

void writePGM(const char* filename, Image* img) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "P5\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(int), img->width * img->height, file);

    fclose(file);
}

void histogramEqualization(Image* img) {
    int size = img->width * img->height;
    int L = 255;

    // Step 1: Compute the histogram of the input image
    int* histogram = (int*)calloc(L + 1, sizeof(int));
    for (int i = 0; i < size; ++i) {
        histogram[img->data[i]]++;
    }

    // Step 2: Calculate the cumulative histogram of the image
    int* cumulativeHist = (int*)malloc((L + 1) * sizeof(int));
    cumulativeHist[0] = histogram[0];
    for (int i = 1; i <= L; ++i) {
        cumulativeHist[i] = cumulativeHist[i - 1] + histogram[i];
    }

    // Step 2 (Optimised): Adjust the cumulative histogram values
    for (int i = 0; i <= L; ++i) {
        cumulativeHist[i] = (cumulativeHist[i] * L) / size;
    }

    // Step 3 (Optimised): Image Mapping
    for (int i = 0; i < size; ++i) {
        img->data[i] = cumulativeHist[img->data[i]];
    }

    free(histogram);
    free(cumulativeHist);
}

int main() {
    Image img;
    readPGM("Rain_Tree.pgm", &img);

    histogramEqualization(&img);

    writePGM("Equalized_Rain_Tree.pgm", &img);

    free(img.data);

    return 0;
}
