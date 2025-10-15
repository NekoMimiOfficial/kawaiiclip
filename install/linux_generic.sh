#!/usr/bin/env bash

mkdir -p ./build/output
g++ ./src/main.cpp -o ./build/output/kawaiiclip
sudo mkdir -p ~/.config/kawaiiclip/
cp emoticons.txt ~/.config/kawaiiclip/emoticons.txt
cp ./build/output/kawaiiclip ~/.local/bin/
