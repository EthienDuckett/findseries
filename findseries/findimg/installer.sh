#!/bin/bash
echo "read README.txt choices are uninstall/install"
read OP
CHANGEBIN=/usr/bin
WD=$(locate /findseries/findimg | head -1)
if [[ $OP = "install" ]]
then
    sudo ln -s $WD/downimg.sh $CHANGEBIN/findimg
    chmod 744 $CHANGEBIN/findimg
    # I still have no idea how to make those weird executables
fi
if [[ $OP = "uninstall" ]]
then
    sudo rm $CHANGEBIN/findimg
    sudo rm -R $WD
fi
