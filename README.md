# Swap
[**Reference**](https://access.redhat.com/documentation/en-US/Red_Hat_Enterprise_Linux/3/html/System_Administration_Guide/s1-swap-adding.html)

### Usage
**swapon -s** # display summary about used swap devices
+ Create Swap Partition
```
  mkswap /dev/sdb3
  swapon /dev/sdb3
```
+ Create Swap File
```
  dd if=/dev/zero of=/swapfile bs=1024 count=65536
  mkswap /swapfile
  swapon /swapfile
```

+ Create Loop Device For Swapfile<p> 
[**Reference**](http://www.spinics.net/lists/linux-btrfs/msg28533.html)

```
  swapfile=$(losetup -f)   # get free loop device
  truncate -s 8G /swap     # create 8G sparse swap file 
  losetup $swapfile /swap  # mount file to loop
  mkswap  $swapfile
  swapon  $swapfile
```
