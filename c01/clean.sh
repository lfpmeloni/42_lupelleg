#!/bin/sh
echo "*.DS_Store" > .gitignore
echo ".vsode/" >> .gitignore
echo "clean.sh" >> .gitignore

find . -type d -name "*.dSYM" -exec rm -rf {} +
find . -type f ! -name "*.c" ! -path "./.git/*" ! -name "clean.sh" -exec rm -f {} +

echo "Cleanup complete: .dSYM files deleted, non-C files removed, and .gitignore created."