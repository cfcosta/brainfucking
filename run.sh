#!/bin/bash

rm a.out
clang compiler.c -ansi -pedantic && ./a.out
