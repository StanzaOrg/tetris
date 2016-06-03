#Adjust these to point to your QT installation
QTDIR=/Users/psli/Qt5.6.0

stanza src/libqt.stanza src/tetris.stanza -s tetris.s

mkdir -p build
cd build
$QTDIR/5.6/clang_64/bin/qmake ../src/tetris.pro -r -spec macx-clang
make
$QTDIR/5.6/clang_64/bin/macdeployqt tetris.app -dmg
cd ..


