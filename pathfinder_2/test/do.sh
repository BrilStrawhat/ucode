echo test1 no arguments
./pathfinder 2> ./res/res.txt
diff -y ./res/tst1.txt ./res/res.txt

echo test2 no file
./pathfinder islands 2> ./res/res.txt
diff -y ./res/tst2.txt ./res/res.txt

echo test3 empty file
./pathfinder empty.txt 2> ./res/res.txt
diff -y ./res/tst3.txt ./res/res.txt

echo test4 invalid1
./pathfinder invalid1 2> ./res/res.txt
diff -y ./res/tst4.txt ./res/res.txt

echo test5 invalid2
./pathfinder invalid2 2> ./res/res.txt
diff -y ./res/tst5.txt ./res/res.txt

echo test6 invalid3
./pathfinder invalid3 2> ./res/res.txt
diff -y ./res/tst6.txt ./res/res.txt

echo test7 example1
./pathfinder example1 > ./res/res.txt
diff -y ./res/tst7.txt ./res/res.txt

echo test8 example2
./pathfinder example2 > ./res/res.txt
diff -y ./res/tst8.txt ./res/res.txt

echo test9 easy
./pathfinder easy > ./res/res.txt
diff -y ./res/tst9.txt ./res/res.txt

echo test10 medium
./pathfinder medium > ./res/res.txt
diff -y ./res/tst10.txt ./res/res.txt

echo test11 hard
./pathfinder hard > ./res/res.txt
diff -y ./res/tst11.txt ./res/res.txt

echo test12 hardest
./pathfinder hardest > ./res/res.txt
diff -y ./res/tst12.txt ./res/res.txt

echo test13 invalid4
./pathfinder invalid4 2> ./res/res.txt
diff -y ./res/tst13.txt ./res/res.txt
