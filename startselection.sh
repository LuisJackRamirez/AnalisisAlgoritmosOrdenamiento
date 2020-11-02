echo "Compiling Selection Sort Sort..."
gcc SelectionSort.c tiempo.c -o ss

echo "Testing Selection Sort Sort..."
echo "N = 100"
./ss 100 < nums.txt > selection-testing/ss-test100.txt
echo "N = 1000"
./ss 1000 < nums.txt > selection-testing/ss-test1000.txt
echo "N = 5000"
./ss 5000 < nums.txt > selection-testing/ss-test5000.txt
echo "N = 10000"
./ss 10000 < nums.txt > selection-testing/ss-test10000.txt
echo "N = 50000"
./ss 50000 < nums.txt > selection-testing/ss-test50000.txt
echo "N = 100000"
./ss 100000 < nums.txt > selection-testing/ss-test100000.txt
echo "N = 200000"
./ss 200000 < nums.txt > selection-testing/ss-test200000.txt
echo "N = 400000"
./ss 400000 < nums.txt > selection-testing/ss-test400000.txt
echo "N = 500000"
./ss 500000 < nums.txt > selection-testing/ss-test500000.txt
echo "N = 600000"
./ss 600000 < nums.txt > selection-testing/ss-test600000.txt
echo "N = 800000"
./ss 800000 < nums.txt > selection-testing/ss-test800000.txt
echo "N = 1000000"
./ss 1000000 < nums.txt > selection-testing/ss-test1000000.txt
echo "N = 2000000"
./ss 2000000 < nums.txt > selection-testing/ss-test2000000.txt
echo "N = 3000000"
./ss 3000000 < nums.txt > selection-testing/ss-test3000000.txt