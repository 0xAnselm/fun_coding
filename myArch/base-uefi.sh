#!/bin/bash

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

pacman -S networkmanager dialog iwd reflector base-devel linux-headers avahi dnsutils openssh acpi acpi_call tlp terminus-font zsh zsh-theme-powerlevel10k-git

systemctl enable sshd
systemctl enable avahi-daemon
systemctl enable tlp # Just for install on laptop
systemctl enable reflector.timer
systemctl enable fstrim.timer

useradd -m r
passwd r

echo "r ALL=(ALL) ALL" >> /etc/sudoers.d/r
echo "Think about oh-my-zsh-git and chsh -s /usr/bin/zsh"
# git clone https://github.com/zsh-users/zsh-syntax-highlighting.git ~/.oh-my-zsh/custom/plugins/zsh-syntax-highlighting
# git clone https://github.com/zsh-users/zsh-autosuggestions ~/.oh-my-zsh/custom/plugins/zsh-autosuggestions
printf "\e[1;32mDone! Type exit, umount -a and reboot.\e[0m"
# chmod +x base-uefi.sh

# ZSH Links
# https://github.com/zsh-users/zsh-syntax-highlighting/blob/master/INSTALL.md
# https://github.com/zsh-users/zsh-autosuggestions/blob/master/INSTALL.md
# https://github.com/zsh-users/zsh-completions/blob/master/README.md

