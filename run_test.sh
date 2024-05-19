#!/bin/bash

executable_name="Prog2_NHF_test"

clear
cd build
gnome-terminal -- bash -c " \
  make; \
  ./$executable_name; \
  echo; \
  read -s -n 1 -p 'All tests finished running. Press any key to exit...';
"