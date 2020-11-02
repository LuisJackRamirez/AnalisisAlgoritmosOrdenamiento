echo "Compiling Insertion Sort..."
gcc InsertionSort.c tiempo.c -o is

echo "Testing Insertion Sort..."
echo "N = 100"
./is 100 < nums.txt > insertion-testing/is-test100.txt
echo "N = 1000"
./is 1000 < nums.txt > insertion-testing/is-test1000.txt
echo "N = 5000"
./is 5000 < nums.txt > insertion-testing/is-test5000.txt
echo "N = 10000"
./is 10000 < nums.txt > insertion-testing/is-test10000.txt
echo "N = 50000"
./is 50000 < nums.txt > insertion-testing/is-test50000.txt
echo "N = 100000"
./is 100000 < nums.txt > insertion-testing/is-test100000.txt
echo "N = 200000"
./is 200000 < nums.txt > insertion-testing/is-test200000.txt
echo "N = 400000"
./is 400000 < nums.txt > insertion-testing/is-test400000.txt
echo "N = 500000"
./is 500000 < nums.txt > insertion-testing/is-test500000.txt
echo "N = 600000"
./is 600000 < nums.txt > insertion-testing/is-test600000.txt
echo "N = 800000"
./is 800000 < nums.txt > insertion-testing/is-test800000.txt
echo "N = 1000000"
./is 1000000 < nums.txt > insertion-testing/is-test1000000.txt
echo "N = 2000000"
./is 2000000 < nums.txt > insertion-testing/is-test2000000.txt
echo "N = 3000000"
./is 3000000 < nums.txt > insertion-testing/is-test3000000.txt