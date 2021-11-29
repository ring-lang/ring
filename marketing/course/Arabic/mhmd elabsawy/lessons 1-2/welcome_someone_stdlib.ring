/*
 * Application : welcome_someone_stlib
 * Author      : mhmd elabsawy
 * Date        : --/--/----
*/

load "stdlib.ring"

print('Hello\nEnter your name')
name = getstring()
print('Hello, #{ name }')
