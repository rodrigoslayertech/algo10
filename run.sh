#!/bin/bash

# Definir cores
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
WHITE='\033[1;37m'
GREY='\033[0;37m'
BLUE='\033[0;34m'
NC='\033[0m' # Sem cor

echo -e "${WHITE}Algo10 - Running algorithms...${NC}\n"
printf "${GREY}Command: %s${NC}\n\n" "$(basename "$0") $*"

# !
# # Languages
LANGUAGES=(
    # Language|Compiler|Compiler Args|Is Compiled|Version Number
    "C|gcc|-o|1|gcc --version"
    "CPP|g++|-o|1|g++ --version"
    "Go|go run||0|go version"
    "Javascript|node||0|node --version"
    "Javascript|bun||0|bun --version"
    "PHP|php||0|php --version"
    "Python|python3||0|python3 --version 2>&1"
    "Rust|rustc|--crate-name temp_crate -o|1|rustc --version"
)
# # Algos
declare -A unique_algos
algo_list=()
for entry in "${LANGUAGES[@]}"; do
  IFS='|' read -r DIR CMD ARGS <<< "$entry"
  for file in "$DIR"/*.algo*; do
    [ -f "$file" ] || continue
    base=$(basename "$file")
    # E.g.: split_string.algo1.php -> split_string
    name="${base%%.algo*}"
    if [[ -z "${unique_algos[$name]}" ]]; then
      unique_algos[$name]=1
      algo_list+=("$name")
    fi
  done
done
# # Params
# Default number of iterations
iterations=10000

# Parse arguments
language_filter=""
while [[ $# -gt 0 ]]; do
    case $1 in
        --iterations)
            iterations="$2"
            shift 2
            ;;
        --language)
            language_filter="$2"
            shift 2
            ;;
        *)
            algo_arg="$1"
            shift
            ;;
    esac
done
# # Arguments
# iterations
printf "${RED}Number of iterations: %s${NC}\n" "$iterations"
# algo_arg
if [[ $algo_arg =~ ^[0-9]+$ ]]; then
  algo_index=$algo_arg
  algo_name="${algo_list[$((algo_index-1))]}"

  printf "${RED}Running algo with index: %s${NC}\n" "$algo_index"
elif [[ -n "$algo_arg" ]]; then
  algo_name="$algo_arg"

  printf "${RED}Running algo with name: '%s'${NC}\n" "$algo_name"
fi
# language_filter
if [[ -n "$language_filter" ]]; then
  printf "${RED}Filtering by language: '%s'${NC}\n" "$language_filter"
fi

echo -e "\n${BLUE}Starting tests...${NC}\n"

# @@
for entry in "${LANGUAGES[@]}"; do
    IFS='|' read -r DIR CMD ARGS IS_COMPILED VERSION_OUTPUT <<< "$entry"

    # Filter languages
    if [[ -n "$language_filter" && "$DIR" != "$language_filter" ]]; then
        continue
    fi

    version_output="$($VERSION_OUTPUT | head -n 1)"
    version_number="$(echo "$version_output" | grep -oE '[0-9]+(\.[0-9]+){1,3}' | head -n1)"

    echo -e "${YELLOW}$DIR [$CMD v${version_number}]:${NC}\n"

    for file in "$DIR"/*.algo*; do
        [ -f "$file" ] || continue

        base=$(basename "$file")
        name="${base%%.algo*}"
        variation="${base##*.algo}"
        variation="${variation%%.*}"

        # Filter algorithms
        if [[ -n "$algo_name" && "$name" != "$algo_name" ]]; then
            continue
        fi

        printf "${GREEN}%s (algo%s)${NC} " "$name" "$variation"

        if [ "$IS_COMPILED" = "1" ]; then
            # Compile
            binary="/tmp/${name//[^a-zA-Z0-9_]/_}"
            # shellcheck disable=SC2086
            $CMD $file $ARGS "$binary"
            # Run binary if compiled
            if [ -f "$binary" ]; then
                $binary "$iterations"
            fi
            # Cleanup
            rm -f "$binary"
        else
            # shellcheck disable=SC2086
            $CMD $ARGS "$file" "$iterations"
        fi

        echo -e "${YELLOW}------------------------${NC}\n"
    done
done

echo -e "${GREEN}All tests completed!${NC}"
