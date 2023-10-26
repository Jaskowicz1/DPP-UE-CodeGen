#!/bin/bash

echo "Creating temp directory..."
mkdir temp
cd temp || exit

echo "Fetching latest DPP"
git clone --depth 1 https://github.com/brainboxdotcc/DPP

echo "Copying includes over to up-most directory"
mv DPP/include ..

echo "Cleaning up..."
cd .. || exit
rm -rf temp

echo "Committing..."
git checkout main
git pull
git add include
git commit -m "auto update include to latest DPP"
git push
