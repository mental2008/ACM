g++ gen.cpp -std=c++11 -o gen && ./gen > in.txt
g++ g.cpp -std=c++11 -o g && ./g < ./in.txt
g++ brute.cpp -std=c++11 -o brute && ./brute < ./in.txt