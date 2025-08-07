BREW_PREFIX=$(brew --prefix)

ring ../ring2exe/ring2exe.ring ringrepl.ring 

cp ringrepl $PWD/../../bin/ringrepl 

if [ -f ../../lib/libring.dylib ];
then
ln -sf "`pwd`/ringrepl" $BREW_PREFIX/bin/ringrepl
chmod +x $BREW_PREFIX/bin/ringrepl
fi

if [ -f ../../lib/libring.so ];
then
sudo ln -sf "`pwd`/ringrepl" /usr/bin/ringrepl
sudo chmod +x /usr/bin/ringrepl
fi


