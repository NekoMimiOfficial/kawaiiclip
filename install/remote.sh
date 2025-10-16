#!/usr/bin/env bash

curl -o kawaiiclip.cpp https://raw.githubusercontent.com/NekoMimiOfficial/kawaiiclip/refs/heads/main/src/main.cpp
curl -o emoticons.txt https://raw.githubusercontent.com/NekoMimiOfficial/kawaiiclip/refs/heads/main/etc/kawaiiclip/emoticons.txt

g++ -o kawaiiclip kawaiiclip.cpp

mkdir -p $HOME/.local/bin/
mkdir -p $HOME/.config/kawaiiclip/

rm kawaiiclip.cpp
mv kawaiiclip $HOME/.local/bin/
mv emoticons.txt $HOME/.config/kawaiiclip/
