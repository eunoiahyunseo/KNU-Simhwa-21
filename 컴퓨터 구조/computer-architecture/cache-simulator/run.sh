rm cachesim
make cachesim

echo case1
./cachesim -s=32 -a=1 -b=4 -f=./case1.single_write.trc
echo case2
./cachesim -s=32 -a=1 -b=4 -f=./case2.single_read.trc
echo case3
./cachesim -s=32 -a=1 -b=4 -f=./case3.consecutive_write.trc
echo case4
./cachesim -s=32 -a=1 -b=8 -f=./case3.consecutive_write.trc
echo case5
./cachesim -s=32 -a=1 -b=4 -f=./case4.consecutive_read.trc
echo case6
./cachesim -s=32 -a=1 -b=4 -f=./case5.push_and_read.trc
echo case7
./cachesim -s=32 -a=2 -b=4 -f=./case5.push_and_read.trc
echo case8
./cachesim -s=32 -a=1 -b=4 -f=./case6.complex.trc
echo case9
./cachesim -s=32 -a=1 -b=8 -f=./case6.complex.trc
echo case10
./cachesim -s=64 -a=2 -b=16 -f=./case6.complex.trc