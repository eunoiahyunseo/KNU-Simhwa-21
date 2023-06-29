#!/bin/bash


SOURCE_DIR="$( cd "$( dirname "$0" )" >/dev/null 2>&1 && pwd -P )"

# for testing trace file ( cache-simulator )

rm -rf $SOURCE_DIR/cachesim
make $SOURCE_DIR/cachesim

###########################
# essential option
###########################

OPTS_WITH_VAL=(
    "s"
    "b"
    "a"
    "d"
)

OPTS_WITH_VAL_DESC=(
    "s( cache_size ): total size of cache"
    "b( block_size ): size of block"
    "a( associative_size ): cache assocative size"
    "d( dir_name ): tracefile set directory name"
)

###########################
# not essential option
###########################

OPTS_NO_VAL=(
    "h"
)

OPTS_NO_VAL_DESC=(
    "print usage"
)


###########################
# print usage
###########################

function print_usage() {
    pg_name=$(basename $0)
    _opts_list_with_val=$(printf "[-%s=<val>] " "${OPTS_WITH_VAL[@]}")
    _opts_list_no_val=$(printf "[-%s] " "${OPTS_NO_VAL[@]}")
    
    echo ""
    echo "USAGE:"
    echo "  $pg_name ${_opts_list_with_val}"
    echo "      ${_opts_list_no_val}"

    echo ""
    echo "DESCRIPTIONS:"
    # description of essential options
    for((i = 0; i<${#OPTS_WITH_VAL[@]}; i++));
    do
        printf "\t-%s=<val>, \t%s\n" ${OPTS_WITH_VAL[$i]} "${OPTS_WITH_VAL_DESC[$i]}"
    done
    
    # description of not essential options
    for((i = 0; i<${#OPTS_NO_VAL[@]}; i++));
    do
        printf "\t-%s, \t%s\n" ${OPTS_NO_VAL[$i]} "${OPTS_NO_VAL_DESC[$i]}"
    done

}

_opts_list_with_val=$(printf "%s:" "${OPTS_WITH_VAL[@]}")
_opts_list_no_val=$(printf "%s" "${OPTS_NO_VAL[@]}")
opts_list_str=${_opts_list_with_val}${_opts_list_no_val}


while getopts $opts_list_str opt; do
    case $opt in
        "${OPTS_WITH_VAL[0]}")
            cache_size=$OPTARG
            ;;
        "${OPTS_WITH_VAL[1]}")
            block_size=$OPTARG
            ;;
        
        "${OPTS_WITH_VAL[2]}")
            associative_size=$OPTARG
            ;;
        
        "${OPTS_WITH_VAL[3]}")
            trace_directory=$OPTARG
            ;;
        "h" | "?")
            print_usage
            exit 1
            ;;
    esac
done

echo -e "cache_size: $cache_size"
echo -e "block_size: $block_size"
echo -e "associative_size: $associative_size \n"
echo -e "----------------< simulation start >------------------ \n"

FILE_COUNTER=0

for file in $SOURCE_DIR/$trace_directory/*.trc
do
    if [ -f $file ]
    then
        echo -e "Running test ( `basename $file` )"
        ./$(dirname "$0")/./cachesim -s=$cache_size -b=$block_size -a=$associative_size -f=$file
        
        echo -e "\n---------------------------------------------\n"
    fi
done



