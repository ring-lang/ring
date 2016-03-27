del "output\current_output.txt"
echo "Testing..."
call scripts_list >> "output\current_output.txt"
echo "Test result..."
fc "output\current_output.txt" "output\correct_output.txt"
 