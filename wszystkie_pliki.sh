#!/bin/bash
make odbieranie
make przesylanie
./przesylanie
./odbieranie
./badanie.sh

make clean
