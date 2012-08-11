#!/bin/bash

set -e

rm -f a.out brainfucking lex.yy.c y.tab.?
yacc -d grammar.y
flex lexer.l
yacc grammar.y
gcc -o brainfucking -lfl -ly lex.yy.c y.tab.c

echo "Trying hello world..."
./brainfucking ../examples/hello_world.bf
echo "OK!"

echo "Trying quine!"
./brainfucking ../examples/quine.bf
echo "OMG OK!"
