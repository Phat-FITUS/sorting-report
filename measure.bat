@ECHO OFF

g++ *.cpp -o main
main -test 0
main -test 1
main -test 2
main -test 3

PAUSE