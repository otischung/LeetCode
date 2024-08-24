#!/bin/bash

make -s
diff <(./palindrome < in.txt) <(cat out.txt)
