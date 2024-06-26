#!/bin/bash

executable_name="Prog2_NHF"

clear
cd build
gnome-terminal -- bash -c " \
  make; \
  if [ \$? -ne 0 ]; then \
      read -s -n 1 -p 'Make failed. Press any key to exit...'; \
  else \
    ./$executable_name; \
    if [ \$? -ne 0 ]; then \
      read -s -n 1 -p 'Execution failed. Press any key to exit...'; \
    fi \
  fi"
