BREW_PREFIX=$(brew --prefix)

ring ../ring2exe/ring2exe.ring folder2qrc.ring 

cp folder2qrc $PWD/../../bin/folder2qrc 

if [ -f ../../lib/libring.dylib ];
then
cd ../../bin
ln -sf "`pwd`/folder2qrc" $BREW_PREFIX/bin/folder2qrc
chmod +x $BREW_PREFIX/bin/folder2qrc
fi

if [ -f ../../lib/libring.so ];
then
cd ../../bin
sudo ln -sf "`pwd`/folder2qrc" /usr/bin/folder2qrc
sudo chmod +x /usr/bin/folder2qrc
fi


