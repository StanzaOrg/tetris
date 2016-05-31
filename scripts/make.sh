cd build
/Users/psli/Qt5.6.0/5.6/clang_64/bin/qmake ../src/tetris.pro -r -spec macx-clang
make
cd ..
stanza src/tetris.stanza -o tetris -ccfiles build/libtetris.a -ccflags "-lstdc++ -F/Users/psli/Qt5.6.0/5.6/clang_64/lib -framework QtWidgets -framework QtGui -framework QtCore -framework OpenGL -framework AGL -Wl,-rpath,/Users/psli/Qt5.6.0/5.6/clang_64/lib"
