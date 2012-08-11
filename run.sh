#!/bin/bash

rm a.out
clang src/compiler.c -ansi -pedantic && ./a.out
