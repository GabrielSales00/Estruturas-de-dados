
void insertion_sort (int *A) {
    for (int j = 1; j < 10 ; j++) {

        //mão direita
        int key = A[j];
        int i = j - 1;

        //Compara com os da mão esquerda e, se algum for maior, trocamos de lugar 
        while (i >= 0 && A[i] > key) {
            A[i+1] = A[i];
            i = i - 1;
        }
        A[i+1] = key;
    }
}

void inverse_sort (int *A) {
    for (int j = 1; j < 10 ; j++) {

        //mão direita
        int key = A[j];
        int i = j - 1;

        //Compara com os da mão esquerda e, se algum for maior, trocamos de lugar 
        while (i >= 0 && A[i] < key) {
            A[i+1] = A[i];
            i = i - 1;
        }
        A[i+1] = key;
    }
}