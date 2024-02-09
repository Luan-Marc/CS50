#!/bin/bash

echo dictionary
read dict

echo texts
read text

./speller dictionaries/$dict texts/$text.txt > student.txt
./speller50 dictionaries/$dict texts/$text.txt > staff.txt
diff -y student.txt staff.txt


