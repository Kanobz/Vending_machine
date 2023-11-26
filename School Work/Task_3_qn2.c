#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *InpImage;
    int L;
    int *Histogram;
    int *CumulativeHist;
    int *OutImage;
    int Size;
} ImageData;

void computeHistogram(ImageData *data) {
    for (int i = 0; i < data->Size; ++i) {
        data->Histogram[data->InpImage[i]]++;
    }
}

void computeCumulativeHist(ImageData *data) {
    data->CumulativeHist[0] = data->Histogram[0];
    for (int i = 1; i <= data->L; ++i) {
        data->CumulativeHist[i] = data->CumulativeHist[i - 1] + data->Histogram[i];
    }

    for (int i = 0; i <= data->L; ++i) {
        data->CumulativeHist[i] = (data->CumulativeHist[i] * data->L) / data->Size;
    }
}

void performHistogramEqualization(ImageData *data) {
    for (int i = 0; i < data->Size; ++i) {
        data->OutImage[i] = data->CumulativeHist[data->InpImage[i]];
    }
}

void savePGM(const char *filename, int *pixels, int width, int height) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "P2\n");
    fprintf(file, "%d %d\n", width, height);
    fprintf(file, "255\n");

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            fprintf(file, "%d ", pixels[i * width + j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

void freeImageData(ImageData *data) {
    free(data->InpImage);
    free(data->Histogram);
    free(data->CumulativeHist);
    free(data->OutImage);
}

int main() {
    FILE *file = fopen("Rain_Tree.pgm", "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        return EXIT_FAILURE;
    }

    ImageData imageData;
    char buffer[256];

    // Read PGM header
    fgets(buffer, sizeof(buffer), file); // Skip P2
    fgets(buffer, sizeof(buffer), file); // Read image dimensions
    sscanf(buffer, "%d %d", &imageData.Size, &imageData.Size);

    fgets(buffer, sizeof(buffer), file); // Skip max pixel value

    // Allocate memory for image data
    imageData.InpImage = (int *)malloc(imageData.Size * sizeof(int));
    imageData.Histogram = (int *)calloc(256, sizeof(int));
    imageData.L = 255; // 8-bit image
    imageData.CumulativeHist = (int *)malloc((imageData.L + 1) * sizeof(int));
    imageData.OutImage = (int *)malloc(imageData.Size * sizeof(int));

    // Reading pixel values
    for (int i = 0; i < imageData.Size; ++i) {
        fscanf(file, "%d", &imageData.InpImage[i]);
    }

    fclose(file);

    // Step 1: Computing the Histogram
    computeHistogram(&imageData);

    // Step 2: Computing the Cumulative Histogram
    computeCumulativeHist(&imageData);

    // Step 3: Executing the Histogram Equalization
    performHistogramEqualization(&imageData);

    // Save the result to a new PGM file
    savePGM("Equalized_Image.pgm", imageData.OutImage, imageData.Size, imageData.Size);

    // Free allocated memory
    freeImageData(&imageData);

    return 0;
}
