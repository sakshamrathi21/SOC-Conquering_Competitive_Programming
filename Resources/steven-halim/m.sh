#!/bin/bash
file_name=$1

export file_name

make > make_output.txt 2>&1

if [ $? -ne 0 ]; then
    cat make_output.txt
    echo "Compilation failed"
    rm make_output.txt
    exit 1
fi

if grep -q "Nothing to be done for \`all'" make_output.txt; then
    rm make_output.txt
else
    cat make_output.txt
    rm make_output.txt
fi

./a.out

rm a.out
