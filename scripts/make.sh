#Adjust these to point to your QT installation
QTDIR=/home/psli/Qt5.6.0

mkdir -p build
cd build
$QTDIR/5.6/gcc_64/bin/qmake ../src/tetris.pro -r -spec linux-g++
make
cd ..
stanza src/libqt.stanza src/tetris.stanza -o tetris -ccfiles build/libtetris.a -ccflags "-lstdc++ -Wl,-O1 -Wl,-z,origin -Wl,-rpath,\$ORIGIN -Wl,-rpath,$QTDIR/5.6/gcc_64/lib -L$QTDIR/5.6/gcc_64/lib -lQt5Widgets -lQt5Gui -lQt5Core -lGL -lpthread"
