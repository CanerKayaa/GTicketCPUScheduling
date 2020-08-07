#!/bin/bash
sudo -u usr1 gcc process.c
sudo -u usr1 ./a.out &
sudo -u usr2 gcc process.c
sudo -u usr2 ./a.out &
sudo -u usr3 gcc process.c
sudo -u usr3 ./a.out &
sudo -u usr3 ./a.out &
sudo -u usr4 gcc process.c
sudo -u usr4 ./a.out &
