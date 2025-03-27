<!-- *********************************************************************** -->
<!--                                                                         -->
<!--                                                      :::      ::::::::  -->
<!-- README.md                                          :+:      :+:    :+:  -->
<!--                                                  +:+ +:+         +:+    -->
<!-- By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+       -->
<!--                                              +#+#+#+#+#+   +#+          -->
<!-- Created: 2025/03/27 13:11:12 by lupelleg          #+#    #+#            -->
<!-- Updated: 2025/03/27 13:53:18 by lupelleg         ###   ########.fr      -->
<!--                                                                         -->
<!-- *********************************************************************** -->

# Born2beroot

## Overall Notes

Why Debian? Easy to use, easy to install and configure, clean, stable and widdelly 
used. Has good documentation and option to install with no unnecessary software.
It also uses apt which is a good package manager used in command line although
aptitude might have better dependency resolution. AppArmor is default in Debian
and it is a good security path-based MAC feature that enforces access control
policy beyond standard UNIX. Systemd is also default in Debian and it is a good
init system that is widely used for boot process (managing units), starting and
stopping services, logging, time sync, resource control, etc. LVM is also default
in Debian (Logical Volume Manager) making it flexible for managing disk size,
resize partitions live, group multiple physical drives into one volume group,
create, extend, shrink logical volumes inside the group. UFW (Uncomplicated
Firewall) works with iptables (status / allow 4242 / TCP). Cron is used to run
tasks on schedule. wall sends message to all logged-in users. sudo config logs all 
sudo commands. SELinux defines access controls for the applications process and
files. User is an identity while process is a running task, usually as a user.
When running a command such as (ls) the shell finds the binary whithin the PATH 
and executes as process. The process is then assigned a PID (Process ID). A
Daemon is a process that runs in the background like sshd or cron.

## VM Configuration

### 1 - Virtual Machine

- Install VirtualBox (6.1.42)
- Download Debian .iso (12.10.0 | amd64 | netinst)
- Make sure to work on goinfre directory
- Create a new VM (4GB RAM | 2 CPUs | 20GB HDD)
- Installation: Guided - use entire disk and setup encrypted LVM
- Create srv and var-log logical volumes (using ext-4 and set respective mount)
- Finish installation and reboot

### 2 - Setting up SSH (remote access)

- Log in as root
- systemctl status ssh (check port)
- /etc/ssh/sshd_config (change port to 4242 + PermitRootLogin no)
- systemctl restart ssh
- Port forwarding on the VM
- Logout

### 3 - Remote Log In

- ssh lupelleg@localhost -p 2222
- switch to root su -

### 4 - Firewall Configuration

- apt install ufw
- ufw default deny incomming
- ufw default allow outgoing
- ufw allow 4242
- ufw enable
- ufw status

### 5 - Setting up sudo

- apt install sudo
- visudo (add user to sudo group)
-- secure_path=<default is as asked>
-- requiretty
-- badpass_message="Wrong password"
-- logfile = "/var/log/sudo/sudo.log"
-- log_input
-- log_output
-- iolog_dir = /var/log/sudo
-- passwd_tries = 3

### 6 - Groups

- groupadd user42
- usermod -aG user42, sudo lupelleg
- cat /etc/group

### 7 Password Policy

- /etc/login.defs
-- PASS_MAX_DAYS 30
-- PASS_MIN_DAYS 2
-- PASS_WARN_AGE 7
- chage -M 30 lupelleg
- chage -m 2 lupelleg
- chage -M 30 root
- chage -m 2 root
- apt install libpam-pwquality
- /etc/pam.d/common-password
-- password requisite pam_pwquality.so retry=3 minlen=10 ucredit=-1 lcredit=-1
dcredit=-1 difok=7 maxrepeat=3 reject_username enforce_for_root
- passwd lupelleg

### 8 - Monitoring

- apt install bc sysstat (math and system statistics)
- crontab -e
-- */10 * * * * bash /etc/cron.d/monitoring.sh

### 9 - Defence

- sudo adduser <username>
- sudo groupadd <groupname>
- sudo usermod -aG user42
- sudo vi /etc/hostname
- sudo vi /etc/hosts
- sudo reboot
