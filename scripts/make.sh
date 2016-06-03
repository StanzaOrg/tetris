#Adjust these to point to your QT installation
QTDIR=/Users/psli/Qt5.6.0

cd build
$QTDIR/5.6/clang_64/bin/qmake ../src/tetris.pro -r -spec macx-clang
make
cd ..

stanza src/libqt.stanza src/tetris.stanza -o tetris -ccfiles build/libtetris.a -ccflags "-lstdc++ -F$QTDIR/5.6/clang_64/lib -framework QtWidgets -framework QtGui -framework QtCore -framework OpenGL -framework AGL -Wl,-rpath,$QTDIR/5.6/clang_64/lib"
