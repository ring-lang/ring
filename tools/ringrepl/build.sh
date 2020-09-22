ring ../tools/ring2exe/ring2exe.ring ringrepl.ring 

cp ringrepl $PWD/../../bin/ringrepl 

if [ -f ../../lib/libring.dylib ];
then
echo "`pwd`/ringrepl \$1 \$2 \$3 \$4 \$5 \$6 \$7" > /usr/local/bin/ringrepl
chmod +x /usr/local/bin/ringrepl
fi

if [ -f ../../lib/libring.so ];
then
sudo echo "`pwd`/ringrepl \$1 \$2 \$3 \$4 \$5 \$6 \$7" > /usr/bin/ringrepl
sudo chmod +x /usr/bin/ringrepl
fi


