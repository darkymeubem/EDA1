#!/bin/bash

# Verifica se o número correto de argumentos foi fornecido
if [ "$#" -ne 2 ]; then
    echo "Uso: $0 <nome_do_arquivo> <quantidade_de_valores>"
    exit 1
fi

# Nome do arquivo e quantidade de valores
OUTPUT_FILE=$1
NUM_VALUES=$2

# Cria diretório se não existir
mkdir -p input

# Gera valores aleatórios e escreve no arquivo
echo $NUM_VALUES > input/$OUTPUT_FILE
for ((i=0; i<NUM_VALUES; i++)); do
    echo $((RANDOM % 1000)) >> input/$OUTPUT_FILE
done

echo "Arquivo $OUTPUT_FILE criado com $NUM_VALUES valores aleatórios."
