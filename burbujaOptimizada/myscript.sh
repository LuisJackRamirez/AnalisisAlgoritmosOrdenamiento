#!/bin/bash
gcc main.c tiempo.c
./a.out 100 < numeros10M.txt > optimizada100.txt
./a.out 1000 < numeros10M.txt > optimizada1000.txt
./a.out 5000 < numeros10M.txt > optimizada5000.txt
./a.out 10000 < numeros10M.txt > optimizada10000.txt
./a.out 50000 < numeros10M.txt > optimizada50000.txt
./a.out 100000 < numeros10M.txt > optimizada100000.txt
./a.out 200000 < numeros10M.txt > optimizada200000.txt
./a.out 400000 < numeros10M.txt > optimizada400000.txt
./a.out 500000 < numeros10M.txt > optimizada500000.txt
./a.out 600000 < numeros10M.txt > optimizada600000.txt
./a.out 800000 < numeros10M.txt > optimizada800000.txt
./a.out 1000000 < numeros10M.txt > optimizada1000000.txt
./a.out 2000000 < numeros10M.txt > optimizada2000000.txt


