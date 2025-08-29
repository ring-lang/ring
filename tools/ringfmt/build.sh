BREW_PREFIX=$(brew --prefix)

ring ../ring2exe/ring2exe.ring ringfmt.ring
./cleartemp.sh

cp ringfmt $PWD/../../bin/ringfmt 

if [ -f ../../lib/libring.dylib ];
then
cd ../../bin
ln -sf "`pwd`/ringfmt" $BREW_PREFIX/bin/ringfmt
chmod +x $BREW_PREFIX/bin/ringfmt
fi

if [ -f ../../lib/libring.so ];
then
cd ../../bin
sudo ln -sf "`pwd`/ringfmt" /usr/bin/ringfmt
sudo chmod +x /usr/bin/ringfmt
fi


