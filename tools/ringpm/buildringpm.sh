ring ../ring2exe/ring2exe.ring ringpm.ring
./cleartemp.sh

cp ringpm $PWD/../../bin/ringpm 

if [ -f ../../lib/libring.dylib ];
then
cd ../../bin
ln -sf "`pwd`/ringpm" /usr/local/bin/ringpm
chmod +x /usr/local/bin/ringpm
fi

if [ -f ../../lib/libring.so ];
then
cd ../../bin
sudo ln -sf "`pwd`/ringpm" /usr/bin/ringpm
sudo chmod +x /usr/bin/ringpm
fi


