#!/usr/bin/env bash

VERSION="1.0.0"

mkdir -p ./build/output/kawaiiclip_${VERSION}_amd64/usr/bin/
mkdir -p ./build/output/kawaiiclip_${VERSION}_amd64/DEBIAN/
mkdir -p ./build/output/kawaiiclip_${VERSION}_amd64/etc/kawaiiclip/
rm -rf ./build/output/kawaiiclip_${VERSION}_amd64/usr/bin/*
rm -rf ./build/output/kawaiiclip_${VERSION}_amd64/etc/kawaiiclip/*

cmake -L ./build/
make -j4

cp ./build/debian/* ./build/output/kawaiiclip_${VERSION}_amd64/DEBIAN/
cp ./build/output/kawaiiclip ./build/output/kawaiiclip_${VERSION}_amd64/usr/bin/
cp ./etc/kawaiiclip/* ./build/output/kawaiiclip_${VERSION}_amd64/etc/kawaiiclip/
python3 ./python/version_build.py

dpkg-deb --build ./build/output/kawaiiclip_${VERSION}_amd64
