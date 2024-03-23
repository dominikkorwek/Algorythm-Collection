#!/bin/bash
# manjaro simps: sudo pacman -Sy time
MEM_LIMIT=1024 # in megabytes
TIME_LIMIT=3 # in seconds
for((i=1; i<=10; i++)); do
    for j in {a..z}; do
        if [ -f "t/alc$i${j}.in" ]; then
            echo -n "alc$i${j}: "
            # can connect with oiejq script
            command time -f "%M %e %x" ./main < t/alc$i${j}.in > out.txt 2> log
            read MEM TIME STATUS <log
            MEM=$((MEM/1024))
            echo -n "${MEM}/${MEM_LIMIT}Mb ${TIME}/${TIME_LIMIT}s "

            if (( MEM >= MEM_LIMIT )); then  
                echo -e "\e[93mmemory limit\e[39m"
                break
            elif (( $(echo "$TIME > $TIME_LIMIT" | bc -l) )); then
                echo -e "\e[93mtime limit\e[39m"
                break
            elif ! diff -bwq t/alc$i${j}.out out.txt &> /dev/null; then
                echo -e "\e[91mwrong answer\e[39m"
                break
            fi

            echo -e "\e[92maccepted\e[39m"
        fi
    done
done
