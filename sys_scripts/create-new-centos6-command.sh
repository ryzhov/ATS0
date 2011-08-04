#!/bin/sh

sudo virt-install --name=ctom --ram=1356 --vcpus=2 --os-type=linux --disk path=/dev/mapper/dat-demo2 --network=bridge:xenbr0 --vnc --location=http://192.168.0.1/centos-iso/ --extra-args="ramdisk_size=9216 ksdevice=eth0 ks=ftp://192.168.0.1/co64-vm.cfg" --force
