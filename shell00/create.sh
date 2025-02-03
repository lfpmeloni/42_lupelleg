#!/bin/sh
mkdir ex00 ex01 ex02 ex03 ex04 ex05 ex06 ex07 ex08 ex09
cd ex00
touch z
echo "Z" > z
cd ../ex01
touch testShell00
printf 0123456789012345678901234567890123456789 > testShell00
touch -t 202406012342 testShell00
chmod 455 testShell00
tar -cf testShell00.tar testShell00
chmod 777 testShell00
rm testShell00
cd ../ex02
mkdir test0 test2
touch test1 test3 test4
ln test3 test5
printf abcd > test1
printf 1 > test3
printf 12 > test4
printf 2 > test5
ln -s test0 test6
touch -t 202406012047 test0
touch -t 202406012146 test1
touch -t 202406012245 test2
touch -t 202406012344 test3
touch -t 202406012343 test4
touch -t 202406012344 test5
touch -h -t 202406012220 test6
chmod 715 test0
chmod 714 test1
chmod 504 test2
chmod 404 test3
chmod 641 test4
chmod 404 test5
chmod -h 777 test6
tar -cf exo2.tar *
chmod 777 test0 test1 test2 test3 test4 test5 test6
rmdir test0 test2
rm test1 test3 test4 test5 test6
cd ../ex03
cat ~/.ssh/id_rsa.pub > id_rsa_pub
cd ../ex04
touch midLS
echo "ls -tpm" > midLS
cd ../ex05
touch git_commit.sh
echo '#!/bin/bash' > git_commit.sh
echo 'git log -5 --pretty=tformat:"%H"' >> git_commit.sh
chmod 777 git_commit.sh
cd ../ex06
echo '#!/bin/bash' > git_ignore.sh
echo 'git ls-files --others --ignored --exclude-standard' >> git_ignore.sh
cd ../resources
patch a sw.diff -o b
mv b ../ex07/
cd ../ex08
touch clean
echo '#!/bin/bash' > clean
echo 'find . -type f \( -name ‘#*#’ -o -name ‘*~’  \) -print -delete' >> clean
