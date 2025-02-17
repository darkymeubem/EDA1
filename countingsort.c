#include <stdio.h>

// Função para encontrar o maior valor no array
int getMax(int arr[], int n) {
    int max = arr[0];  // Inicializa o maior valor como o primeiro elemento
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];  // Atualiza o maior valor se encontrar um maior
        }
    }
    return max;
}

// Função para implementar o Counting Sort
void countingSort(int arr[], int n) {
    // Passo 1: Encontrar o maior valor no array
    int max = getMax(arr, n);  // Usando a função getMax para encontrar o maior valor

    // Passo 2: Criar o array de contagem (contador)
    int count[max + 1];  // O tamanho é max + 1 porque precisamos de índices até o valor máximo
    for (int i = 0; i <= max; i++) {
        count[i] = 0;  // Inicializar tudo com 0
    }

    // Passo 3: Contar a frequência de cada número no array original
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;  // Aumenta o contador para o valor que encontramos no array
    }

    // Passo 4: Acumular as contagens para obter a posição final de cada número
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];  // Soma com o valor anterior, acumulando as posições
    }

    // Passo 5: Reconstruir o array original com os números ordenados
    int output[n];  // Array para armazenar o resultado ordenado
    for (int i = n -1 ;i >=  0; i--) {  // Vamos de trás para frente para manter a estabilidade
        output[count[arr[i]] - 1] = arr[i];  // Coloca o número na posição correta
        count[arr[i]]--;  // Decremente a contagem de onde o número foi colocado
    }

    // Passo 6: Copiar o array ordenado de volta para o array original
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];  // Agora o array original tem os números ordenados
    }
}

int main() {
    // Exemplo de array desordenado
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);  // Tamanho do array

    printf("Array original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    countingSort(arr, n);  // Chama a função de Counting Sort

    printf("Array ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
