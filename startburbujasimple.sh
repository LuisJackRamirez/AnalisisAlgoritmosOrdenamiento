echo "Compiling Burbuja Simple Sort..."
gcc BurbujaSimple.c tiempo.c -o bs

echo "Testing Burbuja Simple Sort..."
echo "N = 100"
./bs 100 < nums.txt > burbujasimple-testing/bs-test100.txt
echo "N = 1000"
./bs 1000 < nums.txt > burbujasimple-testing/bs-test1000.txt
echo "N = 5000"
./bs 5000 < nums.txt > burbujasimple-testing/bs-test5000.txt
echo "N = 10000"
./bs 10000 < nums.txt > burbujasimple-testing/bs-test10000.txt
echo "N = 50000"
./bs 50000 < nums.txt > burbujasimple-testing/bs-test50000.txt
echo "N = 100000"
./bs 100000 < nums.txt > burbujasimple-testing/bs-test100000.txt
echo "N = 200000"
./bs 200000 < nums.txt > burbujasimple-testing/bs-test200000.txt
echo "N = 400000"
./bs 400000 < nums.txt > burbujasimple-testing/bs-test400000.txt
echo "N = 500000"
./bs 500000 < nums.txt > burbujasimple-testing/bs-test500000.txt
echo "N = 600000"
./bs 600000 < nums.txt > burbujasimple-testing/bs-test600000.txt
echo "N = 800000"
./bs 800000 < nums.txt > burbujasimple-testing/bs-test800000.txt
echo "N = 1000000"
./bs 1000000 < nums.txt > burbujasimple-testing/bs-test1000000.txt