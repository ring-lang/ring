/*
 * Application : load stdlib.
 * Author      : Abdulwahab Benkher.
 * Date        : 2018.9.28
 */

load "stdlib.ring"
print("Hello, Ring\nWelcome to my first application\nWhat is your name")
name = getstring()
print("Hello, #{ name }")
