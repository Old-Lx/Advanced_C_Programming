echo "Clear the Debug mode compilation"
make -f debug.mk clean

echo "Build debug mode"
make -f debug.mk

echo "Clear the Prod mode compilation"
make -f Makefile clean

echo "Build Prod mode"
make -f Makefile