#!/bin/bash

doxygen
cd docs
cd latex
make pdf
cp refman.pdf ../doc_parts/programozoi_dokumentacio.pdf
cd ..
rm -rf latex
rm -rf html
