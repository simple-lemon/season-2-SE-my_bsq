first thing to do: create a .txt file and write a map to it.
second step: the file named my_bsq.c is compiled (via Makefile)
final step: the my_bsq file is launched through the terminal, the map file must also be entered through argv.


When content is written in .txt format files in the Windows system, the system writes \r before \n, so convert .txt files to unix format
use, for this you need to install the dos2unix command in the terminal.
to install this command is needed: 
sudo apt update
sudo apt install dos2unix
sudo yum install dos2unix
The file "dos2unix filename.txt" will be converted to unix format.
