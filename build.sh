#!/bin/bash
set -e

gcc -std=c17 -Wall -Wextra -g -O0 -isystem raylib/include main.c -o sorted_circle raylib/lib/libraylib.a -lm -lpthread -ldl -lrt -l:libX11.so.6

./sorted_circle
