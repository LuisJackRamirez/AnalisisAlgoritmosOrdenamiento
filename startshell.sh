echo "Compiling Shell Sort..."
gcc ShellSort.c tiempo.c -o shell

echo "Testing Shell Sort..."
./shell 100 < nums.txt
./shell 1000 < nums.txt
./shell 5000 < nums.txt
./shell 10000 < nums.txt
./shell 50000 < nums.txt
./shell 100000 < nums.txt
./shell 200000 < nums.txt
./shell 400000 < nums.txt
./shell 600000 < nums.txt
./shell 800000 < nums.txt
./shell 1000000 < nums.txt
./shell 2000000 < nums.txt
./shell 3000000 < nums.txt
./shell 4000000 < nums.txt
./shell 5000000 < nums.txt
./shell 6000000 < nums.txt
./shell 7000000 < nums.txt
./shell 8000000 < nums.txt
./shell 9000000 < nums.txt
./shell 10000000 < nums.txt
