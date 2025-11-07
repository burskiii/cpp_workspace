#!/bin/bash
for arg in 0 42 -42 4.2 4.2f a Z nanf +inff -inff nan +inf -inf nan。ff 42,0f ++42
do
    echo "====== Test: $arg ======"
    ./a.out $arg
    echo
done
