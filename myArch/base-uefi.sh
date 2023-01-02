#!/bin/bash

# chmod +x base-uefi.sh

ln -sf /usr/share/zoneinfo/Europe/Berlin /etc/localtime
hwclock --systohc
# Disable en_US and de_DE
locale-gen
echo "LANG=en_US.UTF-8" >> /etc/locale.conf
echo "KEYMAP=de_DE-latin1" >> /etc/vconsole.conf
echo "asus" >> /etc/hostname
echo "127.0.0.1 localhost" >> /etc/hosts
echo "::1       localhost" >> /etc/hosts
echo "127.0.1.1 asus.localdomain asus" >> /etc/hosts
passwd

<<<<<<< HEAD
pacman -S networkmanager dialog iwd reflector base-devel linux-headers avahi dnsutils openssh acpi acpi_call tlp terminus-font zsh zsh-theme-powerlevel10k-git
=======
pacman -S --needed git base-devel
git clone https://aur.archlinux.org/yay.git ~/Downloads/yay
cd ~/Downloads/yay
makepkg -sri

yay -S networkmanager dialog iwd reflector base-devel linux-headers avahi dnsutils openssh acpi acpi_call tlp terminus-font zsh zsh-theme-powerlevel10k-git oh-my-zsh-git bluez bluez-utils gnome timeshift
>>>>>>> e88678db4f082e2b93c8084063fb1ed07be27760

systemctl enable sshd
systemctl enable avahi-daemon
systemctl enable tlp # Just for install on laptop
systemctl enable reflector.timer
systemctl enable fstrim.timer
systmectl enable bluetooth.service
systemctl enable cronie.service

useradd -m r
passwd r

echo "r ALL=(ALL) ALL" >> /etc/sudoers.d/r
<<<<<<< HEAD
echo "Think about oh-my-zsh-git and chsh -s /usr/bin/zsh"
# git clone https://github.com/zsh-users/zsh-syntax-highlighting.git ~/.oh-my-zsh/custom/plugins/zsh-syntax-highlighting
# git clone https://github.com/zsh-users/zsh-autosuggestions ~/.oh-my-zsh/custom/plugins/zsh-autosuggestions
=======
chsh -s /usr/bin/zsh
git clone https://github.com/zsh-users/zsh-syntax-highlighting.git ~/.oh-my-zsh/custom/plugins/zsh-syntax-highlighting
git clone https://github.com/zsh-users/zsh-autosuggestions.git ~/.oh-my-zsh/custom/plugins/zsh-autosuggestions
git clone https://github.com/zsh-users/zsh-completions.git ~/.oh-my-zsh/custom/plugins/zsh-completions
journalctl --vacuum-time=1d

>>>>>>> e88678db4f082e2b93c8084063fb1ed07be27760
printf "\e[1;32mDone! Type exit, umount -a and reboot.\e[0m"

# cat /boot/loader/entries/arch.conf  
# title	Arch Linux
# linux	/vmlinuz-linux
# initrd	/amd-ucode.img
# initrd	/initramfs-linux.img
# options	root=LABEL=arch quiet systemd.show_status=0 systemd.restore_state=0 rootflags=subvol=@ rw

# cat /etc/mkinitcpio.conf 
# vim:set ft=sh
# MODULES
# The following modules are loaded before any boot hooks are
# run.  Advanced users may wish to specify all system modules
# in this array.  For instance:
#     MODULES=(piix ide_disk reiserfs)
# MODULES=(amdgpu btrfs)

# cat /boot/loader/loader.conf
# timeout 0
# console-mode max
# editor no
# default arch.conf


# ZSH Links
# https://github.com/zsh-users/zsh-syntax-highlighting/blob/master/INSTALL.md
# https://github.com/zsh-users/zsh-autosuggestions/blob/master/INSTALL.md
# https://github.com/zsh-users/zsh-completions/blob/master/README.md



