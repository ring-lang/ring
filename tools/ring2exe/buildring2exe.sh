ring ring2exe.ring ring2exe.ring
./cleartemp.sh

cp ring2exe $PWD/../../bin/ring2exe 

if [ -f ../../lib/libring.dylib ];
then
cd ../../bin
echo "`pwd`/ring2exe \$1 \$2 \$3 \$4 \$5 \$6 \$7" > /usr/local/bin/ring2exe
chmod +x /usr/local/bin/ring2exe
fi

if [ -f ../../lib/libring.so ];
then
cd ../../bin
sudo echo "`pwd`/ring2exe \$1 \$2 \$3 \$4 \$5 \$6 \$7" > /usr/bin/ring2exe 
sudo chmod +x /usr/bin/ring2exe
fi


