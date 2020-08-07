#!/bin/bash
rm g0usr1.txt
rm g0usr2.txt
rm g0usr3p1.txt
rm g0usr3p2.txt
rm g0usr4.txt

echo "Basladi"

watch -n 1000 "top  -b -n 1 | grep usr1 | awk '{printf "%.2f\n", $9}'" >> g0usr1.txt
watch -n 1000 "top  -b -n 1 | grep usr2 | awk '{printf "%.2f\n", $9}'" >> g0usr2.txt
watch -n 1000 "top  -b -n 10 | grep 1379 | awk '{printf "%.2f\n", $9}'" >> g0usr3p1.txt
watch -n 1000 "top  -b -n 10 | grep 1380 | awk '{printf "%.2f\n", $9}'" >> g0usr3p2.txt
watch -n 1000 "top  -b -n 10 | grep usr4 | awk '{printf "%.2f\n", $9}'" >> g0usr4.txt

echo "Bitti"
