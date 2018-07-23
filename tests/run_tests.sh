#!/bin/bash
rm "output/current_output.txt"
echo "Testing..."
./scripts_list.sh >> "output/current_output.txt"
echo "Test result..."
diff "output/current_output.txt" "output/correct_output_linux.txt"
 
