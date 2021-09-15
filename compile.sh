#/bin/bash

##########
function valid() {
  if [ $1 -ne 0 ]; then
    echo $2"["$1"]"
    exit 1
  fi
}
##########

cmake_folder="cmake-build"
path=$(pwd)

echo "build folder: $cmake_folder"
echo "current path: $path"

if [[ ! -d "$cmake_folder" ]]
then
    mkdir "$cmake_folder"
    valid $? "Can't create build folder: $cmake_folder "
fi

cd $cmake_folder
valid $? "Cannot change to build folder"

cmake -DABS_PATH=$path -B$path/$cmake_folder ..
valid $? "Cmake fail check error list for more information"

make
valid $? "make fail check error list for more information"

cd ..
valid $? "Main directory doesn't not "

if [[ ! -d "Build" ]]
then
    echo "Build folder doesn't exist project cannot be created"
    exit 1
fi

open Build/
valid $? "Cannot open Build folder"