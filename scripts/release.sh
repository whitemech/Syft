#!/usr/bin/env bash

OS="ubuntu"
OS_VERSION="20.04"
VERSION="3.0.0"
RELEASE_NAME="syft-${VERSION}_${OS}-${OS_VERSION}"
prefix="/usr/local"
includedir="${prefix}/include/"

OUTPUT_DIR="${RELEASE_NAME}"
OUTPUT_TAR="${RELEASE_NAME}.tar.gz"

mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make -j

cd ..
rm -rf "${OUTPUT_DIR}"
mkdir "${OUTPUT_DIR}"
cp README "${OUTPUT_DIR}"

mkdir "${OUTPUT_DIR}"/lib
cp -P build/lib/libsynthesis.so "${OUTPUT_DIR}"/lib/libsynthesis.so

tar -c "${OUTPUT_DIR}" -f "${OUTPUT_TAR}"
rm -r "${OUTPUT_DIR}"

echo "Output in ${OUTPUT_TAR}"