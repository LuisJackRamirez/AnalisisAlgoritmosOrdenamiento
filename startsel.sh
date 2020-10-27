echo "testing sel sort..."
./sel 100 < nums.txt > sel-testing/sel-testing100.txt
./sel 1000 < nums.txt > sel-testing/sel-testing1000.txt
./sel 5000 < nums.txt > sel-testing/sel-testing5000.txt
./sel 10000 < nums.txt > sel-testing/sel-testing10000.txt
./sel 50000 < nums.txt > sel-testing/sel-testing50000.txt
./sel 100000 < nums.txt > sel-testing/sel-testing100000.txt
./sel 200000 < nums.txt > sel-testing/sel-testing200000.txt
./sel 400000 < nums.txt > sel-testing/sel-testing400000.txt
./sel 600000 < nums.txt > sel-testing/sel-testing600000.txt
echo "600000 done..."
./sel 800000 < nums.txt > sel-testing/sel-testing800000.txt
echo "800000 done..."
./sel 1000000 < nums.txt > sel-testing/sel-testing1000000.txt
echo "1000000 done..."
./sel 2000000 < nums.txt > sel-testing/sel-testing2000000.txt
echo "2000000 done..."
./sel 3000000 < nums.txt > sel-testing/sel-testing3000000.txt
echo "3000000 done..."
