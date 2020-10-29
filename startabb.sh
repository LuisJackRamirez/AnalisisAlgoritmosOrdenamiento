echo "Compiling ABB Sort..."
gcc ABBSort.c tiempo.c -o abb

echo "Testing ABB Sort..."
./abb 100 < nums.txt
./abb 1000 < nums.txt
./abb 5000 < nums.txt
./abb 10000 < nums.txt
./abb 50000 < nums.txt
./abb 100000 < nums.txt
./abb 200000 < nums.txt
./abb 400000 < nums.txt
./abb 600000 < nums.txt
./abb 800000 < nums.txt
./abb 1000000 < nums.txt
./abb 2000000 < nums.txt
./abb 3000000 < nums.txt
./abb 4000000 < nums.txt
./abb 5000000 < nums.txt
./abb 6000000 < nums.txt
./abb 7000000 < nums.txt
./abb 8000000 < nums.txt
./abb 9000000 < nums.txt
./abb 10000000 < nums.txt
