#include <stdio.h>
#include <FreeImage.h>
#include <math.h> 
#include <string.h>

FIBITMAP* cargar_imagen(const char* nombreArchivo) {
    FREE_IMAGE_FORMAT formato = FreeImage_GetFileType(nombreArchivo, 0);

    if (formato == FIF_UNKNOWN) {
        formato = FreeImage_GetFIFFromFilename(nombreArchivo);
        fprintf(stderr, "Formato de imagen desconocido para el archivo: %s\n", nombreArchivo);
        return NULL;
    }

    FIBITMAP* imagen = FreeImage_Load(formato, nombreArchivo, 0);
    return imagen;
}


void guardar_imagen(FIBITMAP* imagen, const char* nombreArchivo) {
    FreeImage_Save(FIF_PNG, imagen, nombreArchivo, PNG_DEFAULT);
}

FIBITMAP* escala_grises(FIBITMAP* imagen) {
    FIBITMAP* imagen_gris = FreeImage_ConvertToGreyscale(imagen);
    return imagen_gris;
}


FIBITMAP *filtro_laplaciano(FIBITMAP *Image) {
    int width = FreeImage_GetWidth(Image);
    int height = FreeImage_GetHeight(Image);

    // Crear una matriz de filtro laplaciano
    int laplacianFilter[3][3] = {
        {0, 1, 0},
        {1, -4, 1},
        {0, 1, 0}
    };

    // Crear una nueva imagen para almacenar el resultado
    FIBITMAP *laplacianImage = FreeImage_Clone(Image);

    // Acceder a los datos de los píxeles de la imagen original y la nueva imagen
    BYTE *inputBits = FreeImage_GetBits(Image);
    BYTE *outputBits = FreeImage_GetBits(laplacianImage);

    // Aplicar el filtro laplaciano a la imagen
    for (int y = 1; y < height - 1; y++) {
        for (int x = 1; x < width - 1; x++) {
            int sum = 0;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int pixelValue = inputBits[(y + i) * FreeImage_GetPitch(Image) + (x + j)];
                    sum += pixelValue * laplacianFilter[i + 1][j + 1];
                }
            }
            // Asignar el valor resultante al píxel correspondiente en la nueva imagen
            outputBits[y * FreeImage_GetPitch(laplacianImage) + x] = (BYTE)sum;
        }
    }

    return laplacianImage;
}

void ejecutar_filtro_laplaciano(char *nombre_imagen){
    FIBITMAP* imagen = cargar_imagen(nombre_imagen);

    if (!imagen) {
        fprintf(stderr, "No se pudo cargar la imagen.\n");
        return;
    }

    imagen = escala_grises(imagen);
    imagen = filtro_laplaciano(imagen);

    char nombre_salida[100] = "Laplaciano_";
    strcat(nombre_salida, nombre_imagen);

    guardar_imagen(imagen, nombre_salida);
    FreeImage_Unload(imagen);
}


int main() {
    ejecutar_filtro_laplaciano("imagen_original.jpg");
    return 0;
}
