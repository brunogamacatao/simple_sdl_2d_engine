VCPKG_DIR=/home/bruno/dev/vcpkg
BUILD_DIR=build

rm -rf $BUILD_DIR

cmake -B $BUILD_DIR -S . -DCMAKE_TOOLCHAIN_FILE=$VCPKG_DIR/scripts/buildsystems/vcpkg.cmake
cd $BUILD_DIR
make
