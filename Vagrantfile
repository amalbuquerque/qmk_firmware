# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant.configure(2) do |config|
  # define a name instead of just 'default'
  config.vm.define "qmk_firmware"

  # VMware/Virtualbox ( and also Hyperv/Parallels) 64 bit
  config.vm.box = "generic/debian9"
  
  config.vm.synced_folder '.', '/vagrant'

  # This section allows you to customize the Virtualbox VM
  # settings, ie showing the GUI or upping the memory
  # or cores if desired
  config.vm.provider "virtualbox" do |vb|
    # Hide the VirtualBox GUI when booting the machine
    vb.gui = false
    # Uncomment the below lines if you want to program
    # your Teensy via the VM rather than your host OS
    vb.customize ['modifyvm', :id, '--usb', 'on']
    vb.customize ['usbfilter', 'add', '0',
        	  '--target', :id,
        	  '--name', 'promicro',
        	  '--vendorid', '0x2341',
        	  '--productid','0x0036'
    		 ]
    vb.customize ['usbfilter', 'add', '1',
        	  '--target', :id,
        	  '--name', 'promicro',
        	  '--vendorid', '0x2341',
        	  '--productid','0x8036'
    		 ]
    vb.customize ['usbfilter', 'add', '2',
        	  '--target', :id,
        	  '--name', 'promicro',
        	  '--vendorid', '0xFEED',
        	  '--productid','0x6060'
    		 ]
    vb.customize ['usbfilter', 'add', '3',
        	  '--target', :id,
        	  '--name', 'promicro',
        	  '--vendorid', '0x16C0',
        	  '--productid','0x0487'
    		 ]
    vb.customize ['usbfilter', 'add', '4',
        	  '--target', :id,
        	  '--name', 'promicro',
        	  '--vendorid', '0x16C0',
        	  '--productid','0x0478'
    		 ]
    # Customize the amount of memory on the VM:
    vb.memory = "512"
    # Uncomment the below lines if you have time sync
    # issues with make and incremental builds
    #vb.customize [ "guestproperty", "set", :id, "/VirtualBox/GuestAdd/VBoxService/--timesync-set-threshold", 1000 ]
  end

# Bootloader mode, after shorting GND and RST twice, for *only* 8 secs
# (w/o loading any firmware yet)
# UUID:               fd823e5d-b774-4faa-b40c-9ea270557a21
# VendorId:           0x2341 (2341)
# ProductId:          0x0036 (0036)
# Revision:           0.1 (0001)
# Port:               0
# USB version/speed:  1/Full
# Manufacturer:       Arduino LLC
# Product:            Arduino Leonardo
# Address:            {4d36e978-e325-11ce-bfc1-08002be10318}\0003
# Current State:      Busy

# Normal Pro Micro mode (w/o loading any firmware yet)
# UUID:               f5b38e7a-6e0c-4d28-a423-0e1d981fdf5e
# VendorId:           0x2341 (2341)
# ProductId:          0x8036 (8036)
# Revision:           1.0 (0100)
# Port:               0
# USB version/speed:  2/High
# Manufacturer:       Arduino LLC
# Product:            Arduino Leonardo
# Address:            {36fc9e60-c465-11cf-8056-444553540000}\0007
# Current State:      Busy

# After loading my first firmware
# UUID:               00a96173-f4ee-4ed7-8b9d-d4906a5b0010
# VendorId:           0xfeed (FEED)
# ProductId:          0x6060 (6060)
# Revision:           0.1 (0001)
# Port:               0
# USB version/speed:  1/Full
# Manufacturer:       Lejboua
# Product:            macropad_2x5
# Address:            {36fc9e60-c465-11cf-8056-444553540000}\0010
# Current State:      Busy
  #
  # Normal Teensy (without Reset)
# UUID:               0497a188-f560-4c02-8d30-7c52e5255dae
# VendorId:           0x16c0 (16C0)
# ProductId:          0x0487 (0487)
# Revision:           1.2 (0102)
# Port:               0
# USB version/speed:  2/High
# Manufacturer:       Teensyduino
# Product:            Serial+Keyboard+Mouse+Joystick
# SerialNumber:       12345
# Address:            {36fc9e60-c465-11cf-8056-444553540000}\0014
# Current State:      Busy
#
  # Teensy inside bootloader (after pressing reset)
# UUID:               7bae14c2-3427-4d56-9124-9b0a5c5d6cf2
# VendorId:           0x16c0 (16C0)
# ProductId:          0x0478 (0478)
# Revision:           1.32 (0132)
# Port:               0
# USB version/speed:  1/Full
# Manufacturer:       Van Ooijen Technische Informatica
# Product:            Teensy Halfkay Bootloader
# Address:            {745a17a0-74d3-11d0-b6fe-00a0c90f57da}\0016
# Current State:      Busy

  # This section allows you to customize the VMware VM
  # settings, ie showing the GUI or upping the memory
  # or cores if desired
  config.vm.provider "vmware_workstation" do |vmw|
    # Hide the VMware GUI when booting the machine
    vmw.gui = false

    # Customize the amount of memory on the VM:
    vmw.memory = "512"
  end

  config.vm.provider "vmware_fusion" do |vmf|
    # Hide the vmfare GUI when booting the machine
    vmf.gui = false

    # Customize the amount of memory on the VM:
    vmf.memory = "512"
  end

  # Docker provider pulls from hub.docker.com respecting docker.image if
  # config.vm.box is nil. Note that this bind-mounts from the current dir to
  # /vagrant in the guest, so unless your UID is 1000 to match vagrant in the
  # image, you'll need to: chmod -R a+rw .
  config.vm.provider "docker" do |docker, override|
    override.vm.box = nil
    docker.image = "jesselang/debian-vagrant:stretch"
    docker.has_ssh = true
  end

  # This script ensures the required packages for AVR programming are installed
  # It also ensures the system always gets the latest updates when powered on
  # If this causes issues you can run a 'vagrant destroy' and then
  # add a # before ,run: (or change "always" to "once") and run 'vagrant up' to get a working
  # non-updated box and then attempt to troubleshoot or open a Github issue
  config.vm.provision "shell", inline: "/vagrant/util/qmk_install.sh", run: "always"

  config.vm.post_up_message = <<-EOT

  Log into the VM using 'vagrant ssh'. QMK directory synchronized with host is
  located at /vagrant
  To compile the .hex files use make command inside this directory, e.g.
     cd /vagrant
     make <keyboard>:default

  Examples:
     make planck/rev4:default:dfu
     make planck:default

  EOT
end
