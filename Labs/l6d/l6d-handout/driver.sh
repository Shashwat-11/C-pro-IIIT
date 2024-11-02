#!/usr/bin/bash
# driver.sh - A simple autograder script.
# Usage: ./driver.sh

# Initialize total scores
# total_score_1=0
max_score=60

# test_count_1=0
# test_count_2=0
# test_count_3=0


# Colors for pass/fail
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m'

total_score_1=0
total_score_2=0
total_score_3=0
# Compile the code for problem 1
cd p1
echo "Compiling p1, main.c"
(make clean; make)
status1=$?
if [ ${status1} -ne 0 ]; then
    echo "Failure: Unable to compile main.c (return status = ${status1})"
    total_score_1=0
else
    run_test_1() {
        local input_file="$1"
        local expected_output_file="$2"
        local points="$3"
        # Increment test count
        test_count_1=$((test_count_1 + 1))
        
        # Read expected output from file
        expected_output=$(cat "$expected_output_file")
        
        # Run the program with time and memory limit
        # 'timeout' command sets time limit, and '/usr/bin/time -v' captures memory
        { time_output=$(timeout  1s ./main < "$input_file" 2> time_stats) ; } 2>&1
        # { time_output=$(timeout  1s /usr/bin/time -v ./main < "$input_file" 2> time_stats) ; } 2>&1
        exit_status=$?
        cat "time_stats"
        
        memory_kb=0
        # Capture time stats and memory usage from time_stats
        real_time=$(grep "Elapsed (wall clock) time" time_stats | awk '{print $8}')
        #memory_kb=$(grep "Maximum resident set size" time_stats | awk '{print $6}')  # Memory in KB
        #pid=$(pgrep main)
        #memory_kb=$(grep VmRSS /proc/$pid/status | awk '{print $2}')
        
        # Convert time to milliseconds (integer arithmetic)
        real_time_seconds=$(echo $real_time | sed 's/s//')  # Remove the 's' suffix from time if any
        time_taken_ms=$(echo "$real_time_seconds * 1000" | awk '{printf "%.3f", $0}')
        
        MEMORY_LIMIT=$((4 * 1024))  # 4 MB in KB
        # echo $memory_kb
        
        # Read the program's output
        output=$time_output
        # echo $expected_output
        # Check if the program timed out
        if [ $exit_status -eq 124 ]; then
            echo -e "$TLE: Test Case $test_count_1 FAILED (Time Limit Exceeded)"
            #elif [[ -z "$memory_kb" || $memory_kb -gt $MEMORY_LIMIT ]]; then
            #echo -e "${YELLOW}MLE:${NC} Test Case $test_count_1 FAILED (Memory Limit Exceeded)"
        else
            # Check if the output matches the expected output
            if [ "$output" = "$expected_output" ]; then
                echo -e "AC: Test Case $test_count_1 PASSED"
                total_score_1=$((total_score_1 + 10))
            else
                echo -e "WA: Test Case $test_count_1 FAILED (Wrong Answer)"
            fi
        fi
    }
    
    echo "Problem 1 Test Cases Running"
    echo "--------------------"
    
    # Folder where test cases are stored
    tests_folder="testsp1"
    
    # Number of test cases
    #num_tests=2
    num_tests=3
    
    i=1
    # Loop through all test cases
    while [ "$i" -lt $num_tests ];
    do
        input_file="../$tests_folder/input$i.txt"
        output_file="../$tests_folder/output$i.txt"
        points=20/$num_tests  # Points for each test case
        
        if [[ -f "$input_file" && -f "$output_file" ]]; then
            run_test_1 "$input_file" "$output_file" "10"
        else
            if [ ! -f "$input_file" ]; then
                echo "Input file not found: $(realpath "$input_file")"
            fi
            if [ ! -f "$output_file" ]; then
                echo "Output file not found: $(realpath "$output_file")"
            fi
        fi
        i=$(( i + 1 ))
        
    done
fi

# Compile the code for problem 2
cd ../p2
echo "Compiling p2, main.c"
(make clean; make)
status2=$?
if [ ${status2} -ne 0 ]; then
    echo "Failure: Unable to compile main.c (return status = ${status2})"
    total_score_2=0
else
    run_test_2() {
        local input_file="$1"
        local expected_output_file="$2"
        local points="$3"
        
        # Increment test count
        test_count_2=$((test_count_2 + 1))
        
        # Read expected output from file
        expected_output=$(cat "$expected_output_file")
        
        # Run the program with time and memory limit
        # 'timeout' command sets time limit, and '/usr/bin/time -v' captures memory
        #{ time_output=$(timeout 1s /usr/bin/time -v ./main < "$input_file" 2> time_stats) ; } 2>&1
        { time_output=$(timeout 1s ./main < "$input_file" 2> time_stats) ; } 2>&1
        exit_status=$?
        
        # Capture time stats and memory usage from time_stats
        real_time=$(grep "Elapsed (wall clock) time" time_stats | awk '{print $8}')
        #memory_kb=$(grep "Maximum resident set size" time_stats | awk '{print $6}')  # Memory in KB
        
        # Convert time to milliseconds (integer arithmetic)
        real_time_seconds=$(echo $real_time | sed 's/s//')  # Remove the 's' suffix from time if any
        time_taken_ms=$(echo "$real_time_seconds * 1000" | awk '{printf "%.3f", $0}')
        
        MEMORY_LIMIT=$((2 * 1024))  # 2 MB in KB
        
        # Read the program's output
        output=$time_output
        # echo $memory_kb
        # echo $real_time
        
        # Check if the program timed out or exceeded memory limit
        if [ $exit_status -eq 124 ]; then
            echo -e "$TLE: Test Case $test_count_2 FAILED (Time Limit Exceeded)"
            # elif [ "$memory_kb" -gt "$MEMORY_LIMIT" ]; then
            #echo -e "${YELLOW}MLE:${NC} Test Case $test_count_2 FAILED (Memory Limit Exceeded)"
        else
            # Check if the output matches the expected output
            output_lines=$(echo "$output" | tr '\n' ' ')
            expected_lines=$(echo "$expected_output" | tr '\n' ' ')
            match=true
            
            for line in $expected_lines; do
                if ! echo "$output_lines expected_lines" | grep -q "$line"; then
                    match=false
                    break
                fi
            done
            
            if $match; then
                echo -e "AC: Test Case $test_count_2 PASSED"
                total_score_2=$((total_score_2 + points))
            else
                echo -e "WA: Test Case $test_count_2 FAILED (Wrong Answer)"
                flag=1
            fi
            
        fi
        # echo "--------------------"
    }
    
    echo "Problem 2 Test Cases Running"
    echo "--------------------"
    
    # Folder where test cases are stored
    tests_folder="testsp2"
    
    # Number of test cases
    # num_tests=50
    num_tests=2
    i=0
    # Loop through all test cases
    while [ "$i" -lt $num_tests ];
    do
        input_file="../$tests_folder/input$i.txt"
        output_file="../$tests_folder/output$i.txt"
        points=20/$num_tests  # Points for each test case
        
        if [[ -f "$input_file" && -f "$output_file" ]]; then
            run_test_2 "$input_file" "$output_file" "$points"
        else
            if [ ! -f "$input_file" ]; then
                echo "Input file not found: $(realpath "$input_file")"
            fi
            if [ ! -f "$output_file" ]; then
                echo "Output file not found: $(realpath "$output_file")"
            fi
        fi
        i=$(( i + 1 ))
        
    done
fi

# Compile the code for problem 3
cd ../p3
echo "Compiling p3, main.c"
(make clean; make)
status3=$?
if [ ${status3} -ne 0 ]; then
    echo "Failure: Unable to compile main.c (return status = ${status3})"
    total_score_3=0
else
    run_test_3() {
        local input_file="$1"
        local expected_output_file="$2"
        local points="$3"
        
        # Increment test count
        test_count_3=$((test_count_3 + 1))
        
        # Read expected output from file
        expected_output=$(cat "$expected_output_file")
        
        # Run the program with time and memory limit
        # 'timeout' command sets time limit, and '/usr/bin/time -v' captures memory
        { time_output=$(timeout 1s ./main < "$input_file" 2> time_stats) ; } 2>&1
        #{ time_output=$(timeout 1s /usr/bin/time -v ./main < "$input_file" 2> time_stats) ; } 2>&1
        exit_status=$?
        
        # Capture time stats and memory usage from time_stats
        memory_kb=0
        real_time=$(grep "Elapsed (wall clock) time" time_stats | awk '{print $8}')
        #memory_kb=$(grep "Maximum resident set size" time_stats | awk '{print $6}')  # Memory in KB
        
        
        
        
        
        # Convert time to milliseconds (integer arithmetic)
        real_time_seconds=$(echo $real_time | sed 's/s//')  # Remove the 's' suffix from time if any
        time_taken_ms=$(echo "$real_time_seconds * 1000" | awk '{printf "%.3f", $0}')
        
        MEMORY_LIMIT=$((4 * 1024))  # 4 MB in KB
        
        # Read the program's output
        output=$time_output
        # echo $memory_kb
        # echo $real_time
        
        # Check if the program timed out or exceeded memory limit
        if [ $exit_status -eq 124 ]; then
            echo -e "TLE: Test Case $test_count_3 FAILED (Time Limit Exceeded)"
            #elif [[ -z "$memory_kb" || $memory_kb -gt $MEMORY_LIMIT ]]; then
            #echo -e "${YELLOW}MLE:${NC} Test Case $test_count_3 FAILED (Memory Limit Exceeded)"
        else
            # Check if the output matches the expected output
            if [ "$output" = "$expected_output" ]; then
                echo -e "AC: Test Case $test_count_3 PASSED"
                total_score_3=$((total_score_3 + points))
            else
                echo -e "WA:Test Case $test_count_3 FAILED (Wrong Answer)"
            fi
        fi
        # echo "--------------------"
    }
    
    echo "Problem 3 Test Cases Running"
    echo "--------------------"
    
    # Folder where test cases are stored
    tests_folder="testsp3"
    
    # Number of test cases
    num_tests=2
    i=0
    # Loop through all test cases
    while [ "$i" -lt $num_tests ];
    do
        input_file="../$tests_folder/input$i.txt"
        output_file="../$tests_folder/output$i.txt"
        points=20/$num_tests  # Points for each test case
        
        if [[ -f "$input_file" && -f "$output_file" ]]; then
            run_test_3 "$input_file" "$output_file" "$points"
        else
            if [ ! -f "$input_file" ]; then
                echo "Input file not found: $(realpath "$input_file")"
            fi
            if [ ! -f "$output_file" ]; then
                echo "Output file not found: $(realpath "$output_file")"
            fi
        fi
        i=$(( i + 1 ))
        
    done
fi





# Calculate total score and percentage
total_score=$((total_score_1+total_score_2+total_score_3))
percentage=$((total_score * 100 / max_score))

# Print the total score and percentage
echo "Total Score: $total_score / $max_score"
echo "Percentage: $percentage%"


echo "---------------------------------------------------------------------------------"

echo "{\"scores\": {\"p1\": $total_score_1, \"p2\": $total_score_2, \"p3\": $total_score_3}}"
exit
