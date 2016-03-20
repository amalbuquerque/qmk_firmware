To compile with ChibiOS to have media keys
==========================================

Following instructions on lejboua/qmk_firmware/keyboard/infinity_chibios/MEMO.txt I was able to compile the layout on lejboua/qmk_firmware/keyboard/infinity_chibios/keymap_lejboua.c

To use advanced features found on jackhumbert qmk_firmware like MACRODOWN and such, I had to update the following files on the repo I cloned from flabbergast:

vagrant@vagrant-ubuntu-trusty-64:/vagrant/qmk_firmware$ cd ~/infinity_layouts/flabbergast_tmk/
vagrant@vagrant-ubuntu-trusty-64:~/infinity_layouts/flabbergast_tmk$ cd tmk_keyboard/
vagrant@vagrant-ubuntu-trusty-64:~/infinity_layouts/flabbergast_tmk/tmk_keyboard$ git status
On branch chibios
Your branch is up-to-date with 'origin/chibios'.

Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

        modified:   .gitmodules
        new file:   tmk_core/tool/chibios/chibios

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)

        modified:   keyboard/infinity_chibios/Makefile
        modified:   keyboard/infinity_chibios/config.h
        modified:   keyboard/infinity_chibios/keymap_common.h

Untracked files:
  (use "git add <file>..." to include in what will be committed)

        keyboard/infinity_chibios/Makefileold
        keyboard/infinity_chibios/keymap_lejboua.c

