ring ring2exe.ring folder2qrc.ring 

cp folder2qrc $PWD/../../bin/folder2qrc 

if [ -f ../../lib/libring.dylib ];
then
echo "`pwd`/folder2qrc \$1 \$2 \$3 \$4 \$5 \$6 \$7" > /usr/local/bin/folder2qrc
chmod +x /usr/local/bin/folder2qrc
fi

if [ -f ../../lib/libring.so ];
then
sudo echo "`pwd`/folder2qrc \$1 \$2 \$3 \$4 \$5 \$6 \$7" > /usr/bin/folder2qrc
sudo chmod +x /usr/bin/folder2qrc
fi


