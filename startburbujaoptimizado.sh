echo "Compiling Burbuja Optimizado Sort..."
gcc BurbujaOptimizado.c tiempo.c -o bo

echo "Testing Burbuja Optimizado Sort..."
echo "N = 100"
./bo 100 < nums.txt > burbujaoptimizada-testing/bo-test100.txt
echo "N = 1000"
./bo 1000 < nums.txt > burbujaoptimizada-testing/bo-test1000.txt
echo "N = 5000"
./bo 5000 < nums.txt > burbujaoptimizada-testing/bo-test5000.txt
echo "N = 10000"
./bo 10000 < nums.txt > burbujaoptimizada-testing/bo-test10000.txt
echo "N = 50000"
./bo 50000 < nums.txt > burbujaoptimizada-testing/bo-test50000.txt
echo "N = 100000"
./bo 100000 < nums.txt > burbujaoptimizada-testing/bo-test100000.txt
echo "N = 200000"
./bo 200000 < nums.txt > burbujaoptimizada-testing/bo-test200000.txt
echo "N = 400000"
./bo 400000 < nums.txt > burbujaoptimizada-testing/bo-test400000.txt
echo "N = 500000"
./bo 500000 < nums.txt > burbujaoptimizada-testing/bo-test500000.txt
echo "N = 600000"
./bo 600000 < nums.txt > burbujaoptimizada-testing/bo-test600000.txt
echo "N = 800000"
./bo 800000 < nums.txt > burbujaoptimizada-testing/bo-test800000.txt
echo "N = 1000000"
./bo 1000000 < nums.txt > burbujaoptimizada-testing/bo-test1000000.txt
echo "N = 2000000"
./bo 2000000 < nums.txt > burbujaoptimizada-testing/bo-test2000000.txt
