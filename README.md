# FTP
An implementation of a file transfer protocol system developed in C

Compatibility:

This program source has been tested to be compatible with OSX 10.11.6, Ubuntu 16.04.3 LTS and Debian9

Prerequisites:
Navigate to program root folder
Run make in terminal

Usage:
run ./server binary and specify port num in terminal
eg: ./server 4500

Open a new terminal and run ./client binary and specify host & port
eg: ./client localhost 4500

Idenitfied Bugs & Issues:
Implementation of "cd" faulty. Client is able to navigate to computer root directory
