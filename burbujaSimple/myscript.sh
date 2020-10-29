#!/bin/bash
gcc main.c tiempo.c
./a.out 100 < numeros10M.txt > sal100.txt
./a.out 1000 < numeros10M.txt > sal1000.txt
./a.out 5000 < numeros10M.txt > sal5000.txt
./a.out 10000 < numeros10M.txt > sal10000.txt
./a.out 50000 < numeros10M.txt > sal50000.txt
./a.out 100000 < numeros10M.txt > sal100000.txt
./a.out 200000 < numeros10M.txt > sal200000.txt
./a.out 400000 < numeros10M.txt > sal400000.txt
./a.out 500000 < numeros10M.txt > sal500000.txt
./a.out 600000 < numeros10M.txt > sal600000.txt
./a.out 800000 < numeros10M.txt > sal800000.txt
./a.out 1000000 < numeros10M.txt > sal1000000.txt

