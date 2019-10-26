#!/bin/sh
clear


print_green ()
{
	echo "\033[32m$1\033[0m"
}

print_red ()
{
	echo "\033[31m$1\033[0m"
}


print_red "----==== IT'S CHECK LIST FOR PUSH_SWAP ====----

"

print_green "author file: cat -e author"
cat -e author

print_red "
test checker error management"

print_green "
./checker aaa"
./checker aaa

print_green "
./checker 1 1"
./checker 1 1

print_green "
./checker 1 2 11122233344"
./checker 1 2 11122233344

print_green "

echo \"  pb  \" | ./checker	2 1 3"
echo "  pb  " | ./checker	2 1 3



print_red "
test checker False tests"


print_green "
echo \"sa\npb\nrrr\" | ./checker 0 9 1 8 2 7 3 6 4 5"
echo "sa\npb\nrrr" | ./checker 0 9 1 8 2 7 3 6 4 5



print_red "

test checker Right tests"

print_green "
./checker	0 1 2"
./checker 0 1 2

print_green "
echo \"pb\nra\npb\nra\nsa\nra\npa\npa\" | ./checker  0 9 1 8 2"
echo "pb\nra\npb\nra\nsa\nra\npa\npa" | ./checker  0 9 1 8 2



print_red "
Push_swap - Identity test"

print_green "
./push_swap 42"
./push_swap 42

print_green "
./push_swap 0 1 2 3"
./push_swap 0 1 2 3

print_green "
./push_swap 0 1 2 3 4 5 6 7 8 9"
./push_swap 0 1 2 3 4 5 6 7 8 9



print_red "
Push_swap - Simple version"

print_green "
ARG=\"2 1 0\"; ./push_swap \$ARG | ./checker \$ARG
ARG=\"2 1 0\"; ./push_swap \$ARG | wc -l"
ARG="2 1 0"; ./push_swap $ARG | ./checker $ARG
ARG="2 1 0"; ./push_swap $ARG | wc -l



print_red "
Push_swap - Another simple version"

print_green "
ARG=\"1 5 2 4 3\"; ./push_swap \$ARG | ./checker \$ARG
ARG=\"1 5 2 4 3\"; ./push_swap \$ARG | wc -l"
ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker $ARG
ARG="1 5 2 4 3"; ./push_swap $ARG | wc -l
