#!/bin/bash

tests=(
  "0" "42" "-42" "4.2" "4.2f" "a" "Z"
  "nanf" "+inff" "-inff" "nan" "+inf" "-inf"
  "nan。ff" "42,0f" "++42"
  # char to int boundary
  "31" "32" "127" "128" "-1"
  # int max/min
  "2147483647" "2147483648" "-2147483648" "-2147483649"
  #overflow
  "1e308" "1e309" "-1e309"
  
  "." "+." "42f" "42.0ff" " 42" "42 "
)

for arg in "${tests[@]}"
do
  echo "====== Test: [$arg] ======"
  ./ScarlaConverter "$arg"
  echo
done
