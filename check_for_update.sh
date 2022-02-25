#!/usr/bin/bash

libraries_folder="Engine"
build_folder="Build"
prefix="[SWEngine-Core] "

function print() {
    echo -e $prefix ${1}
}

function download() {
        print "Download ${1}..."
        print "Download complete"

        print "Installation ${1}..."
        cd ${libraries_folder}
        if [[ ! -d ${4} ]]; then
            mkdir ${4}
        fi
        cd ${4}
        tar -xf ../${1}.tar || exit 1
        mv *.so* ../
        rm ../${1}.tar
        cd ../../
        print "${1} installation complete"
}

if [[ ${1} == "-i" ]]; then

    if [[ ! -d ${libraries_folder} ]]; then
        mkdir ${libraries_folder} || exit 1
    fi
fi

if [[ ${1} == "-c" ]]; then
    print "Cleaning..."
    # if [[ -d ${libraries_folder} ]]; then
    #     rm -r ${libraries_folder} || exit 1
    # fi
    if [[ -d ${build_folder} ]]; then
        rm -r ${build_folder} || exit 1
    fi
    print "Clean complete"
fi

if [[ ${1} == "-b" ]]; then
    if [[ ! -d ${libraries_folder} ]]; then
        print "$libraries_folder not found please run ./check_for_update -i before!"
        exit 1
    fi
    build_folder=Build
    if [[ ! -d ${build_folder} ]]; then
        mkdir ${build_folder}
    fi
    cd $build_folder
    cmake .. -G "Unix Makefiles"
    cmake --build .
    print "You project are built in ./${build_folder}/out/"
fi

if [[ ${1} == "-h" ]]; then
    print "-h\tFor help"
    print "-i\tTo install the project"
    print "-c\tTo clear the repo"
    print "-b\tBuild your project"
fi

