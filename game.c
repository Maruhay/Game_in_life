#include "game.h"


void matGen (bool** matrix, config conf) {
    srand(time(NULL));
    for (int i = 1 ; i <= conf->row; i++) {
        for (int j = 1; j <= conf->col; j++)
            matrix[i][j] = rand() % 2;
    }

    for (int i = 1 ; i <= conf->row; i++) {
                for (int j = 1; j <= conf->col; j++)
                        printf("%d ", matrix[i][j]);
                printf("\n");
    }
    printf("\n");
    printf("\n");
    printf("\n");
}

bool** Moore (bool** matrix, config conf) {
    int sum;
    // Creating of temporary matrix
    bool** tempMat = (bool **)malloc(conf->row * sizeof(bool *));
        for (int i = 1 ; i <= conf->row; i++)
                tempMat[i] = (bool *)malloc(conf->col * sizeof(bool));
    for (int i = 1 ; i <= conf->row; i++)
        for (int j = 1; j <= conf->col; j++)
            tempMat[i][j] = matrix[i][j];

    for (int i = 1 ; i <= conf->row; i++) {
        for (int j = 1; j <= conf->col; j++) {

                    // Death of points

            if (matrix[i][j] == 1 && i == 1 && j > 1 && j < conf->col) {
                sum = 0;
                sum = matrix[i][j-1] + matrix[i][j+1] + matrix[i+1][j-1] + matrix[i+1][j] + matrix[i+1][j+1];
                if (sum != 2 && sum != 3) tempMat[i][j] = 0;
            }
            if (matrix[i][j] == 1 && i == conf->row && j > 1 && j < conf->col) {
                sum = 0;
                sum = matrix[i-1][j-1] + matrix[i-1][j] + matrix[i-1][j+1] + matrix[i][j-1] + matrix[i][j+1];
                if (sum != 2 && sum != 3) tempMat[i][j] = 0;
            }
            if (matrix[i][j] == 1 && j == 1 && i > 1 && i < conf->row) {
                sum = 0;
                sum = matrix[i-1][j] + matrix[i+1][j] + matrix[i-1][j+1] + matrix[i][j+1] + matrix[i+1][j+1];
                if (sum != 2 && sum != 3) tempMat[i][j] = 0;
            }
            if (matrix[i][j] == 1 && j == conf->col && i > 1 && i < conf->row) {
                sum = 0;
                sum = matrix[i-1][j-1] + matrix[i][j-1] + matrix[i+1][j-1] + matrix[i-1][j] + matrix[i+1][j];
                if (sum != 2 && sum != 3) tempMat[i][j] = 0;
            }
            if (matrix[i][j] == 1 && i > 1 && j > 1 && i < conf->row && j < conf->col) {
                sum = 0;
                sum = matrix[i-1][j-1] + matrix[i-1][j] + matrix[i-1][j+1] + matrix[i][j-1] + matrix[i][j+1] + 
                matrix[i+1][j-1] + matrix[i+1][j] + matrix[i+1][j+1];
                if (sum != 2 && sum != 3) tempMat[i][j] = 0;
            }
            if (matrix[i][j] == 1 && i == 1 && j == 1) {
                sum = 0;
                sum = matrix[i][j+1] + matrix[i+1][j] + matrix[i+1][j+1];
                if (sum != 2 && sum != 3) tempMat[i][j] = 0;
            }
            if (matrix[i][j] == 1 && i == 1 && j == conf->col) {
                sum = 0;
                sum = matrix[i+1][j] + matrix[i][j-1] + matrix[i+1][j-1];
                if (sum != 2 && sum != 3) tempMat[i][j] = 0;
            }
            if (matrix[i][j] == 1 && i == conf->row && j == 1) {
                sum = 0;
                sum = matrix[i-1][j] + matrix[i-1][j+1] + matrix[i][j+1];
                if (sum != 2 && sum != 3) tempMat[i][j] = 0;
            }
            if (matrix[i][j] == 1 && i == conf->row && j == conf->col) {
                sum = 0;
                sum = matrix[i][j-1] + matrix[i-1][j] + matrix[i-1][j-1];
                if (sum != 2 && sum != 3) tempMat[i][j] = 0;
            }



                    // Points reviving

            if (matrix[i][j] == 0 && i == 1 && j > 1 && j < conf->col) {
                sum = 0;
                sum = matrix[i][j-1] + matrix[i][j+1] + matrix[i+1][j-1] + matrix[i+1][j] + matrix[i+1][j+1];
                if (sum == 3) tempMat[i][j] = 1;
            }
            if (matrix[i][j] == 0 && i == conf->row && j > 1 && j < conf->col) {
                sum = 0;
                sum = matrix[i-1][j-1] + matrix[i-1][j] + matrix[i-1][j+1] + matrix[i][j-1] + matrix[i][j+1];
                if (sum == 3) tempMat[i][j] = 1;
            }
            if (matrix[i][j] == 0 && j == 1 && i > 1 && i < conf->row) {
                sum = 0;
                sum = matrix[i-1][j] + matrix[i+1][j] + matrix[i-1][j+1] + matrix[i][j+1] + matrix[i+1][j+1];
                if (sum == 3) tempMat[i][j] = 1;
            }
            if (matrix[i][j] == 0 && j == conf->col && i > 1 && i < conf->row) {
                sum = 0;
                sum = matrix[i-1][j-1] + matrix[i][j-1] + matrix[i+1][j-1] + matrix[i-1][j] + matrix[i+1][j];
                if (sum == 3) tempMat[i][j] = 1;
            }
            if (matrix[i][j] == 0 && i > 1 && j > 1 && i < conf->row && j < conf->col) {
                sum = 0;
                sum = matrix[i-1][j-1] + matrix[i-1][j] + matrix[i-1][j+1] + matrix[i][j-1] + matrix[i][j+1] + 
                matrix[i+1][j-1] + matrix[i+1][j] + matrix[i+1][j+1];
                if (sum == 3) tempMat[i][j] = 1;
            }
            if (matrix[i][j] == 0 && i == 1 && j == 1) {
                sum = 0;
                sum = matrix[i][j+1] + matrix[i+1][j] + matrix[i+1][j+1];
                if (sum == 3) tempMat[i][j] = 1;
            }
            if (matrix[i][j] == 0 && i == 1 && j == conf->col) {
                sum = 0;
                sum = matrix[i+1][j] + matrix[i][j-1] + matrix[i+1][j-1];
                if (sum == 3) tempMat[i][j] = 1;
            }
            if (matrix[i][j] == 0 && i == conf->row && j == 1) {
                sum = 0;
                sum = matrix[i-1][j] + matrix[i-1][j+1] + matrix[i][j+1];
                if (sum == 3) tempMat[i][j] = 1;
            }
            if (matrix[i][j] == 0 && i == conf->row && j == conf->col) {
                sum = 0;
                sum = matrix[i][j-1] + matrix[i-1][j] + matrix[i-1][j-1];
                if (sum == 3) tempMat[i][j] = 1;
            }
        } 
    }
    return tempMat;
}

bool** Neumann (bool** matrix, config conf) {
    int sum;
    // Creating of temporary matrix
    bool** tempMat = (bool **)malloc(conf->row * sizeof(bool *));
        for (int i = 1 ; i <= conf->row; i++)
                tempMat[i] = (bool *)malloc(conf->col * sizeof(bool));
    for (int i = 1 ; i <= conf->row; i++)
        for (int j = 1; j <= conf->col; j++)
            tempMat[i][j] = matrix[i][j];

    for (int i = 1 ; i <= conf->row; i++) {
        for (int j = 1; j <= conf->col; j++) {

                    // Death of points

            if (matrix[i][j] == 1 && i == 1 && j > 1 && j < conf->col) {
                sum = 0;
                sum = matrix[i][j-1] + matrix[i][j+1] + matrix[i+1][j];
                if (sum != 2 && sum != 3) tempMat[i][j] = 0;
            }
            if (matrix[i][j] == 1 && i == conf->row && j > 1 && j < conf->col) {
                sum = 0;
                sum = matrix[i-1][j] + matrix[i][j-1] + matrix[i][j+1];
                if (sum != 2 && sum != 3) tempMat[i][j] = 0;
            }
            if (matrix[i][j] == 1 && j == 1 && i > 1 && i < conf->row) {
                sum = 0;
                sum = matrix[i-1][j] + matrix[i+1][j] + matrix[i][j+1];
                if (sum != 2 && sum != 3) tempMat[i][j] = 0;
            }
            if (matrix[i][j] == 1 && j == conf->col && i > 1 && i < conf->row) {
                sum = 0;
                sum = matrix[i][j-1] + matrix[i-1][j] + matrix[i+1][j];
                if (sum != 2 && sum != 3) tempMat[i][j] = 0;
            }
            if (matrix[i][j] == 1 && i > 1 && j > 1 && i < conf->row && j < conf->col) {
                sum = 0;
                sum = matrix[i-1][j]+ matrix[i][j-1] + matrix[i][j+1] + matrix[i+1][j];
                if (sum != 2 && sum != 3) tempMat[i][j] = 0;
            }
            if (matrix[i][j] == 1 && i == 1 && j == 1) {
                sum = 0;
                sum = matrix[i][j+1] + matrix[i+1][j];
                if (sum != 2 && sum != 3) tempMat[i][j] = 0;
            }
            if (matrix[i][j] == 1 && i == 1 && j == conf->col) {
                sum = 0;
                sum = matrix[i+1][j] + matrix[i][j-1];
                if (sum != 2 && sum != 3) tempMat[i][j] = 0;
            }
            if (matrix[i][j] == 1 && i == conf->row && j == 1) {
                sum = 0;
                sum = matrix[i-1][j] + matrix[i][j+1];
                if (sum != 2 && sum != 3) tempMat[i][j] = 0;
            }
            if (matrix[i][j] == 1 && i == conf->row && j == conf->col) {
                sum = 0;
                sum = matrix[i][j-1] + matrix[i-1][j];
                if (sum != 2 && sum != 3) tempMat[i][j] = 0;
            }



                    // Points reviving

            if (matrix[i][j] == 0 && i == 1 && j > 1 && j < conf->col) {
                sum = 0;
                sum = matrix[i][j-1] + matrix[i][j+1] + matrix[i+1][j];
                if (sum == 3) tempMat[i][j] = 1;
            }
            if (matrix[i][j] == 0 && i == conf->row && j > 1 && j < conf->col) {
                sum = 0;
                sum = matrix[i-1][j] + matrix[i][j-1] + matrix[i][j+1];
                if (sum == 3) tempMat[i][j] = 1;
            }
            if (matrix[i][j] == 0 && j == 1 && i > 1 && i < conf->row) {
                sum = 0;
                sum = matrix[i-1][j] + matrix[i+1][j] + matrix[i][j+1];
                if (sum == 3) tempMat[i][j] = 1;
            }
            if (matrix[i][j] == 0 && j == conf->col && i > 1 && i < conf->row) {
                sum = 0;
                sum = matrix[i][j-1] + matrix[i-1][j] + matrix[i+1][j];
                if (sum == 3) tempMat[i][j] = 1;
            }
            if (matrix[i][j] == 0 && i > 1 && j > 1 && i < conf->row && j < conf->col) {
                sum = 0;
                sum = matrix[i-1][j]+ matrix[i][j-1] + matrix[i][j+1] + matrix[i+1][j];
                if (sum == 3) tempMat[i][j] = 1;
            }
            if (matrix[i][j] == 0 && i == 1 && j == 1) {
                sum = 0;
                sum = matrix[i][j+1] + matrix[i+1][j];
                if (sum == 3) tempMat[i][j] = 1;
            }
            if (matrix[i][j] == 0 && i == 1 && j == conf->col) {
                sum = 0;
                sum = matrix[i+1][j] + matrix[i][j-1];
                if (sum == 3) tempMat[i][j] = 1;
            }
            if (matrix[i][j] == 0 && i == conf->row && j == 1) {
                sum = 0;
                sum = matrix[i-1][j] + matrix[i][j+1];
                if (sum == 3) tempMat[i][j] = 1;
            }
            if (matrix[i][j] == 0 && i == conf->row && j == conf->col) {
                sum = 0;
                sum = matrix[i][j-1] + matrix[i-1][j];
                if (sum == 3) tempMat[i][j] = 1;
            }
        } 
    }
    return tempMat;
}